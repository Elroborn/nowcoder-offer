import java.util.ArrayList;
public class Solution {
    //冒泡排序，不过只排外面的k轮即可
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) { 
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(k>input.length){
            return res;
        }
        for(int i=0;i<k;i++){
            for(int j=input.length-1;j>i;j--){
                if(input[j]<input[j-1]){
                    int t = input[j];
                    input[j] =input[j-1];
                    input[j-1] =t;
                    }
            }
            res.add(input[i]);
        }
        return res;
    }
    public static void main(String[] args) {
        int arr[] = {4,5,1,6,2,7,3,8};
        System.out.println(new Solution().GetLeastNumbers_Solution(arr,20));
    }
}