#include<iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
    	if(pHead==NULL){
    		return NULL; 
		}
		RandomListNode* curr = pHead;
		while(curr!=NULL){
			RandomListNode* cloneNode = new RandomListNode(curr->label);
			RandomListNode* next = curr->next;
			curr->next = cloneNode;
			cloneNode->next = next;
			curr = next;
		}
		curr = pHead;
		while(curr!=NULL){
			RandomListNode* cloneNode = curr->next;
			cloneNode->random = curr->random==NULL?NULL:curr->random->next;
			curr = curr->next->next;
		}
		curr = pHead;
		RandomListNode* pClone = pHead->next;
		while(curr!=NULL){
			RandomListNode* cloneNode = curr->next;
			curr->next = cloneNode->next;
			cloneNode->next = cloneNode->next==NULL?NULL:cloneNode->next->next;
			curr = curr->next;
		}
		return pClone;
        
    }
};
int main(){
	RandomListNode* head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	RandomListNode* clo = Solution().Clone(head);
	cout<<clo->label;
	return 0;
}
