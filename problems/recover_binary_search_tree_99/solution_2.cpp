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
class Solution {
private:
    TreeNode *node1 = nullptr;
    TreeNode *node2 = nullptr;
    bool found = false;
public:
    void recoverTree(TreeNode* root){
        findBugNodes(root,nullptr);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
private:
    TreeNode* findBugNodes(TreeNode* node,TreeNode* prev){
        if(node == nullptr || found){
            return prev;
        }
        prev = findBugNodes(node->left,prev);
        // 违反顺序规则
        if(prev != nullptr && node->val < prev->val){
            if(node1 == nullptr){
                node1 = prev;
            }else{
                found = true;
            }
            node2 = node;
        }
        return findBugNodes(node->right,node);
    }
};