#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
    	if(array.size()==1){
    		return ;
		}
		for(int i=1;i<array.size();i++){
			if((array[i]&1)==1){//ÆæÊý
				int j = i-1,t = array[i];
				while(j>=0 && (array[j]&1)==0){
					array[j+1] = array[j];
					j--;
				}
				array[j+1] = t;
			}
		}
    	
        
    }
};

int main(){
	int a[] = {1,2,3,4,5};
	vector<int> array(a,a+5);
	Solution().reOrderArray(array);
	for(int i = 0;i<5;i++){
		cout<<array[i];
	}
	return 0;
}
