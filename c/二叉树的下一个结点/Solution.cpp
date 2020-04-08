#include<iostream>
using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr){
            return nullptr;
        }
        if(pNode->right!=nullptr){
            TreeLinkNode* t = pNode->right;
            while (t->left!=nullptr)
            {
                t = t->left;
            }
            return t;
        }
        while (pNode->next!=nullptr)
        {
            if(pNode->next->left==pNode){
                return pNode->next;
            }
            pNode = pNode->next;
        }
        return nullptr;
        
    }
};