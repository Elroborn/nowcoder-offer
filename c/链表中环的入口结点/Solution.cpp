#include<iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast = pHead;
        ListNode* low = pHead;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            low = low->next;
            if(fast==low){
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr){
            return NULL;
        }
        low = pHead;
        while(fast!=low){
            fast = fast->next;
            low = low->next;
        }
        return fast;
    }
};

int main(){
      ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    head->next = node1;
    ListNode* rear = new ListNode(3);
    node1->next = rear;
    rear->next = node1;
    cout<<Solution().EntryNodeOfLoop(head)->val;
    return 0;
}