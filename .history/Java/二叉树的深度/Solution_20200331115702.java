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
        if(root!=null && root.left==null && root.right==null){ //边界条件，并且递归到最后肯定可达这个条件
            return 1;
        }
        int left = TreeDepth(root.left);
        int right = TreeDepth(root.right);
        return max(left,right) +1;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
    }
}