#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr ){
            return head;
        }
        ListNode* cur = head;
        ListNode* tail = nullptr;
        ListNode* res = head;
        int j = 1 ;
        ListNode* tempH = head;
        while(j< k && tempH != nullptr  ){
            tempH = tempH->next;
            j++;
        }
        if(j == k){
            res = tempH;
        }
        ListNode*  pHead = nullptr;
        while(cur != nullptr){
            int times = 1;
            ListNode* tempCur = cur;
            while(tempCur != nullptr &&times < k){
                tempCur = tempCur->next;
                times++;
            }
            if(times != k){
                pHead->next = cur;
                break;
            }
            int tempK = k-1;
            ListNode* nextPHead = cur;
            while(tempK > 0 && cur != nullptr){
                ListNode* temp = cur->next;
                cur->next = tail;
                tail = cur;
                cur = temp;
                tempK--;
            }
            if(pHead != nullptr){
                pHead->next = tail;
                pHead = nextPHead;   
            }else{
                pHead = head;
            }
            tail = nullptr;
            
        }
        return res;
    }
};
int main(){
    Solution s;
    ListNode head(1);
    ListNode* cur = &head ;
    for(int i=2;i<6;i++){
        cur->next = &ListNode(i);
        cur = cur->next;
    }
    cur = &head;
    while (cur != nullptr)
    {
        cout<< cur->val;
    }
}