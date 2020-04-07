class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    //用快慢指针/hashset求长度，这里用快慢指针
    public ListNode EntryNodeOfLoop(ListNode pHead)
    {
        ListNode fast =pHead,low=pHead;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            low = low.next;
            if(fast==low){
                break; //相遇点
            }
        }
        if(fast==null || fast.next==null){
            return null;//无环
        }
        low = pHead;
        //找相遇点
        while(low!=fast){
            low = low.next;
            fast = fast.next;
        }
        return fast;

    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode node1 = new ListNode(2);
        head.next = node1;
        ListNode rear = new ListNode(3);
        node1.next = rear;
        rear.next = node1;
        System.out.println(new Solution().EntryNodeOfLoop(head).val);
    }
}