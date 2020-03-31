#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> char_map;
        vector<char>single;
        for(int i=0;i<str.length();i++){
            map<char,int>::iterator iter = char_map.find(str[i]);
            if(iter != char_map.end()) { //find 多次
                int v = iter->second;
                char_map.insert(pair<char,int>(str[i],++v));
                vector<char>::iterator s = find(single.begin(), single.end(), str[i]);//第一个参数是array的起始地址，第二个参数是array的结束地址，第三个参数是需要查找的值
                if (s != single.end())//如果找到，就输出这个元素
                {
                    single.erase(s);
                }	
            }else{ //not find  第一次
                char_map.insert(pair<char,int>(str[i],1));
                single.push_back(str[i]);
            }
        }
    
        for(int i=0;i<str.length();i++){
            vector<char>::iterator s = find(single.begin(), single.end(), str[i]);
            if(s!=single.end()){
                return i;
            }

        }
        return -1;
        
    }

    int FirstNotRepeatingChar2(string str) {
        map<char,int> char_map;
        for(int i=0;i<str.length();i++){
         
        }
    
        for(int i=0;i<str.length();i++){
   

        }
        return -1;
        
    }
};
int main(){
    cout<<Solution().FirstNotRepeatingChar("acah");
    return 0;
}