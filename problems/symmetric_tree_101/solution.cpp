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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isSymmetricTwo(root->left,root->right);
        
    }
    bool isSymmetricTwo(TreeNode* a,TreeNode* b){
        if((a == NULL ) && (b == NULL)){
            return true;
        }
        if(a == NULL || b == NULL){
            return false;
        }
        return (a->val == b->val) && isSymmetricTwo(a->left,b->right)&&isSymmetricTwo(a->right,b->left);
    }
};