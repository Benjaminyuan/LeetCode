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
};