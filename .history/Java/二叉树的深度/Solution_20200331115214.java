class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    public void Mirror_node(TreeNode root){//以root为根，左右交换
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
    }
    public void Mirror(TreeNode root) { //树镜像
        if(root!=null){
            Mirror_node(root);
            Mirror(root.left);
            Mirror(root.right);

        }
        
    }
    public void show_tree(TreeNode root){
        if(root!=null){
            System.out.println(root.val);
            show_tree(root.left);
            show_tree(root.right);
        }
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(5);
        new Solution().Mirror(root);
        new Solution().show_tree(root);
    }
}