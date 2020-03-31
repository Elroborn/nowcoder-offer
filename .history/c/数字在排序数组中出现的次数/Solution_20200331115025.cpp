#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0;
        int i,j;
        for(i=0;i<data.size();i++){
            if(data[i]==k){
                break;
            }
        }
        for(j=i;j<data.size();j++){
            if(data[j]!=k){
                break;
            }
            cnt+=1;
        }
        
        return cnt;
    }
};
int main(){
    vector<int>arr = {1,2,3,3,3,4,5}
}