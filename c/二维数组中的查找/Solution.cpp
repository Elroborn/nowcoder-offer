#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	int hang = array.size();
    	int lie = array[0].size();
		int row = 0;
		int col = lie -1;
		while(row<hang && col>=0){
			int value = array[row][col];
			if(target>value){
				row++;
			}
			else if(target<value){
				col--;
			}
			else{
				return true;
			}
		}
		
		return false;
        
    }
};

int main()
{
	int a[2][3] = {{1,2,3},{4,5,6}};
    int N=2, M=3; 
    vector<vector<int> > obj(N,vector<int>(M)); //定义二维动态数组5行6列 
 
    for(int i=0; i< 2; i++)//输出二维动态数组 
    {
        for(int j=0;j<3;j++)
        {
            obj[i][j] = a[i][j];
        }
    }
	cout<<Solution().Find(3,obj);
 
}

