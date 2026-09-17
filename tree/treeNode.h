
template <typename T = int>
struct TreeNode
{
    unsigned int freq;
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : freq(0), left(nullptr), right(nullptr) {};
    TreeNode(unsigned int freq, T data) : freq(freq), data(data), left(nullptr), right(nullptr) {};
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