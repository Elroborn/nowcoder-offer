#include<iostream>
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res =0;
        for(int i=1;i<=n;i*=10){
            int k = n%(i*10);
            int t = 0;
            if(k>2*i-1){
                t = i;
            }else if (k<i)
            {
                t = 0;
            }else{
                t = k-i+1;
            }
            res +=(n/(10*i)*i + t);
            
        }
        return res;
    
    }
};
int main(){
    cout<<Solution().NumberOf1Between1AndN_Solution(13);
    return 0;
}