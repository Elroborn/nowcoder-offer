#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
    	if(pRootOfTree==NULL){
    		return NULL;
		}
        Inorder(pRootOfTree);
        TreeNode* res = pRootOfTree;
		while(res->left) { //回到表头 
			res = res->left; 
		}
		return res;
    }
    void Inorder(TreeNode* root){
    	if(root==NULL){
    		return;
		}
		Inorder(root->left);
		root->left = pre;
		if(pre!=NULL){
			pre->right = root;
		}
		pre = root;
		Inorder(root->right);
    	
	}
private:
	TreeNode* pre = NULL;
};

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->right = new TreeNode(5);
	TreeNode* res = Solution().Convert(root);
	cout<<res->val;
	cout<<res->right->val;
}


