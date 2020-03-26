class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    //root2 是否是以root1为根的子树
    public boolean IsSubtree(TreeNode root1,TreeNode root2){
        if(root2==null){// 成功遍历，root2则是
            return true;
        }
        if(root1==null){//root2还有，而root1遍历完了 则不是
            return false;
        }
        if(root1.val!=root2.val){ //根
            return false;
        }
        return IsSubtree(root1.left, root2.left) && IsSubtree(root1.right, root2.right); //左右
    }
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
     
        if(root1!=null && root2!=null){
            if(IsSubtree(root1, root2)){//根
                return true;
            }
            return IsSubtree(root1.left, root2) || IsSubtree(root1.right, root2);//左右
        }else{
            return false;
        }
    }

    public static void main(String[] args) {
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        root1.right.left = new TreeNode(3);
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        // root2.right.right = new TreeNode(3);

        System.out.println(new Solution().HasSubtree(null, root2));
    }
}