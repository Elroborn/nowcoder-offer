#include<iostream> 
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	map<int,int> m;
    	for(int i=0;i<numbers.size();i++){
    		m[numbers[i]] = m[numbers[i]]+1;
		}
		for (map<int, int>::iterator i=m.begin(); i!=m.end(); i++){
			if(i->second>numbers.size()/2){
				return i->first;
			}

    	}
    	return 0;
    
    }
};
int main(){
	
	int a[] = {1,2,3,2,2,2,5,4,2};
	vector<int> arr(a,a+9);
	cout<<Solution().MoreThanHalfNum_Solution(arr);
}
