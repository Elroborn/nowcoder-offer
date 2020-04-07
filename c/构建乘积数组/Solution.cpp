#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int>vec;
        if(A.size()==0){
            return vec;
        }
        vec.push_back(1);
        for(int i=0;i<A.size()-1;i++){
            vec.push_back(vec.back()*A[i]);
        }
        int tmp = 1;
        for(int i=A.size()-1;i>=0;i--){
            vec[i]*=tmp;
            tmp*=A[i];
        }
        return vec;
    
    }
};