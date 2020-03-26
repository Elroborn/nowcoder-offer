#include<iostream>
#include<string>
using namespace std;
//class Solution {
//public:
//	void replaceSpace(char *str,int length) {
//		int i = 0;
//		int j =0;
//		int count = 0;
//		for(i;i<length;i++){
//			if(str[i]==' '){
//				count++;
//			}
//		}
//		char *new_str = new char[sizeof(char)*(length+count)];
//		for(i=0;i<length;i++){
//			if(str[i]==' '){
//				new_str[j] ='%';
//				new_str[j+1] ='2';
//				new_str[j+2] ='0';
//				j = j+3;
//			}else{
//				new_str[j] = str[i];
//				j+=1;
//			}
//		}
//		
//		for(i=0;i<j;i++){
//			str[i] = new_str[i];
//		}
//	
//
//	}
//};
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count=0;
        for(int i=0;i<length;i++){
            if(str[i]==' ')
                count++;
        }
        for(int i=length-1;i>=0;i--){
            if(str[i]!=' '){
                str[i+2*count]=str[i];
            }
            else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }

        
    }
};
int main(){
	
	char s[] = "We Are Haapy\0\0\0\0\0\0\0\0";
	Solution().replaceSpace(s,12);
	cout<<s;
	return 0;
	
} 
