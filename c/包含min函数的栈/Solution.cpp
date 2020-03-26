#include<iostream> 
#include<stack>
using namespace std;
class Solution {
public:
    void push(int value) {
    	s.push(value);
    	if(s_min.empty()){
    		s_min.push(value);
		}
		if(value<=s_min.top()){
			s_min.push(value);
		}
        
    }
    void pop() {
    	if(s.top()==s_min.top()){//˵��Ҫpop��Ԫ������СԪ�أ�����Сջ�����Ҳpop���� 
			s_min.pop();
		}
		s.pop();	
		
    }
    int top() {
    	return s.top();
        
    }
    int min() {
    	return s_min.top();
        
    }
private:
	stack<int> s;
	stack<int> s_min; //ջ��Ԫ����С 
//	int min_v = INT_MAX;
};
int main(){
	Solution s;
	s.push(3);
	s.push(5);
//	s.push(2);
//	s.push(7);
	cout<<s.min();
	return 0;
}
