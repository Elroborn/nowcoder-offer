#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
    	stack1.push(node);
    }

    int pop() {
    	if(stack2.empty() && stack1.empty()){
    		return -1;
		}
		if(stack2.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int top = stack2.top();
		stack2.pop();
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(){
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	return 0;
}
