#include<stack>
#include <vector>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 1;
        int next_level = 0;
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            vector<int> temp;
            while(level>0){
                level--;
                TreeNode* t = st.front();
                st.pop();
                temp.push_back(t->val);
                if(t->left != nullptr){
                    st.push(t->left);
                    next_level++;
                }
                 if(t->right != nullptr){
                    st.push(t->right);
                    next_level++;
                }
            }
            res.push_back(temp);
            level = next_level;
            next_level = 0;
        }
        return res;
    }
};