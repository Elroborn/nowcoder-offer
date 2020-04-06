#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> ls;
        for(int i=0;i<n;i++){
            ls.push_back(i);
        }
        int pos = 0;
        while(ls.size()>1){
            pos = (pos+m-1)%ls.size();
            ls.erase(ls.begin()+pos);
        }
        if(ls.size()==1){
            return ls[0];
        }else{
            return -1;
        }
    }
};

int main(){
    cout<<Solution().LastRemaining_Solution(5,4);
    return 0;
}