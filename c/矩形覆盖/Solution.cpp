#include<iostream>
using namespace std;
class Solution {
public:
    int rectCover(int number) {
    	if(number==0){
    		return 0;
		}
    	int f = 1,g =2;
       	while(number-1>0){
           g = f+g;
           f = g-f;
           number -=1;
       }
       return f;

    }
};
int main(){
	cout<< Solution().rectCover(3);
	return 0;
}
