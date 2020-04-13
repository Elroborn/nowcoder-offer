import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer>res = new ArrayList<>();
        if(size==0){
            return res;
        }
        for(int i=0;i+size-1<num.length;i++){
            int m = num[i];
            for(int t = 1;t<size;t++){
                m = Math.max(m, num[i+t]);
            }
            res.add(m);
        }
        return res;
        
    }
    public static void main(String[] args) {
        int num[] ={2,3,4,2,6,2,5,1};
        System.out.println(new Solution().maxInWindows(num, 3));
    }
}