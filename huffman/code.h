#include "heap/heap.h";
#include "tree/treeNode.h"
#include <cstdint>

using treeNode_t = TreeNode<uint8_t>;
using heap_t = Heap<treeNode_t *, compareTreenode<uint8_t>>;

class Huffman
{
    vector<uint8_t> originalData;
    vector<uint64_t> freq;
    heap_t heap;
    treeNode_t *root;

public:
    // public constructor for getting original data and make its freq
    Huffman(vector<uint8_t> &data) : originalData(data), freq(UINT8_MAX + 1, 0), heap(), root(nullptr)
    {
        for (uint8_t &chunk : originalData)
        {
            freq[chunk]++;
        }

        compress();
    }

private:
    void compress()
    {
        vector<treeNode_t *> nodes(UINT8_MAX + 1);

        for (int i = 0; i <= UINT8_MAX; i++)
        {
            if (freq[i] > 0)
            {
                nodes[i] = new treeNode_t(freq[i], i);
            }
        }

        heap.
    }
};