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
    1.二叉搜索树按顺序读出来就是一个递增的数组，违反这一点的就是非法的二叉搜索树
*/
class Solution {
public:
    bool isValidBST(TreeNode* root,TreeNode* min = nullptr,TreeNode* max = nullptr) {
       if( root == nullptr){
           return true;
       }
       stack<TreeNode*> s ;
       TreeNode* cur = root;
       vector<int> res ;
       while(cur != nullptr || !s.empty()){
           while(cur != nullptr){
               s.push(cur);
               cur = cur->left;
           }
           cur = s.top();
           s.pop();
           res.push_back(cur->val);
           cur = cur->right;
       }
       if(res.size() <=1){
           return true;
       }
       for(int i = 1;i< res.size();i++){
           if(res[i]<=res[i-1]){
               return false;
           }
       }
       return true;
    }
};