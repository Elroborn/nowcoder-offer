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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr){
            return 0;
        }
        if(pRoot!=nullptr && pRoot->left==nullptr && pRoot->right==nullptr){
            return 1;
        }
        int left = TreeDepth(pRoot->left)
    
    }
};