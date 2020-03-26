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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead==NULL || k<=0){
    		return NULL;
		}
		int count = 0;//代表p和q的距离
		ListNode *p = pListHead;
		ListNode *q = pListHead;
		while(p!=NULL) {
			p = p->next;
			if(count>=k){
				q = q->next;
			}
			count++;
		}
		if(count<k){
			return NULL;
		}else{
			return q;
		}
    
    }
    
     ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
    	if(pListHead==NULL || k<=0){
    		return NULL;
		}
		int count = 0;//代表p和q的距离
		ListNode *p = pListHead;
		ListNode *q = pListHead;
		for(;p!=NULL;count++){
			if(count>=k){
				q = q->next;
			}
			p =p->next;
		}
		return count<k ?NULL:q;
    
    }
};
int main(){
	ListNode node = ListNode(1);
	ListNode node1 = ListNode(2);
	node.next = &node1;
	std::cout<<Solution().FindKthToTail2(&node,1)->val;
	return 0;
}
