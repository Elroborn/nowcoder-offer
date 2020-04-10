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
            vector<vector<int> > res ;
            if(pRoot==nullptr){
                return res;
            }
            vector<TreeNode*> queue;
            queue.push_back(pRoot);
            while(!queue.empty()){
                int size = queue.size();
                vector<int>t;
                for(int i=0;i<size;i++){
                    TreeNode* tmp = queue.front();
                    queue.erase(queue.begin());
                    if(tmp->left){
                        queue.push_back(tmp->left);
                    }
                    if(tmp->right){
                        queue.push_back(tmp->right);
                    }
                    t.push_back(tmp->val);
                }
                if(t.size()){
                    res.push_back(t);
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

    return  0;

}