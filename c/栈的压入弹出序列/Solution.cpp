#include<iostream>
#include<vector> 
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	vector<int> stack;
    	int pop_index = 0;
    	for(int i=0;i<pushV.size();i++){
    		stack.push_back(pushV[i]);
    		while(!stack.empty() && stack.back()==popV[pop_index]){
    			stack.pop_back();
				pop_index++;	
			}
		}
		return stack.empty();
        
    }
};
int main(){
//	int a[] = {1,2,3,4,5};
//	vector<int> pushV = vector<int>(a,a+5);
//	int b[] = {4,5,3,2,1};
//	vector<int> popV = vector<int>(b,b+5);
//	cout<<Solution().IsPopOrder(pushV,popV);
	vector<int> a;
	cout<<a.size();
	return 0;
} 
