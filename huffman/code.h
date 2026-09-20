#include "../heap/heap.h"
#include "../tree/treeNode.h"
#include <cstdint>
#include <cmath>
#include <utility>
#include <algorithm>

using std::pair;
using TreeNode_t = TreeNode<uint8_t>;
using Heap_t = Heap<TreeNode_t *, compareTreenode<uint8_t>>;

struct Code
{

    uint64_t bits;
    uint16_t length;
};

struct
    CompressedData
{
    vector<uint8_t> compressed;
    vector<uint8_t> serializedTree;
    size_t originalDataSize;
};

class Huffman
{
    /*function which calculates the frequence of the each byte data from (0,255)*/
    static void calFreq(const vector<uint8_t> &data, uint64_t *freq)
    {
        for (const uint8_t &chunk : data)
        {
            freq[chunk]++;
        }
    }

    /*this function builds the Huffman Tree using minHeap and binary tree
    and returns root node of tree.*/
    static TreeNode_t *buildTree(uint64_t *freq)
    {
        // push all the data treeNode whoes freq > 0 in heap
        Heap_t heap;
        for (int i = 0; i <= UINT8_MAX; i++)
        {
            if (freq[i] > 0)
            {
                heap.push(new TreeNode_t(freq[i], i));
            }
        }

        // take 2 minimum frequence node each time and combine them and again push in heap
        while (heap.size() > 1)
        {
            TreeNode_t *left = heap.pop();
            TreeNode_t *right = heap.pop();

            TreeNode_t *parent = new TreeNode_t(left->freq + right->freq, uint8_t{}, left, right);
            heap.push(parent);
        }

        // check if data is null
        if (heap.isEmpty())
            return nullptr;

        // returns the root node of Huffman tree.
        return heap.pop();
    }

    /*build table [data -> (path_bits,valid,bitLen)] (0 for L & 1 for R)*/
    static void buildCodeTable(TreeNode_t *root, uint64_t key, uint16_t len, uint64_t *freq, Code *map, size_t &consumedBits)
    {
        if (root == nullptr)
            return;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            uint16_t codeLen = (len == 0) ? static_cast<uint16_t>(1) : len; // len==0 only when root itself is the lone leaf
            map[root->data] = {key, codeLen};
            consumedBits += codeLen * freq[root->data];
        }

