#include<stack>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertTree(nums,0,nums.size()-1);
    }
    TreeNode* convertTree(vector<int>& nums,int i,int j){
        if(i > j){
            return nullptr;
        }
        if(i == j){
            return new TreeNode(nums[i]);
        }
        int pos = (i+j) >> 1;
        TreeNode* head = new TreeNode(nums[pos]);
        TreeNode* left = convertTree(nums,i,pos-1);
        TreeNode* right = convertTree(nums,pos+1,j);
        head->left = left;
        head->right = right;
        return head;
    }
};