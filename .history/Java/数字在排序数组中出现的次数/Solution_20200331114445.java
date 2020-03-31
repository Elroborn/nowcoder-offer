import java.util.HashMap;
import java.util.Map;
// 该方法不是最优，还可以考虑先排序，或者根据要超过一半，则它出现的次数比其他所有数字出现的次数和还要多
public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        Map<Integer,Integer> res = new HashMap<>();
        for(int i=0;i<array.length;i++){
            Integer t = res.get(array[i]);
            if(t==null){
                res.put(array[i],1);
            }else{
                res.put(array[i],t+1);
            }
        }
       
        for (Integer key : res.keySet()) {
            if(res.get(key)>array.length/2){
                return key;
            }
        }
        return 0;
        
    }
    // 链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163?f=discussion
    // 来源：牛客网
    
    // 如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
    // 在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，
    // 则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。
    // 然后再判断它是否符合条件即可。
    public int MoreThanHalfNum_Solution2(int [] array) {
        int times=1;
        int num = array[0];
        for(int i=1;i<array.length;i++){
            if(times==0){
                times=1;
                num = array[i];
            }else if(array[i]==num){
                times+=1;
            }else{
                times-=1;
            }
        }
        times = 0;
        for(int i=0;i<array.length;i++){
            if(array[i]==num){
                times+=1;
            }
        }
        return times>array.length/2?num:0;
    }
    public static void main(String[] args) {
        int array[] = {1,2,3,2,2,2,5,4,2};
        System.out.println(new Solution().MoreThanHalfNum_Solution2(array));
    }

}