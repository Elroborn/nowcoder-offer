#include<iostream>
#include<vector>
using namespace std;
// 双指针，一个从0往右，一个从lengte往左，主要整明为啥第一对就是最小
//假如 a+b = sum,则(a-m) + (b+m) =sum 但是(a-m) *(b+m)  <a*b 所有看出外层小也就是第一队小，因为是从外层到内层遍历的
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>  res;
        int plow = 0;
        int phigh = array.size()-1;
        while (plow<phigh)
        {
            if(array[plow]+array[phigh]==sum){
                res.push_back(array[plow]);
                res.push_back(array[phigh]);
                return res;
            }else if(array[plow]+array[phigh]>sum){
                phigh-=1;
            }else{
                plow+=1;
            }
        }
        return res;
    }
};
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int>res = Solution().FindNumbersWithSum(a, 5);
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    return 0;
}