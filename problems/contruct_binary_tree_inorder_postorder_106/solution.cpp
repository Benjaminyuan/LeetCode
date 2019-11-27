#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeTwo(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* buildTreeTwo(vector<int>& inorder,vector<int>& postorder,int i,int j,int x,int y){
        if(i>j){
            return nullptr;
        }
        if(i==j){
            return new TreeNode(inorder[i]);
        }
        TreeNode* head = new TreeNode(postorder[y]);
        int cur = 0;
        for(int pos=i;pos<=j;pos++){
            if(inorder[pos] == head->val){
                cur = pos;
                break;
            }
        }
        TreeNode* left = buildTreeTwo(inorder,postorder,i,cur-1,x,x+cur-i-1);
        TreeNode* right = buildTreeTwo(inorder,postorder,cur+1,j,x+cur-i,y-1);
        head->left = left;
        head->right = right;
        return head;
    }
};