#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
bool compare(vector<int> o1,vector<int>o2){
	if(o1.size()>o2.size()){
		return true;
	}else{
		return false;
	}
}
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > res;
    	vector<int> cur;
    	dfs(root,expectNumber,cur,res);
    	sort(res.begin(),res.end(),compare);
    	return res;
    }
	void dfs(TreeNode* root,int target,vector<int>cur,vector<vector<int> >& res){
		if(root==NULL){
			return ;
		}
		int val = root->val;
		cur.push_back(val);
	
		if(root->left==NULL && root->right==NULL && target==val){
			res.push_back(cur);
		
			
		}else{
			dfs(root->left,target-val,cur,res);
			dfs(root->right,target-val,cur,res);
		}
		cur.pop_back();
	}
};

void test(vector<int> a){
	a.push_back(233);
}
int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(1);
	vector<vector<int> > res = Solution().FindPath(root,3);
	cout<<res[0].size();
//	vector<int> a;
//	test(a);
//	cout<<a.size();
	return 0;
}
