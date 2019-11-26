#include <stack>
#include <vector>
using namespace std;
//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
    1.将当前递归的最大值和最小值传入，违反二叉树性质 ->return false;
*/
class Solution
{
public:
    bool isValidBST(TreeNode *root, TreeNode *min = nullptr, TreeNode *max = nullptr)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (min && root->val <= min->val)
        {
            return false;
        }
        if (max && root->val >= max->val)
        {
            return false;
        }

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};