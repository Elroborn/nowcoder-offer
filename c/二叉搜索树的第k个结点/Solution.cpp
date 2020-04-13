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
    TreeNode* res;
    int index = 0;
    void In_order(TreeNode* pRoot,int k){
        if(pRoot==nullptr){
            return;
        }
        In_order(pRoot->left,k);
        index+=1;
        if(index==k){
            res = pRoot;
        }
        In_order(pRoot->right,k);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        In_order(pRoot,k);
        return res;
    }

};

int main(){
    TreeNode* pRoot = new TreeNode(5);
    pRoot->left = new TreeNode(3);
    pRoot->right = new TreeNode(7);
    cout<<Solution().KthNode(pRoot,4);
    return 0;
}