        buildCodeTable(root->left, key << 1, len + 1, freq, map, consumedBits);
        buildCodeTable(root->right, (key << 1) | 1, len + 1, freq, map, consumedBits);
    }

    /*save compressed data sequence wise from map table */
    static void saveCompressedData(const vector<uint8_t> &data, Code *map, vector<uint8_t> &compressed)
    {
        int8_t i = 7;
        uint8_t cbyte = 0;

        for (const uint8_t &key : data)
        {
            const auto &[bits, length] = map[key];
            uint16_t len = length;

            while (len > 0)
            {

                cbyte |= ((bits >> (len - 1)) & 1) << i;

                i--;
                len--;

                if (i < 0)
                {
                    compressed.push_back(cbyte);
                    cbyte = 0;
                    i = 7;
                }
            }
        }

        // Store remaining partial byte
        if (i != 7)
        {
            compressed.push_back(cbyte);
        }
    }

    /*Serialize the tree in binary form*/
    static pair<uint8_t, uint8_t> serializeTree(TreeNode_t *root, uint8_t byte, uint8_t bitPos, vector<uint8_t> &serializedTree)
    {
        if (root == nullptr)
            return {byte, bitPos};

        // byte limit exceeded
        // save current byte in serialized
        if (bitPos > 7)
        {
            serializedTree.push_back(byte);
            byte = 0;
            bitPos = 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            byte |= (1 << (7 - bitPos));
            return serializeHelper({byte, bitPos + 1}, root->data, serializedTree);
        }

        auto left = serializeTree(root->left, byte, bitPos + 1, serializedTree);
        return serializeTree(root->right, left.first, left.second, serializedTree);
    }

    static pair<uint8_t, uint8_t> serializeHelper(pair<uint8_t, uint8_t> curr, uint8_t data, vector<uint8_t> &serializedTree)
    {
        auto [byte, bitPos] = curr;
        byte |= data >> bitPos;
        serializedTree.push_back(byte);
        byte = 0;
        byte |= data << (8 - bitPos);

        return {byte, bitPos};
    }

    /*de-Serialize the tree from binary to actual tree*/
    static TreeNode_t *deserializeTree(vector<uint8_t> &serializedTree, uint8_t &bitPos)
    {
        // CHECK
        if (serializedTree.empty())
            return nullptr;

        // byte limit exceeded
        // pop the current used byte from serialized
        if (bitPos > 7)
        {
            bitPos = 0;
            serializedTree.pop_back();

            // CHECK
            if (serializedTree.empty())
                return nullptr;
        }

        if ((serializedTree.back() & (1 << (7 - bitPos))) != 0)
        {
            bitPos++;

            // byte limit exceeded
            if (bitPos > 7)
            {
                bitPos = 0;
                serializedTree.pop_back();
            }

            return deserializeHelper(serializedTree, bitPos);
        }

        TreeNode_t *root = new TreeNode_t(0, 0);
        bitPos++;

        root->left = deserializeTree(serializedTree, bitPos);
        root->right = deserializeTree(serializedTree, bitPos);

        return root;
    }

    static TreeNode_t *deserializeHelper(vector<uint8_t> &serializedTree, uint8_t &bitPos)
    {
        if (serializedTree.empty())
            return nullptr;

        uint8_t data = 0;
        data |= serializedTree.back() << bitPos;
        serializedTree.pop_back();

        if (serializedTree.empty())
            return new TreeNode_t(0, data);

        data |= serializedTree.back() >> (8 - bitPos);

        if (8 - bitPos < 8 && serializedTree.size() == 1)
            serializedTree.pop_back();

        return new TreeNode_t(0, data);
    }

    static void generateOriginal(TreeNode_t *root, vector<uint8_t> &compressedData, vector<uint8_t> &dataContainer, const size_t &originalDataSize)
    {
        if (compressedData.empty() || root == nullptr)
            return;

        dataContainer.reserve(originalDataSize);

        int8_t i = 7;
        TreeNode_t *node = root;

        while (dataContainer.size() < originalDataSize)
        {
            if (i < 0)
            {
                compressedData.pop_back();
                if (compressedData.empty())
                    break;
                i = 7;
            }

            if (node->left == nullptr && node->right == nullptr)
            {
                dataContainer.push_back(node->data);
                node = root;
                continue;
            }

            uint8_t curr = compressedData.back();
            node = ((curr & (1 << i)) == 0) ? node->left : node->right;
            i--;
        }
    }

public:
    // public constructor for getting original data and make its freq
    Huffman()
    {
    }
    ~Huffman() {}

    static CompressedData compress(const vector<uint8_t> data)
    {
        uint64_t freq[UINT8_MAX + 1]{}; // frequence of each byte saved in this
        Code map[UINT8_MAX + 1]{};      // path table of tree saved in this
        size_t consumedBits = 0;        // used for calulate reservation of sloat of byte in vector
        vector<uint8_t> compressed;     // compressed data saved in this
        vector<uint8_t> serializedTree; // serlized tree saved in this

        calFreq(data, freq);
        TreeNode_t *tree = buildTree(freq);
        buildCodeTable(tree, 0, 0, freq, map, consumedBits);

        compressed.reserve((consumedBits + 7) / 8);
        saveCompressedData(data, map, compressed);

        auto [byte, bitPos] = serializeTree(tree, 0, 0, serializedTree);

        if (bitPos > 0)
        {
            serializedTree.push_back(byte);
        }

        // release tree
        delete tree;

        return {
            compressed,
            serializedTree,
            data.size(),
        };
    }

    static vector<uint8_t> decompress(vector<uint8_t> compressed, vector<uint8_t> serializedTree, const size_t originalDataSize)
    {
        std::reverse(serializedTree.begin(), serializedTree.end());
        std::reverse(compressed.begin(), compressed.end());

        uint8_t bitPos = 0;
        TreeNode_t *tree = deserializeTree(serializedTree, bitPos);
        vector<uint8_t> decompressed;
        generateOriginal(tree, compressed, decompressed, originalDataSize);
        delete tree;

        return decompressed;
    }
};