class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) { //不好
        if(head==null || k<=0){
            return null;
        }
        int count = 0; //count代表p和q之间的距离
        ListNode p = head,q = head;
        while(p!=null){
            p = p.next;
            if(count>=k){
                q = q.next;
            }
            count++;
        }
        if(count<k){
            return null;
        }else{
            return q;
        }

    }
    public ListNode FindKthToTail2(ListNode head,int k) { //一个先走，然后两个一起走
        if(head==null || k<=0){
            return null;
        }
        ListNode p = head,q = head; 
        while(k>1){ //p先走一步 需要走k-1步
            if(p.next!=null){
                p = p.next;
                k--;
            }else{
                return null;// 出现{1,2} 3这种情况
            }
        }
        //剩下的路一起走
        while(p.next!=null){
            p = p.next;
            q = q.next;
        }
        return q;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        System.out.println(new Solution().FindKthToTail(head, 4).val);
    }
}