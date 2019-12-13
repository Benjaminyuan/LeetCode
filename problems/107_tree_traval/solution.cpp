#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int nextLevel=0;
        while(!q.empty()){
            vector<int> temp;
            while(level > 0){
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left != nullptr){
                    q.push(cur->left);
                    nextLevel++;
                } 
                if(cur->right != nullptr){
                    q.push(cur->right);
                    nextLevel++;
                }
                level--;
            }
            res.push_back(temp);
            level = nextLevel;
            nextLevel = 0;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};