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
	//看root2是否为以root1为根的子树 
	bool IsSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
		if(pRoot2==NULL) {
			return true;
		}
		if(pRoot1==NULL){
			return false;
		}
		if(pRoot1->val!=pRoot2->val){
			return false;
		}
		return IsSubtree(pRoot1->left,pRoot2->left) && IsSubtree(pRoot1->right,pRoot2->right);
		
	}
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if(pRoot1!=NULL && pRoot2!=NULL){
    		if(IsSubtree(pRoot1,pRoot2)){
    			return true;
			}
			return IsSubtree(pRoot1->left,pRoot2) || IsSubtree(pRoot1->right,pRoot2);
    		
		}else{
			return false;
		}

    }
};

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(3);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    // root2.right.right = new TreeNode(3);
    std::cout<<Solution().HasSubtree(root1,root2);
	return 0;
}
