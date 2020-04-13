#include<iostream>
using namespace std;
class Solution {
public:
    int cutRope(int target) {
        if(target==2){
            return 1;
        }
        if(target==3){
            return 2;
        }
        int* d = new int[target+1];
        d[1] = 1;
        d[2] = 2;
        d[3] = 3;
        for(int i=4;i<=target;i++){
            int m=0;
            for(int j=i-1;j>0;j--){ //for (int j = 1; j <=i/2 ; j++) {
                int tmp = j*d[i-j];
                m = max(tmp, m);
            }
            d[i] = m;
        }
        return d[target];
    }

};