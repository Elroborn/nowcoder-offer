import java.util.ArrayList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
//可用递归，边界条件是left==null && right=null 以及left==null|| right==null
//递归为 left.val==right.vall && sym(left.left,left.right) && sym(right.left,right.right)
//这里用非递归，树的层次遍历即可
public class Solution {
    boolean isSymmetrical(TreeNode left,TreeNode right){
        if(left==null && right==null){
            return true;
        }
        if(left==null || right==null){
            return false;
        }
        return left.val==right.val && isSymmetrical(left.left, right.right) && isSymmetrical(left.right, right.left);

    }
    boolean isSymmetrical(TreeNode pRoot){
        if(pRoot==null){
            return true;
        }
        return isSymmetrical(pRoot.left, pRoot.right);
    }
    boolean isSymmetrical1(TreeNode pRoot)
    {
        if(pRoot==null){
            return true;
        }
        ArrayList<TreeNode> q = new ArrayList<>();
        q.add(pRoot.left);
        q.add(pRoot.right); //按对进入
        while(!q.isEmpty()){
            System.out.println(q.size());
            TreeNode left = q.get(0);
            TreeNode right = q.get(1);
            q.remove(0);
            q.remove(0);
            if(left==null && right==null){
                continue;
            }
            if(left==null || right==null){
                return false;
            }
            if(left.val!=right.val){
                return false;
            }
            q.add(left.left); //注意这个地方，成对插入（镜像）
            q.add(right.right);
            q.add(left.right);
            q.add(right.left);
        }
        return true;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        System.out.println(new Solution().isSymmetrical(root));
      
    }
}