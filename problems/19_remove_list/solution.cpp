using namespace std;
struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;
        while(fast->next != nullptr){
            if(i == n){
                break;
            }
            fast = fast->next ;
            i++;
        }
        if(i != n){
            return head->next;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 设置哨兵可以排除头节点的情况
        ListNode flag(0);
        flag.next = head;
        ListNode* fast = &flag;
        ListNode* slow = &flag;
        int i = 0;
        while(fast->next != nullptr && i < n){
            fast = fast->next ;
            i++;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return flag.next;
    }
};
