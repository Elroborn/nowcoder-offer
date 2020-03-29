#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	//Ã°ÅİÅÅĞò£¬ÅÅÇ°kÂÖ
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	vector<int> res;
    	if(k>input.size()){
    		return res;
		}
		for(int i =0;i<k;i++){
			for(int j = input.size()-1;j>i;j--){
				if(input[j]<input[j-1]){
					int t = input[j];
					input[j] = input[j-1];
					input[j-1] = t;
				}
			}
			res.push_back(input[i]);
		}
		return res;
    }
};
int main(){
	int arr[] = {4,5,1,6,2,7,3,8};
	vector<int> input(arr,arr+8);
	vector<int> res = Solution().GetLeastNumbers_Solution(input,10);
	cout<<res[0];
	cout<<res[1];
	return 0;
}
