#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	if(rotateArray.size()==0){
    		return 0;
		}
		else if(rotateArray.size()==1){
			return rotateArray[0];
		}else{
			for(int i=1;i<rotateArray.size();i++){
				if(rotateArray[i]<rotateArray[i-1]){
					return rotateArray[i];
				}
			}
		}
        
    }
};

int main(){
	int arr[]= {3,4,5,1,2};
	vector<int> v(arr,arr+5);
	cout<<Solution().minNumberInRotateArray(v);
	return 0;
}
