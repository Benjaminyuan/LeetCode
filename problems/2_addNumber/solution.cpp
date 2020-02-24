using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int overflow = 0;
        ListNode* tail;
        while(cur1 != nullptr && cur2!= nullptr){
            int sum  = cur1->val+cur2->val+overflow;
            overflow =  sum/10;
            cur1->val = sum%10;
            tail = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;    
        }
        if(cur1 == nullptr){
            while(cur2 != nullptr){
                int sum  = cur2->val+overflow;
                overflow =  sum/10;
                cur2->val = sum%10;
                tail->next = cur2;
                tail = cur2;
                cur2 = cur2->next;
            }
        }else if(cur2 == nullptr){
              while(cur1 != nullptr){
                int sum  = cur1->val+overflow;
                overflow =  sum/10;
                cur1->val = sum%10;
                tail = cur1;
                cur1 = cur1->next;
            }
        }
        if(overflow != 0){
            tail->next = new ListNode(overflow);
            tail->next->next = nullptr;
        }
        return l1;
    }
};