#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int dp = array[0];
    	int greatNum = dp;
    	for(int i=1;i<array.size();i++){
    		dp = dp+array[i]<array[i]?array[i]:dp+array[i];
    		greatNum = dp>greatNum?dp:greatNum;
		}
		return greatNum;
    }
};

int main(){
	int arr[] = {100,6,-3,-2,7,-15,1,2,2};
	vector<int> a(arr,arr+8);
	cout<<Solution().FindGreatestSumOfSubArray(a);
	return 0;
}
