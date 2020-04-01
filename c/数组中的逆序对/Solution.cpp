#include<iostream>
#include<vector>
using namespace std;
// %1000000007;
class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int>copy(data);
        return merget_sort(data,0,data.size()-1,copy)%1000000007;
    }
    int merget_sort(vector<int>& data,int left,int right,vector<int>& copy){
        if(left ==right){
            return 0;
        }
        int mid = (left+right)/2;
        int left_cnt = merget_sort(data,left,mid,copy)%1000000007;
        int right_cnt = merget_sort(data,mid+1,right,copy)%1000000007;
        int i = mid;
        int j = right;
        int index = right;
        int cnt = 0;
        while(i>=left && j>mid){
            if(data[i]>data[j]){
                //因为这里递归，说明左半边和右半边都是有序，
                //而i和j代表的都是每个半边的最大，所以如果arr[i]>arr[j]即代表ii整个右边所有都大
                cnt +=(j-mid);
                if(cnt>=1000000007){
                    cnt = cnt%1000000007;
                }
                copy[index--] =data[i--];
            }else{
                copy[index--] =data[j--];
            }
        }
        while(i>=left){
            copy[index--] =data[i--];
        }
        while(j>mid){
            copy[index--] =data[j--];
        }
        for(int s=left;s<=right;s++){
            data[s] =copy[s];
        }
        return (left_cnt+right_cnt+cnt)%1000000007;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,0};
    cout<<Solution().InversePairs(arr);
    return 0;
}