public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
        //分别计算个位，十位，百位等上面的1的个数
        for(int i=1;i<=n;i*=10){
            int k = n%(i*10);
            int t = 0;
            if(k>2*i-1){ //超过
                t = i;
            }else if(k<i){
                t = 0;
            }else{
                t = k-i+1;
            }
            res += (n/(i*10)*i +t);
        }
        return res;
    
    }
    public static void main(String[] args) {
        System.out.println(new Solution().NumberOf1Between1AndN_Solution(13));
    }
}