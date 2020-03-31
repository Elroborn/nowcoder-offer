public class Solution {
    public int InversePairs(int [] array) {
        int cnt = 0;
        for(int i = 0;i<array.length;i++){
            for(int j = i+1;j<array.length;j++){
                if(a[i]>a[j]){
                    cnt+=1;
                }
            }
        }
        
    }
    public static void main(String[] args) {
        
    }
}