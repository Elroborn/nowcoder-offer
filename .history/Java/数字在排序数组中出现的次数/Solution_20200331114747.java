public class Solution {
    public int GetNumberOfK(int [] array , int k) {
        int cnt = 0;
        int i,j;
        for(i=0;i<array.length;i++){
            if(array[i]==k){
                break;
            }
        }
        for(j=i;j<array.length;j++){
            if(array[j]!=k){
                break;
            }
            cnt+=1;
        }
        return cnt;
       
    }
    public static void main(String[] args) {
        int a[] ={1,2,3,3,3,4,5};
        System.out.println(new Solution().GetNumberOfK(a, 3));
    }
}