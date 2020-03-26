#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	int row = matrix.size(),col = matrix[0].size();
    	int circle = ((row>col?col:row)-1)/2 +1;
    	vector<int> res;
    	for(int c=0;c<circle;c++){
    		for(int i = c;i<col-c;i++){
    			res.push_back(matrix[c][i]); //从左到右 
			}
			for(int j=c+1;j<row-c;j++){
				res.push_back(matrix[j][col-c-1]); //从上到下 
			}
			for(int k =col-c-1-1;k>=c&&row-c-1 != c;k--) {
				res.push_back(matrix[row-c-1][k]);//从右到左 ，发现如果单行，即row-c-1 = c 时会出现重复，则判断加入row-c-1 != c
			}
			for(int l =row-c-1-1;l>c&&col-c-1 != c;l--) {
				res.push_back(matrix[l][c]);//从下到上 ，发现如果单列，即col-c-1 = c，则重复，所以加入判断col-c-1 != c
			}
		}
    	return res;

    }
};

int main() {
	int N=3, M=3; 
	int a[N][M] = {{1,2,3},{4,5,6},{7,8,9}};
    
    vector<vector<int> > obj(N,vector<int>(M)); //定义二维动态数组5行6列 
 
    for(int i=0; i< N; i++)//输出二维动态数组 
    {
        for(int j=0;j<M;j++)
        {
            obj[i][j] = a[i][j];
        }
    }
    vector<int >res = Solution().printMatrix(obj);
    for(int i=0;i<M*N;i++){
    	cout<<res[i];
	}
	return 0;
}
