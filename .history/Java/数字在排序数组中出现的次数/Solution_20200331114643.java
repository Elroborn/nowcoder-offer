public class Solution {
    public int GetNumberOfK(int [] array , int k) {
        int cnt = 0;
        for(int i=0;i<array.length;i++){
            if(array[i]==k){
                break;
            }
        }
        for(int j=i;j<array.length;j++){
            cnt+=1;
            if(array[j]!=k){
                break;
            }
        }
        return cnt;
       
    }
    public static void main(String[] args) {
        
    }
}