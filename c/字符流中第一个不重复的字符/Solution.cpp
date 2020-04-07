#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string s = "";
    int hash[256] = {0};
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s+=ch;
        hash[ch]+=1;
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==1){
                return s[i];
            }
        }
        return '#';
    }

};
int main(){
    Solution s;
    s.Insert('g');
    s.Insert('o');
    s.Insert('o');
    s.Insert('g');
    s.Insert('l');
    cout<<s.FirstAppearingOnce();
    return 0;
}