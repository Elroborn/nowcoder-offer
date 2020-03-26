


import java.util.ArrayList;
class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        ListNode head = listNode;
        ListNode new_head = new ListNode(-1);
        ListNode p = new ListNode(-1);
        while(head!=null){
            p = head;
            head = head.next;
            p.next = new_head.next ;
            new_head.next = p;
        }
        new_head = new_head.next;
        while(new_head!=null){
            
            res.add(new_head.val);
            new_head = new_head.next;
        }
        
        return res;
    }
    ArrayList<Integer> res2 = new ArrayList<Integer>();
    public ArrayList<Integer> printListFromTailToHead2(ListNode listNode) { //递归版本
        if(listNode!=null){
            this.printListFromTailToHead2(listNode.next);
            res2.add(listNode.val);
        }
        return res2;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode node = new ListNode(2);
        head.next = node;
        ListNode node2 = new ListNode(3);
        node.next = node2;
        System.out.println(new Solution().printListFromTailToHead2(head));

    }
}