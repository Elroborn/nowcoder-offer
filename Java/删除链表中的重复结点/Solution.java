class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode deleteDuplication(ListNode pHead)
    {
        if(pHead==null || pHead.next==null){
            return pHead;
        }
        ListNode new_head = new ListNode(0);
        new_head.next = pHead;
        ListNode pre = new_head;
        ListNode last = pre.next;
        while(last!=null){
            if(last.next!=null && last.next.val == last.val){ //说明last重复
                while(last.next!=null && last.next.val == last.val){
                    last = last.next;
                }
                pre.next = last.next;
                last = last.next;
            }else{
                pre = last;
                last = last.next;
            }

        }
        return new_head.next;
    }
    public static void main(String[] args) {
        ListNode pHead = new ListNode(1);
        pHead.next = new ListNode(2);
        pHead.next.next = new ListNode(2);
        pHead = new Solution().deleteDuplication(pHead);
        while(pHead!=null){
            System.out.println(pHead.val);
            pHead = pHead.next;
        }
    }
}