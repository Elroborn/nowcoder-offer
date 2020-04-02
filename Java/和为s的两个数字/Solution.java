import java.util.ArrayList;
public class Solution {
    // 双指针，一个从0往右，一个从lengte往左，主要整明为啥第一对就是最小
    //假如 a+b = sum,则(a-m) + (b+m) =sum 但是(a-m) *(b+m)  <a*b 所有看出外层小也就是第一队小，因为是从外层到内层遍历的
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        int plow = 0;
        int phigh = array.length-1;
        while(plow<phigh){
            if(array[plow]+array[phigh]==sum){
                res.add(array[plow]);
                res.add(array[phigh]);
                return res;
            }else if(array[plow]+array[phigh]>sum){
                phigh-=1;
            }else{
                plow+=1;
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int a[] = {1,2,3,4,5};
        System.out.println(new Solution().FindNumbersWithSum(a, 5));
    }
}