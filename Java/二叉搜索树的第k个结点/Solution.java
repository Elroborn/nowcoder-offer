
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    TreeNode res;
    int index = 0;
    void In_order(TreeNode pRoot,int k){
        if(pRoot==null){
            return ;
        }
        In_order(pRoot.left, k);
        index+=1;
        if(index==k){
            res = pRoot;
        }
        In_order(pRoot.right, k);
    }
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        In_order(pRoot, k);
        return res;
    }
    public static void main(String[] args) {
        TreeNode pRoot = new TreeNode(5);
        pRoot.left = new TreeNode(3);
        pRoot.right = new TreeNode(7);
        System.out.println(new Solution().KthNode(pRoot, 2));
    }

}