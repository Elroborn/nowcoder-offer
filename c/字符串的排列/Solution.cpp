#include<iostream> 
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
    	if(str.size()>0){
    		string tmp = "";
    		int book[str.size()];
    		memset(book, 0, str.size()*sizeof(int));
    		dfs(str,0,tmp,book);
		}
		
		return res;
        
    }
private:
	vector<string>res;
	void dfs(string s,int index,string tmp,int book[]){
		if(index==s.size() && find(res.begin(),res.end(),tmp) == res.end()){
			res.push_back(tmp);
		}
		for(int i=0;i<s.size();i++){
			if(book[i]==0){
				tmp+=s[i];
				book[i] =1;
				dfs(s,index+1,tmp,book);
				book[i]=0;
				tmp= tmp.substr(0,tmp.size()-1);
			}
		}
		
	}
};
int main(){
//	vector<string>res = Solution().Permutation("abc");
//	cout<<res[1];

	int *a = new int[5];
	
	return 0;
}
