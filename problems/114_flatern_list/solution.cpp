
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
       TreeNode* head = root;
       //将右子树挂在最子树最右的叶子节点
        while(head->left || head->right){
            if(head->left){
                TreeNode* t = head->left;
                while(t->right){
                    t = t->right ;
                }
                t->right = head->right;
                head->right = head->left;
                head->left = nullptr;
            }
            head = head->right ;
        }

    }
};