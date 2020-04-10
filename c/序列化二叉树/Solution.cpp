#include<iostream>
#include <stdio.h>
#include <string.h>
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
	string s = "";
	void pre_order(TreeNode* root){
		if(root==nullptr){
			s.push_back('#');
			s.push_back(',');
			return;
		}
		s+=to_string(root->val);
		s.push_back(',');
		pre_order(root->left);
		pre_order(root->right);
	}
    char* Serialize(TreeNode *root) {
		if(root==nullptr){
			return NULL;
		}
		pre_order(root);
		char* ret = new char[s.length()];
		strcpy(ret,s.c_str());
		return ret;
    }
	TreeNode* Deserialize(string&s) {
		if(s.empty()){
			return nullptr;
		}
		if(s[0]=='#'){
			s = s.substr(2);
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(s));
		s = s.substr(s.find_first_of(',')+1);
		root->left = Deserialize(s);
		root->right = Deserialize(s);
		return root;
		
    }

    TreeNode* Deserialize(char *str) {
		if (str == NULL)
            return NULL;
		string s(str);
		return Deserialize(s);
    }

};

int main(){
	TreeNode* root = new TreeNode(12);
	root->left = new TreeNode(2);
	char* ch = Solution().Serialize(root);
	cout<<ch[0];
	root = Solution().Deserialize(ch);
	return 0;
}