#include<iostream>
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
	void Mirror_node(TreeNode *pRoot){	
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
	}
    void Mirror(TreeNode *pRoot) {
    	if(pRoot!=NULL){
    		Mirror_node(pRoot);
    		Mirror(pRoot->left);
    		Mirror(pRoot->right);
		}
    }
    
};

void show_tree(TreeNode* pRoot){
	if(pRoot!=NULL){
		std::cout<<pRoot->val;
		show_tree(pRoot->left);
		show_tree(pRoot->right);
	}
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution().Mirror(root);
    show_tree(root);
	return 0;
}
