class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        int l1=0,l2=0;
        ListNode head = pHead1;
        while(head){
            l1+=1;
            head = head.next;
        }
 
    }
}