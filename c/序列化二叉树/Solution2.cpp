#include<iostream>
#include<vector>

//未通过
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
	vector<int> buf;
	int index = -1;
	void preOrder(TreeNode* root){
		if(root==nullptr){
			buf.push_back(0x80000);
			return;
		}
		buf.push_back(root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
    char* Serialize(TreeNode *root) {
        if(root==nullptr){
            return NULL;
        }
		preOrder(root);
		int* ch = new int(buf.size());
		for(int i=0;i<buf.size();i++){
			ch[i] = buf[i];
		}
		return (char*)ch;
    }

    TreeNode* Deserialize(char *str) {
        if(str==nullptr){
            return nullptr;
        }
		int* tmp = (int*)str;
		return Deserialize(tmp);
    }
	TreeNode* Deserialize(int *str) {
		index+=1;
		if(str[index]==0x80000){
			return nullptr;
		}
		TreeNode* root = new TreeNode(str[index]);
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
    }
};

int main(){
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(2);
	char* ch = Solution().Serialize(root);
    root = Solution().Deserialize(ch);
    cout<<root->val;
	return 0;
}