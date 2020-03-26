class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        ListNode new_head = new ListNode(-1);
        ListNode r = new_head; //尾插法
        while(list1!=null && list2!=null){
            if(list1.val<list2.val){
                r.next = list1;
                r = list1;
                list1 = list1.next;
            }else{
                r.next = list2;
                r = list2;
                list2 = list2.next;
            }
        }
        list1 = list1!=null?list1:list2;
        while(list1!=null){
            r.next = list1;
            r = list1;
            list1 = list1.next;
        }
        r.next = null;
        return new_head.next;
    }
    public static void main(String[] args) {
        ListNode h1 = new ListNode(1);
        h1.next = new ListNode(4);
        h1.next.next = new ListNode(6);

        ListNode h2 = new ListNode(2);
        h2.next = new ListNode(3);
        // h2.next.next = new ListNode(5);

        ListNode r = new Solution().Merge(h1, h2);
        while(r!=null){
            System.out.println(r.val);
            r = r.next;
        }

    }
}