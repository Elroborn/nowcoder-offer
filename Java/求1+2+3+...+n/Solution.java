public class Solution {
    // 不让用乘除和for，则用递归，而不让用if，则用&&的短路原则
    public int Sum_Solution(int n) {
        // if(n==0){
        //     return n; //递归边界
        // }else{
        //     n +=Sum_Solution(n-1);
        // }
        boolean tmp = (n>0) && ((n += Sum_Solution(n-1))>0); //Java &&必须作用是boolean，如果n<=0 则n>0为假，则后边不执行
        return n;
        
    }
    public static void main(String[] args) {
        System.out.println(new Solution().Sum_Solution(10));
    }
}