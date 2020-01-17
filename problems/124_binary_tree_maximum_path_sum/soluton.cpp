#include<algorithm>
#include<iostream>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
   int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        int val = maxPath(root,pathSum);
        return max(pathSum,val);
    }
    int maxPath(TreeNode* root,int& pathSum){
        if(root == nullptr){
            return 0;
        }
        int left = maxPath(root->left,pathSum);
        int right = maxPath(root->right,pathSum);
        int internalVal = max(left,right)+root->val;
        pathSum = max(pathSum,max(left+right+root->val,internalVal));
        return max(internalVal,root->val);
        
    }
};