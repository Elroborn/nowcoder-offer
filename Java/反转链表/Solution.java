class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head==null || head.next==null){
            return head;
        }
        ListNode new_head = new ListNode(-1);
        ListNode p = null;
        while(head!=null){
            p = head;
            head = head.next;
            //尾插法
            p.next = new_head.next;
            new_head.next = p; 
        }
        return new_head.next;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        ListNode r = new Solution().ReverseList(head);
        while(r!=null){
            System.out.println(r.val);
            r = r.next;
        }
    }
}