#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre,int l1,int r1,vector<int> vin,int l2,int r2){
		if(l1>r1 || l2>r2){
			return NULL;
		}
		TreeNode* root = new TreeNode(pre[l1]);
		for(int i=l2;i<=r2;i++){
			if(vin[i]==pre[l1]){
				root->left = reConstructBinaryTree(pre,l1+1,l1+i-l2,vin,l2,i-1);
				root->right = reConstructBinaryTree(pre,l1+i-l2+1,r1,vin,i+1,r2);
				break;
			}
		}
		return root;
	}
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	TreeNode* root = reConstructBinaryTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
    	return root;
    }
};
void show_tree(TreeNode *root){
	if(root!=NULL){
		cout<<root->val;
		show_tree(root->left);
		show_tree(root->right);
	}
}
int main(){
	int a[] = {1,2,4,7,3,5,6,8};
	vector<int>pre(a, a + 8 );
	int b[] = {4,7,2,1,5,3,8,6};
	vector<int>in(b, b+ 8 );
	TreeNode *root = Solution().reConstructBinaryTree(pre,in);
	show_tree(root);
	return 0;
} 
