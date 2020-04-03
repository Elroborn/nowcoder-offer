#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<5){
            return false;
        }
        vector<int>data(14,0);
        data[0] = -5;
        int min = 14;
        int max = -1;
        for(int i=0;i<numbers.size();i++){
            data[numbers[i]]++;
            if(data[numbers[i]]>1){
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
        if(max-min<5){
            return true;
        }
        return false;
    }
};
int main(){
    vector<int> a = {1,3,2,6,4};
    cout<<Solution().IsContinuous(a);
    return 0;
}