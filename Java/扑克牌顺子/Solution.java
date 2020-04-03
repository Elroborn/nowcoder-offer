import java.util.Arrays;
import java.util.Collections;
public class Solution {
    //排序
    public boolean isContinuous1(int [] numbers) {
        if(numbers.length<5){
            return false;
        }
        Arrays.sort(numbers);
        int zero_cnt = 0;
        int i=0;
        while(numbers[i]==0){
            zero_cnt++;
            i++;
        }
        for(;i<numbers.length-1;i++){
            if(numbers[i+1]== numbers[i]){ //对子
                return false;
            }
            zero_cnt -= (numbers[i+1] -numbers[i]-1);
            if(zero_cnt<0){
                return false;
            }

        }
        return true;
    }
    //桶排序 最终max -min <5 且除0外无重复 这里因为一定要5张牌，所以如果如果没有对子，那么最大最小之间如果非连续可定>5
    public boolean isContinuous(int [] numbers) {
        if(numbers.length<5){
            return false;
        }
        int data[] =new int[14];
        int max = -1;
        int min = 14;
        data[0] = -5;
        for(int i=0;i<numbers.length;i++){
            data[numbers[i]] ++;
            if(data[numbers[i]]>1){ //对子
                return false;
            }
            if(numbers[i]==0){
                continue;
            }
            if(numbers[i]>max){
                max = numbers[i];
            }
            if(numbers[i]<min){
                min = numbers[i];
            }

        }
        if(max -min <5){
            return true;
        }
        return false;
        
    }
    public static void main(String[] args) {
        int a[] = {3,4,6,0};
        System.out.println(new Solution().isContinuous(a));
    }
}