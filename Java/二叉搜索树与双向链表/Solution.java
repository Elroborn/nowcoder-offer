// 中序遍历即可。只需要记录一个pre指针即可。
// 高分答案也太绕了吧

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    TreeNode pre = null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree==null){
            return null;
        }
        Inorder(pRootOfTree);
        TreeNode res = pRootOfTree;
        
        while(res.left!=null){
            res = res.left;
        }
        return res;
        
    }
    private void Inorder(TreeNode root){ //pre是为了做双向链表记录左值
        if(root==null){
            return;
        }
        Inorder(root.left);
        root.left = pre;
        if(pre!=null){
            pre.right = root;
        }
        pre = root;
        Inorder(root.right);

    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        TreeNode res = new Solution().Convert(root);
        System.out.println(res.val);
    }
}