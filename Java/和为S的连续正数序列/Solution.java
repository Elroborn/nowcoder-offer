// 链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
// 来源：牛客网

// 在答案区找到一个答案，说的很好，叫做双指针技术，就是相当于有一个窗口，窗口的左右两边就是两个指针，
// 我们根据窗口内值之和来确定窗口的位置和宽度。
// 非常牛逼的思路，虽然双指针或者所谓的滑动窗口技巧还是蛮常见的，但是这一题还真想不到这个思路。
import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer> >res = new ArrayList<ArrayList<Integer> >();
        int plow = 1;
        int phigh = 2;
        while(phigh>plow){
            int cur = (phigh+plow) *(phigh-plow+1) /2; //因为连续，等差数列
            if(cur == sum){
                ArrayList<Integer>tmp = new ArrayList<Integer>();
                for(int i=plow;i<=phigh;i++){
                    tmp.add(i);
                }
                res.add(tmp);
                phigh+=1; //plow+=1 都可以
            }else if(cur>sum){
                plow+=1;
            }else{
                phigh+=1;
            }
        }
       return res;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().FindContinuousSequence(6));
    }
}