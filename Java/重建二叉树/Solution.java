class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
public class Solution {
    // static TreeNode root = new TreeNode(-1);
    public TreeNode reConstructBinaryTree(int [] pre,int l1,int r1,int [] in,int l2,int r2){
        if(l1>r1 || l2>r2){
            return null;
        }        
        TreeNode root = new TreeNode(pre[l1]); //根
        for(int i=l2;i<=r2;i++){
            if(in[i]==pre[l1]){
                root.left = reConstructBinaryTree(pre, l1+1, l1+(i-l2), in, l2, i-1);
                root.right = reConstructBinaryTree(pre, l1+(i-l2)+1, r1, in, i+1, r2);
                break;
            }
        }
        return root;
    }
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        TreeNode root = reConstructBinaryTree(pre, 0, pre.length-1, in, 0, in.length-1);
        return root;
    }
    public static void show_tree(TreeNode root){
        if(root!=null){
            System.out.println(root.val);
            show_tree(root.left);
            show_tree(root.right);
        }
    }
    public static void main(String[] args) {
        int pre[] = {1,2,4,7,3,5,6,8};
        int in[] =  {4,7,2,1,5,3,8,6};
        TreeNode root = new Solution().reConstructBinaryTree(pre,in);
        show_tree(root);
    }
}