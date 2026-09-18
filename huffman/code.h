#include "../heap/heap.h"
#include "../tree/treeNode.h"
#include <cstdint>
#include <bitset>
#include <unordered_map>
#include <cmath>

using std::unordered_map;
using treeNode_t = TreeNode<uint8_t>;
using heap_t = Heap<treeNode_t *, compareTreenode<uint8_t>>;

struct Code
{

    uint64_t bits;
    uint16_t length;
};

class Huffman
{
    vector<uint8_t> originalData;
    vector<uint8_t> compressedData;
    uint64_t freq[UINT8_MAX + 1];
    uint16_t max_height;
    treeNode_t *tree;
    unordered_map<uint8_t, Code> map;
    size_t compressedBits;

    void compress()
    {
        calFreq();
        tree = buildTree();
        max_height = buildCodeTableAndGetHeight(tree, 0, 0);
        saveCompressedData();
    }

    void calFreq()
    {
        for (uint8_t &chunk : originalData)
        {
            freq[chunk]++;
        }
    }

    treeNode_t *buildTree()
    {
        heap_t heap;
        for (int i = 0; i <= UINT8_MAX; i++)
        {
            if (freq[i] > 0)
            {
                heap.push(new treeNode_t(freq[i], i));
            }
        }

        while (heap.size() > 1)
        {
            treeNode_t *left = heap.pop();
            treeNode_t *right = heap.pop();

            treeNode_t *parent = new treeNode_t(left->freq + right->freq, uint8_t{}, left, right);
            heap.push(parent);
        }

        return heap.pop();
    }

    uint16_t buildCodeTableAndGetHeight(treeNode_t *root, uint64_t key, uint16_t len)
    {
        if (root == nullptr)
            return 0;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            map[root->data] = {key, len};
            compressedBits += len * freq[root->data];
            return 1;
        }

        return std::max(buildCodeTableAndGetHeight(root->left, key << 1, len + 1),
                        buildCodeTableAndGetHeight(root->right, (key << 1) | 1, len + 1)) +
               1;
    }

    void saveCompressedData()
    {
        int8_t i = 7;
        uint8_t cbyte = 0;

        for (const uint8_t &key : originalData)
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
                    compressedData.push_back(cbyte);
                    cbyte = 0;
                    i = 7;
                }
            }
        }

        // Store remaining partial byte
        if (i != 7)
        {
            compressedData.push_back(cbyte);
        }
    }

    uint64_t sizeofTreeHelper(treeNode_t *root)
        const
    {
        if (root == nullptr)
            return 0;

        uint64_t curr = sizeof(*root);
        return curr + sizeofTreeHelper(root->left) + sizeofTreeHelper(root->right);
    }

public:
    // public constructor for getting original data and make its freq
    Huffman(vector<uint8_t> &data) : originalData(data), compressedData(), freq{}, tree(nullptr), max_height{}, map(), compressedBits{}
    {
        compress();
    }

    ~Huffman() { delete tree; }

    uint64_t sizeofTree()
        const
    {
        return sizeofTreeHelper(tree);
    }

    uint16_t heightOfTree() const
    {
        return max_height;
    }

    size_t getCompressedBits() const
    {
        return compressedBits;
    }

    const vector<uint8_t> &getCompressedData()
    {
        return compressedData;
    }
};