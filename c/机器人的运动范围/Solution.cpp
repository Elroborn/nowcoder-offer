#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};    //四个方向 
    int sum=1;    //记录结果
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0){
            return 0;
        }
        bool* flag = new bool[cols*rows];
        memset(flag,false,rows*cols);
        dfs(0,0,rows,cols,flag,threshold);
        return sum;
        
    }
    void dfs(int i,int j,int rows,int cols,bool flag[],int threshold){
        int index = i*cols +j;
        flag[index] = true;
        for(int d=0;d<4;d++){
            int new_i = i+dy[d];
            int new_j = j+dx[d];
            if(new_i>=0 && new_i<rows && new_j>=0 && new_j<cols && getNum(new_i)+getNum(new_j)<=threshold
            && flag[new_i*cols+new_j]!=true){
                sum+=1;
                dfs(new_i,new_j,rows,cols,flag,threshold);
            }
        }
        
        

    }
    int getNum(int i){
        int s = 0;
        do{
            s+=(i%10);

        }while((i=i/10)>0);
        return s;
    }
};



int main(){
    cout<<Solution().movingCount(-10,2,2);
    // cout<<Solution().getNum(-10);
    return 0;
}