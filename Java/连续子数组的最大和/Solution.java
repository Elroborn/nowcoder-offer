// 链接：https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484?f=discussion
// 来源：牛客网

// dp[i]表示以元素array[i]结尾的最大连续子数组和.
// 以[-2,-3,4,-1,-2,1,5,-3]为例
// 可以发现,
// dp[0] = -2
// dp[1] = -3
// dp[2] = 4
// dp[3] = 3
// 以此类推,会发现
// dp[i] = max{dp[i-1]+array[i],array[i]}.
public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
		int dp = array[0];
		int greatNum = dp;
		for(int i=1;i<array.length;i++){
			dp = dp+array[i]<array[i]?array[i]:dp+array[i];
			if(dp>greatNum){
				greatNum = dp;
			}
		}
		return greatNum;
	}
	public static void main(String[] args) {
		int arr[] = {6,-3,-2,7,-15,1,2,2};
		System.out.println(new Solution().FindGreatestSumOfSubArray(arr));
	}
}