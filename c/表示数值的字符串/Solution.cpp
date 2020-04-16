#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    bool isNumeric(char* string)
    {
		bool hasE = false,hasDot = false,hasSign = false;
		for(int i=0;i<strlen(string);i++){
			if(string[i]=='E' || string[i]=='e'){
				if(i==strlen(string)-1){
					return false;
				}
				if(hasE){
					return false;
				}
				hasE = true;
			}
			else if(string[i]=='.'){
				if(hasDot || hasE){
					return false;
				}
				hasDot = true;
			}
			else if(string[i]=='+' || string[i]=='-'){
				//出现过，则第二次一定要在e后面
				if(hasSign && string[i-1]!='E' && string[i-1]!='e'){
					return false;
				}
				//第一次出现，要么第一位，要么e后面 !(i==0 || string[i-1]=='e')
				if(!hasSign && i>0 && string[i-1]!='e' && string[i-1]!='E'){
					return false;
				}
				hasSign = true;
			}
			else if(string[i]<'0' || string[i]>'9'){
				return false;
			}

		}
		return true;
    }

};
int main(){
	char str[] = {'+','1'};
	cout<<Solution().isNumeric(str);
	return 0;
}