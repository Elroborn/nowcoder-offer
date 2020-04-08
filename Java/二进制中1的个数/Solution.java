// 思路：将n与n-1想与会把n的最右边的1去掉，比如
// 1100&1011 = 1000
// 再让count++即可计算出有多少个1

public class Solution {
    public int NumberOf1(int n) {
        int count = 0;
        while(n!=0){
            count++;
            n = n&(n-1);
        }
        return count;
    }
    public static void main(String[] args) {
        int flag = 1;
        while (flag != 0) {
            System.out.println(flag);
            flag = flag << 1;
        }
        System.out.println(flag);
        // System.out.println(new Solution().NumberOf1(-5));
    }
}