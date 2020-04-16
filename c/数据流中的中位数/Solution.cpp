#include<iostream>
#include<vector>
using namespace std;
class Solution{

public:
    //用vector存，然后插入时排序
    vector<int>vec;
    void Insert(int num){
        vec.push_back(num);
        int i = 0;
        for(i=vec.size()-2;i>=0;i--){
            if(vec[i]>num){
                vec[i+1] = vec[i];
            }else{
                break;
            }
        }
        vec[i+1] = num;
    }
    double GetMedian(){
        int n = vec.size();
        if(n%2==0){
            return (vec[n/2-1]+vec[n/2])/2.0;
        }else{
            return vec[n/2];
        }

    }

};
int main(){
    Solution s;
    s.Insert(2);
    s.Insert(3);
    s.Insert(4);
    s.Insert(5);
    cout<<s.GetMedian();
    return 0;
}