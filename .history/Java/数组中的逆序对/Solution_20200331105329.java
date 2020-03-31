public class Solution {
    public int InversePairs(int [] array) {
        int cnt = 0;
        for(int i = 0;i<array.length;i++){
            for(int j = i+1;j<array.length;j++){
                if(array[i]>array[j]){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
    public static void main(String[] args) {
        int a[] = {1,2,3,4,5,6,7,0};
        System.out.println(new Solution().InversePairs(a));
        
    }
}