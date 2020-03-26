#include<iostream> 
#include<vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> res;
    	vector<TreeNode*> queue;
    	if(root!=NULL){
    		queue.push_back(root);
		}else{
			return res;
		}
		while(!queue.empty()){
			TreeNode* t = queue[0];
			res.push_back(t->val);
			if(t->left!=NULL){
				queue.push_back(t->left);
			}
			if(t->right!=NULL){
				queue.push_back(t->right);		
			}
		
			queue.erase(queue.begin());
		
		}
		return res;

    }
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	vector<int> res = Solution().PrintFromTopToBottom(root);
	for(int i=0;i<3;i++){
		cout<<res[i];
	}
	return 0;
}
