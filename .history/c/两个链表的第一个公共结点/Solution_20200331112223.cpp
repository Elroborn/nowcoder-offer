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
        //保证第二个是较长，方便后面处理
        if(l1>l2){
            int t = l1;
            l1 = l2;
            l2 = t;
            head = pHead1;
            pHead1 = pHead2;
            pHead2 = head;
        }
        int k = l2 -l1;
        while(k>0){ //长的先走
            pHead2 = pHead2->next;
        }
        while(pHead1!=pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
        
    }
};