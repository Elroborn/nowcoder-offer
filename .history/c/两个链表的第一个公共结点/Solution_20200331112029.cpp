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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* head = pHead1;
        int l1 = 0,l2 = 0;
        while(head!=NULL){
            l1+=1;
            head = head->next;
        }
        head = pHead2;
        while(head!=NULL){
            l2+=1;
            head = head->next;
        }
        
    }
};