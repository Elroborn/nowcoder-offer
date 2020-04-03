#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length()<n){
            return "";
        }
        str = reverse(str,0,n-1);
        str = reverse(str,n,str.length()-1);
        str = reverse(str,0,str.length()-1);
        return str;
    }
    string reverse(string str,int left,int right){
        while(left<right){
            char t = str[left];
            str[left] = str[right];
            str[right] = t;
            left++;
            right--;
        }
        return str;
    }
};
int main(){
    string s = "abcXyzder";
    cout<<Solution().LeftRotateString(s,3);
}