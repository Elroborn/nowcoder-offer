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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(pRoot ==nullptr){
                return res;
            }
            vector<TreeNode*> v1; //奇数行
            vector<TreeNode*> v2;// 偶数行
            v1.push_back(pRoot);
            while(!v1.empty()|| !v2.empty()){
                vector<int>t1,t2;
                while(!v1.empty()){
                    TreeNode* t = v1.back();
                    v1.pop_back();
                    if(t->left){
                        v2.push_back(t->left);
                    }
                    if(t->right){
                        v2.push_back(t->right);
                    }
                    t1.push_back(t->val);
                }
                if(t1.size()){
                    res.push_back(t1);
                }

                while(!v2.empty()){
                    TreeNode* t = v2.back();
                    v2.pop_back();
                    if(t->right){
                        v1.push_back(t->right);
                    }
                    if(t->left){
                        v1.push_back(t->left);
                    }
               
                    t2.push_back(t->val);
                }
                if(t2.size()){
                    res.push_back(t2);
                }
            }
            return res;
        }
        
    };
    int main(){
        TreeNode* pRoot = new TreeNode(1);
        pRoot->left = new TreeNode(2);
        pRoot->right = new TreeNode(3);
        vector<vector<int> > res = Solution().Print(pRoot);
        cout<<res.size();

        return 0;
    }