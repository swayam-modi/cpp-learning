#include <cstdint>
template <typename T = int>
struct TreeNode
{
    uint64_t freq;
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode() : freq(0), data(T{}), left(nullptr), right(nullptr) {};
    TreeNode(uint64_t freq, T data) : freq(freq), data(data), left(nullptr), right(nullptr) {};
    TreeNode(uint64_t freq, T data, TreeNode<T> *l, TreeNode<T> *r) : freq(freq), data(data), left(l), right(r) {};
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T = int>
struct compareTreenode
{
    bool operator()(
        const TreeNode<T> *a,
        const TreeNode<T> *b) const
    {
        return a->freq < b->freq;
    }
};