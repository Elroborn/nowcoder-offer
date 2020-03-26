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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
    	
    	ListNode * new_head = new ListNode(-1);
    	ListNode *r = new_head; //β�巨 
    	while(pHead1!=NULL && pHead2!=NULL){
    		if(pHead1->val < pHead2->val){
    			r->next = pHead1;
    			r = r->next;
    			pHead1 = pHead1->next; 
			}else{
				r->next = pHead2;
    			r = r->next;
    			pHead2 = pHead2->next; 
			}
		}
		
		pHead1 = pHead1!=NULL?pHead1:pHead2;
		while(pHead1!=NULL){
			r->next = pHead1;
			r = r->next;
			pHead1 = pHead1->next; 
		}
		r->next = NULL; 
    	return new_head->next;
        
    }
};

int main(){
	ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(6);

    ListNode *h2 = new ListNode(2);
    h2->next = new ListNode(3);
    // h2->next->next = new ListNode(5);

    ListNode *r = Solution().Merge(h1, h2);
    while(r!=NULL){
        std::cout<<r->val;
        r = r->next;
    }

	return 0;
}
