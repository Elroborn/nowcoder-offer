#include<iostream>
using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
    	int f = 1,g = 2;
    	while(number-1){
    		g = g + f;
    		f = g - f;
    		number-=1;
		}
		return f;
		
    
    }
};

int main(){
	cout<<Solution().jumpFloor(4);
}
