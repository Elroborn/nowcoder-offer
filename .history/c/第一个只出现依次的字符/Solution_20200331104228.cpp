#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// 说一下解题思路哈，其实主要还是hash，利用每个字母的ASCII码作hash来作为数组的index。
// 首先用一个58长度的数组来存储每个字母出现的次数，为什么是58呢，主要是由于A-Z对应的ASCII码为65-90，
// a-z对应的ASCII码值为97-122，而每个字母的index=int(word)-65，比如g=103-65=38，
// 而数组中具体记录的内容是该字母出现的次数，最终遍历一遍字符串，找出第一个数组内容为1的字母就可以了，时间复杂度为O(n)
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
            int v = char_map[str[i]];
            char_map[str[i]] = v+1;
        }
    
        for(int i=0;i<str.length();i++){
            if(char_map[str[i]]==1){
                return i;
            }
   

        }
        return -1;
    }
    int FirstNotRepeatingChar2(string str) {
        map<char,int> char_map;
        for(int i=0;i<str.length();i++){
            int v = char_map[str[i]];
            char_map[str[i]] = v+1;
        }
    
        for(int i=0;i<str.length();i++){
            if(char_map[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
    int FirstNotRepeatingChar3(string str) {
        vector<int>hash(58,0); //50即 A-Z对应的ASCII码为65-90，a-z对应的ASCII码值为97-122
        for(int i=0;i<str.length();i++){
            int v = hash[str[i]-65];
            hash[str[i]-65] = v+1;
        }
    
        for(int i=0;i<str.length();i++){
            if(char_map[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    cout<<Solution().FirstNotRepeatingChar2("acah");
    return 0;
}