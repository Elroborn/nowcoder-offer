#include<iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
  
		ListNode *new_head = new ListNode(-1);
		ListNode *p = NULL;
		while(pHead!=NULL){
			p = pHead;
			pHead = pHead->next;
			//β�巨
			p->next = new_head->next;
			new_head->next = p; 
			
		}
		return new_head->next;

    }
};
int main(){
	ListNode *node = new ListNode(1);
	ListNode *node1 = new ListNode(2);
	node->next = node1;
	ListNode *r = Solution().ReverseList(node);
	while(r!=NULL){
		std::cout<<r->val;
		r = r->next;
	}
	return 0;
}
