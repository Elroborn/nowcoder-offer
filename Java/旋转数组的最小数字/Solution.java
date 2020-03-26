import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if(array.length==0){
            return 0;
        }
        else if(array.length==1){
            return array[0];
        }
        else{
            for(int i=1;i<array.length;i++){
                if(array[i]<array[i-1]){
                    return array[i];
                }
            }

        }
        return 0;
    }
    public static void main(String[] args) {
        int array[] = {3,4,5,1,2};
        System.out.println(new Solution().minNumberInRotateArray(array));
    }
    
}