
// 链接：https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e?f=discussion
// 来源：牛客网

// 结合图，我们可发现分成两大类：1、有右子树的，那么下个结点就是右子树最左边的点；（eg：D，B，E，A，C，G） 
// 2、没有右子树的，也可以分成两类，a)是父节点左孩子（eg：N，I，L） ，那么父节点就是下一个节点 ； 
// b)是父节点的右孩子（eg：H，J，K，M）
// 找他的父节点的父节点的父节点...直到当前结点是其父节点的左孩子位置。如果没有eg：M，那么他就是尾节点。
class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        if(pNode==null){
            return null;
        }
        if(pNode.right!=null){
            //右子树的最左结点
            TreeLinkNode t = pNode.right;
            while(t.left!=null){
                t = t.left;
            }
            return t;
        }
        //无右子树，则看父节点，使得当前点是父节点的左儿子
        while(pNode.next!=null){
            if(pNode.next.left==pNode){
                return pNode.next;
            }
            pNode = pNode.next;
        }
        return null;
    }
    public static void main(String[] args) {
        TreeLinkNode root = new TreeLinkNode(1);
        root.right = new TreeLinkNode(2);
        System.out.println(new Solution().GetNext(root).val);
    }
}