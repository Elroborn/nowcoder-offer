// 思路：将n与n-1想与会把n的最右边的1去掉，比如
// 1100&1011 = 1000
// 再让count++即可计算出有多少个1

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
		 while(n!=0) {
		 	count+=1;
		 	n = n&(n-1);
		 }
		 return count;
     }
};
