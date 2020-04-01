import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Solution {
    public int InversePairs1(int [] array) { //不通过
        int cnt = 0;
        for(int i = 0;i<array.length;i++){
            for(int j = i+1;j<array.length;j++){
                if(array[i]>array[j]){
                    cnt+=1;
                }
            }
        }
        return cnt%1000000007;
    }
    // 采用归并排序，在排序的过程中 做从小到大排序，则每次的交换就代表出现了逆序
    public int InversePairs(int [] array) {
        int tmp[] = new int[array.length];
        for(int i=0;i<array.length;i++){
            tmp[i] = array[i];
        }
        return merge_sort(array, 0, array.length-1, tmp)%1000000007;
    }
    public int merge_sort(int []array,int left,int right,int []tmp){
        if(left==right){
            return 0;
        }
        int mid = (left+right) /2;
        int left_cnt = merge_sort(tmp, left, mid,array)%1000000007; // 这里注意因为tmp最后是排好序的，所以传入，如不这样，则需在最后加入一个将tmp内容拷贝到array的代码
        int right_cnt = merge_sort(tmp, mid+1, right,array)%1000000007;
        int i = mid;
        int j = right;
        int index = right;
        int cnt = 0;
        while(i>=left && j>mid){
            if(array[i]>array[j]){ //说明是逆序对
                cnt+=(j-mid); //因为这里递归，说明左半边和右半边都是有序，而i和j代表的都是每个半边的最大，所以如果arr[i]>arr[j]即代表ii整个右边所有都大
                if(cnt>=1000000007){
                    cnt = cnt%1000000007;
                }
                tmp[index--] = array[i--];
            }else{
                tmp[index--] =array[j--];
            }
        }
        while(i>=left){
            tmp[index--] = array[i--];
        }
        while( j>mid){
            tmp[index--] = array[j--];
        }
        return (left_cnt + right_cnt +cnt)%1000000007;
    }
    public static void main(String[] args) {
        int a[] = {1,2,3,4,5,6,7,0};
        System.out.println(new Solution().InversePairs(a));
        
    }
}