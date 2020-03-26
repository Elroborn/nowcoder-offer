
// 链接：https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?f=discussion
// 来源：牛客网

/*
*解题思路：
*1、遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
*2、重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
*3、拆分链表，将链表拆分为原链表和复制后的链表
*/

class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
public class Solution {
    public RandomListNode Clone(RandomListNode pHead)
    {
        if(pHead==null){
            return null;
        }
        RandomListNode curr = pHead;
        while(curr!=null){
            RandomListNode clone = new RandomListNode(curr.label);
            RandomListNode next = curr.next;
            clone.next = next;
            curr.next = clone;
            curr = next;
        }
        curr = pHead;
        while(curr!=null){
            curr.next.random = curr.random==null?null:curr.random.next;
            curr = curr.next.next;
        }
        RandomListNode cloneHead = pHead.next;
        curr = pHead;
        while(curr!=null){
            RandomListNode cloneNode = curr.next;
            curr.next = cloneNode.next;
            cloneNode.next = cloneNode.next==null?null:cloneNode.next.next;
            curr = curr.next;
        }
        return cloneHead;
    }
    public static void main(String[] args) {
        RandomListNode head = new RandomListNode(1);
        head.next = new RandomListNode(2);
        RandomListNode c = new Solution().Clone(head);
        System.out.println(c.label);
        System.out.println(c.next.label);

    }
}