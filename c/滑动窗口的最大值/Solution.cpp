#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(size==0){
            return res;
        }
        for(int i=0;i+size-1<num.size();i++){
            int m = num[i];
            for(int t =1;t<size;t++){
                m = max(m,num[i+t]);
            }
            res.push_back(m);
        }
        return res;
    }
};
int main(){
    vector<int>num = {2,3,4,2,6,2,5,1};
    vector<int> res = Solution().maxInWindows(num,3);
    cout<<res[5];
    return 0;
}