#include <cstdint>

struct TreeNode
{
    int32_t val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0),left(nullptr),right(nullptr){};
    TreeNode(int64_t val) :val(val),left(nullptr),right(nullptr){};
};
