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
        bool isSymmetrical(TreeNode* pRoot)
        {
            if(pRoot==nullptr){
                return true;
            }
            vector<TreeNode*> q;
            q.push_back(pRoot->left);
            q.push_back(pRoot->right);
            while(!q.empty()){
                TreeNode* left = q[0];
                TreeNode* right = q[1];
                q.erase(q.begin());
                q.erase(q.begin());
                if(left==nullptr && right==nullptr){
                    continue;
                }
                if(left==nullptr || right==nullptr){
                    return false;
                }
                if(left->val != right->val){
                    return false;
                }
                q.push_back(left->left);
                q.push_back(right->right);
                q.push_back(left->right);
                q.push_back(right->left);
            }
            return true;
        }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    cout<<Solution().isSymmetrical(root);
      
    return 0;

}