#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTreeTwo(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *buildTreeTwo(vector<int> &preorder, vector<int> &inorder, int i, int j, int x, int y)
    {
        if (i > j || x > y)
        {
            return nullptr;
        }
        if (i == j)
        {
            return new TreeNode(preorder[i]);
        }
        TreeNode *head = new TreeNode(preorder[i]);
        int inter;
        for (int cur = x; cur <= y; cur++)
        {
            if (inorder[cur] == head->val)
            {
                inter = cur;
                break;
            }
        }
        TreeNode *left = buildTreeTwo(preorder, inorder, i + 1, i + inter - x, x, inter - 1);
        TreeNode *right = buildTreeTwo(preorder, inorder, i + inter - x + 1, j, inter + 1, y);
        head->left = left;
        head->right = right;
        return head;
    }
};