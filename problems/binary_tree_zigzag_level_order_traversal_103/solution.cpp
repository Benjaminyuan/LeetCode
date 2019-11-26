#include <stack>
#include <vector>
#include <queue>
#include<deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int level = 1;
        int next_level = 0;
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode *> st;
        st.push(root);
        bool flag = true;
        while (!st.empty())
        {
            deque<int> temp;
            while (level > 0)
            {
                level--;
                TreeNode *t = st.front();
                st.pop();
                if (flag)
                {
                    temp.push_back(t->val);
                }
                else
                {
                    temp.push_front(t->val);
                }
                if (t->left != nullptr)
                {
                    st.push(t->left);
                    next_level++;
                }
                if (t->right != nullptr)
                {
                    st.push(t->right);
                    next_level++;
                }
            }
            flag = !flag;
            vector<int> temp_v;
            for (auto iter = temp.begin(); iter != temp.end(); iter++)
            {
                temp_v.push_back(*iter);
            }
            res.push_back(temp_v);
            level = next_level;
            next_level = 0;
        }
        return res;
    }
};