#include<iostream>
using namespace std;
struct TreeNode {
    int val = 0;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val):
        val(val),left(NULL),right(NULL){
    }
};
class Solution {
public:
    int Depth(TreeNode* pRoot){
        if(pRoot==nullptr){
            return 0;
        }
        if(pRoot!=nullptr && pRoot->left==nullptr && pRoot->right==nullptr){ //单个节点
            return 1;
        }
        return max(Depth(pRoot->left),Depth(pRoot->right)) +1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr){
            return true;
        }
        int letf_depth = Depth(pRoot->left);
        int right_depth = Depth(pRoot->right);
        if(abs(letf_depth - right_depth)>1){
            return false;
        }
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(4);
    cout<<Solution().IsBalanced_Solution(root);
    return 0;
}