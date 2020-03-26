#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> res;
    vector<int> printListFromTailToHead(ListNode* head) {
    	
    	if(head!=NULL){
    		this->printListFromTailToHead(head->next);
    		res.push_back(head->val);
		}
    
    	return res;
        
    }
    
    vector<int> printListFromTailToHead2(ListNode* head) {
    	stack<int> tmp;
    	vector<int> res2;
    	
    	while(head!=NULL){
    		tmp.push(head->val);
    		head = head->next;
		}
    	while(!tmp.empty()){
    		res2.push_back(tmp.top());
    		tmp.pop();
		}
    	return res2;
        
    }
    
    vector<int> printListFromTailToHead3(ListNode* head) {
    	vector<int> res2;
    	ListNode n =  ListNode(-1);
    	ListNode *new_head = &n;
    	while(head!=NULL){
    		ListNode *p = head;
    		head = head->next;
    		p->next = new_head->next;
    		new_head->next = p;
		}
		new_head = new_head->next;
    	while(new_head!=NULL){
    		res2.push_back(new_head->val);
    		new_head = new_head->next;
    		
		}
    	return res2;
        
    }
};

int main() {
	ListNode a = ListNode(1);
	ListNode b = ListNode(2);
	ListNode c = ListNode(3);
	a.next = &b;
	b.next = &c;
	vector<int> r = Solution().printListFromTailToHead3(&a);
	for(int i = 0; i < 3; i++){
	  cout << "value of vec [" << i << "] = " << r[i] << endl;
	}
//	ListNode* head = ListNode(1);
	return 0;
}
