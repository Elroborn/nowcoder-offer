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
    			res.push_back(matrix[c][i]); //������ 
			}
			for(int j=c+1;j<row-c;j++){
				res.push_back(matrix[j][col-c-1]); //���ϵ��� 
			}
			for(int k =col-c-1-1;k>=c&&row-c-1 != c;k--) {
				res.push_back(matrix[row-c-1][k]);//���ҵ��� ������������У���row-c-1 = c ʱ������ظ������жϼ���row-c-1 != c
			}
			for(int l =row-c-1-1;l>c&&col-c-1 != c;l--) {
				res.push_back(matrix[l][c]);//���µ��� ������������У���col-c-1 = c�����ظ������Լ����ж�col-c-1 != c
			}
		}
    	return res;

    }
};

int main() {
	int N=3, M=3; 
	int a[N][M] = {{1,2,3},{4,5,6},{7,8,9}};
    
    vector<vector<int> > obj(N,vector<int>(M)); //�����ά��̬����5��6�� 
 
    for(int i=0; i< N; i++)//�����ά��̬���� 
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
