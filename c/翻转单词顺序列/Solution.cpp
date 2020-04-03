#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        int i=0;
        while(i<str.length()){
            if(str[i]==' '){
                i++;
            }else{
                break;
            }
        }
        if(i==str.length()){
            return str;
        }
        vector<string> arr = split_space(str);
        string res = "";
        for(int i = arr.size()-1;i>=0;i--){
            res+=arr[i];
            if(i>0){
                res+=" ";
            }
        }
        return res;
        
    }
    vector<string> split_space(string str){
        vector<string>res;
        string t = "";
        for(int i=0;i<str.size();i++){
            if(str[i]!=' '){
                t+=str[i];
            }else{
                res.push_back(t);
                t = "";
            }
        }
        if(t!=""){
            res.push_back(t);
        }
        return res;
    }
};
int main(){
    string s = "  ";
    cout<<"!!"<<Solution().ReverseSentence(s).length()<<"!!";
    return 0;
}