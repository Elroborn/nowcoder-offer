#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool cmp(int a1,int a2){
    string s1 = to_string(a1)+to_string(2);
    string s2 = to_string(a2)+to_string(a1);
    return s1<s2;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        string res = "";
        for(int i=0;i<numbers.size();i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
};
int main(){
   int a[] ={3,2,1};
   vector<int> arr(a,a+3);
   cout<<Solution().PrintMinNumber(arr);
 
    return 0;
}
