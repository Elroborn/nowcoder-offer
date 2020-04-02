// 链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
// 来源：牛客网

// 在答案区找到一个答案，说的很好，叫做双指针技术，就是相当于有一个窗口，窗口的左右两边就是两个指针，
// 我们根据窗口内值之和来确定窗口的位置和宽度。
// 非常牛逼的思路，虽然双指针或者所谓的滑动窗口技巧还是蛮常见的，但是这一题还真想不到这个思路。
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res ;
        int plow =1;
        int phigh = 2;
        while(plow<phigh){
            int cur = (phigh+plow)*(phigh - plow +1)/2;
            if(cur ==sum){
                vector<int>tmp;
                for(int i=plow;i<=phigh;i++){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                plow+=1;
            }else if (cur>sum)
            {
                plow+=1;
            }else
            {
                phigh+=1;
            }
        }
        return res;
        
    }
};
int main(){
    vector<vector<int>> res = Solution().FindContinuousSequence(6);
    for(vector<vector<int>>::iterator it =res.begin();it!=res.end();it++){
        for(vector<int>::iterator it1 = it->begin();it1!=it->end();it1++){
            cout<<*it1;
        }
    }
    return 0;
}