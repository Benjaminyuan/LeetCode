

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

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return new TreeNode(head->val);
        }
        auto fast = head;
        auto slow = head;
        auto pre = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        auto h = new TreeNode(slow->val);
        h->left = sortedListToBST(head);
        h->right = sortedListToBST(slow->next);
        return h;
    }
};
