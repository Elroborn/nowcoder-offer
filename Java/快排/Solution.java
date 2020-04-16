public class Solution {
    public void quick_sort(int []arr,int left,int right){
        if(left<right){
            int p = partion(arr, left, right);
            quick_sort(arr, left, p-1);
            quick_sort(arr, p+1,right);
        }
    }
    public int partion(int[]arr,int left,int right){
        int tmp = arr[left];
        while(left<right){
            while(left<right && arr[right]>=tmp){
                right--;
            }
            arr[left] = arr[right];
            while(left<right && arr[left]<=tmp){
                left++;
            }
            arr[right] = arr[left];
        }
        arr[left] = tmp;
        return left;
    }
    public static void main(String[] args) {
        int arr[] = {3,4,7,1,2};
        new Solution().quick_sort(arr,0,arr.length-1);
        for(int a:arr){
            System.out.println(a);
        }
       
    }


}