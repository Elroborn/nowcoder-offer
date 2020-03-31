public class Solution {
    public int GetNumberOfK(int [] array , int k) {
        int cnt = 0;
        int i,j;
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
        int a[] ={1,2,3,3,3,4,5};
        System.out.println(new Solution().GetNumberOfK(a, 3));
    }
}