#include<iostream>
using namespace std;
class Solution {
public:
    int Fibonacci1(int n) {
    	if(n==0 || n==1){
    		return n;
		} 
		return Fibonacci(n-1) + Fibonacci(n-2);
    }
    
    int Fibonacci(int n) {
    	int f = 0,g = 1;
    	while(n){
    		g = g + f;
    		f = g - f;
    		n-=1;
		}
		return f;
		
    
    }
};

int main(){
	cout<<Solution().Fibonacci(5);
}
