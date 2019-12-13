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
private:
    vector<vector<int> > result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> s;
        pathSum2(root,sum,s);
        return result;
    }
    void pathSum2(TreeNode* root,int sum,vector<int> & temp){
        if(root == nullptr){
            return ;
        }
        if(root->val == sum && root->left == nullptr && root->right == nullptr){
            temp.push_back(root->val);
            vector<int> res(temp);
            result.push_back(res);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        pathSum2(root->left,sum-root->val,temp);
        pathSum2(root->right,sum-root->val,temp);
        temp.pop_back();
        return ;
    }
};