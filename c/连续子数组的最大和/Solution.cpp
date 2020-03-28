#include<iostream>
#include<vector>
using namespace std;
// ���ӣ�https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484?f=discussion
// ��Դ��ţ����

// dp[i]��ʾ��Ԫ��array[i]��β����������������.
// ��[-2,-3,4,-1,-2,1,5,-3]Ϊ��
// ���Է���,
// dp[0] = -2
// dp[1] = -3
// dp[2] = 4
// dp[3] = 3
// �Դ�����,�ᷢ��
// dp[i] = max{dp[i-1]+array[i],array[i]}.
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
	int arr[] = {6,-3,-2,7,-15,1,2,2};
	vector<int> a(arr,arr+8);
	cout<<Solution().FindGreatestSumOfSubArray(a);
	return 0;
}
