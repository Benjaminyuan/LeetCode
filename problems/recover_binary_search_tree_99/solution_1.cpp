#include<stack>
#include <vector>
using namespace std;
//  * Definition for a binary tree node.
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> s;
        vector<TreeNode *> res;
        TreeNode *cur = root;
        while (cur != nullptr || !s.empty())
        {
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur);
            cur = cur->right;
        }
        int reve_1;
        for (int i = res.size() - 1; i >= 1; i--)
        {
            if (res[i]->val < res[i - 1]->val)
            {
                reve_1 = i;
                break;
            }
        }
        int reve_2;
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i]->val > res[i + 1]->val)
            {
                reve_2 = i;
                break;
            }
        }
        // cout<<"reve_1:"<<res[reve_1]->val << "reve_2:"<< res[reve_2]->val<<std::endl;
        int temp = res[reve_1]->val;
        res[reve_1]->val = res[reve_2]->val;
        res[reve_2]->val = temp;
    }
};