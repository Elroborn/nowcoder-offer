class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    public int TreeDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        if(root!=null && root.left==null && root.right==null){ //边界条件
            return 1;
        }
    }
}