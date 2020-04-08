

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr || pHead->next==nullptr){
            return pHead;
        }
        ListNode* Head = new ListNode(0);
        Head->next = pHead;
        ListNode* pre = Head;
        ListNode* last = pre->next;
        while(last!=nullptr){
            if(last->next!=nullptr && last->next->val == last->val){
                while(last->next!=nullptr && last->next->val == last->val){// 是重复结点
                    last = last->next;
                }
                //说明找到了不同的那个
                pre->next = last->next;//暂时插入，还需要判断last->next是否是重复
                last = last->next;
            }else{ //非重复，直接插入
                pre = last;
                last = last->next;
            }
        }
        return Head->next;
    }
};
int main(){
    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(2);
    pHead = Solution().deleteDuplication(pHead);
    while(pHead!=nullptr){
        cout<<pHead->val;
        pHead = pHead->next;
    }

    return 0;
}