#include<iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int len = 0;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int i = 0;
        while (str[i]!='\0')
        {
            i+=1;
        }
        len = i;
        bool *flag= new bool[rows*cols];
        memset(flag,false,cols*rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(matrix,rows,cols,i,j,str,0,flag)){
                    return true;
                }
            }
        }
        return false;
    
    }
    bool dfs(char* matrix, int rows, int cols, int i,int j,char* str,int k,bool flag[]){
        int index = i*cols + j;
        if(i<0 || i>=rows || j<0 || j>=cols || matrix[index]!=str[k]|| flag[index]==true){
            return false;
        }
        if(k==len-1){
            return true;
        }
        flag[index] = true;
        if(dfs(matrix,rows,cols,i-1,j,str,k+1,flag)||
        dfs(matrix,rows,cols,i+1,j,str,k+1,flag)||
        dfs(matrix,rows,cols,i,j-1,str,k+1,flag)||
        dfs(matrix,rows,cols,i,j+1,str,k+1,flag)){
            return true;
        }
        flag[index] = false;
        return false;
    }
};

int main(){
   char matrix[] = {'a','b','c','d'};
   char str[] = {'a','b','d'};
   cout<<Solution().hasPath(matrix,2,2, str);
}