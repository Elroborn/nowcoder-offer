import java.util.ArrayList;
import java.util.Stack;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> > res = new ArrayList<ArrayList<Integer> >();
        if(pRoot==null){
            return res;
        }
        Stack<TreeNode>s1 = new Stack<TreeNode>(); //奇数行
        Stack<TreeNode>s2 = new Stack<TreeNode>();//偶数行
        s1.add(pRoot);
        while(!s1.isEmpty() || !s2.isEmpty()){
            ArrayList<Integer>tmp1 = new ArrayList<>();
            ArrayList<Integer>tmp2 = new ArrayList<>();
            while(!s1.isEmpty()){
                TreeNode t = s1.pop();
                if(t.left!=null){ //s2 是偶数行，遍历应从右到左，而栈是逆序，所以从左到右
                    s2.push(t.left);
                }
                if(t.right!=null){
                    s2.push(t.right);
                }
                tmp1.add(t.val);
            }
            if(tmp1.size()>0){
                res.add(tmp1);
            }
            while(!s2.isEmpty()){
                TreeNode t = s2.pop();
                if(t.right!=null){
                    s1.push(t.right);
                }
                if(t.left!=null){
                    s1.push(t.left);
                }
                tmp2.add(t.val);
            }
            if(tmp2.size()>0){
                res.add(tmp2);
            }

        }
        return res;
    }
    public static void main(String[] args) {
        TreeNode pRoot = new TreeNode(1);
        pRoot.left = new TreeNode(2);
        pRoot.right = new TreeNode(3);
        System.out.println(new Solution().Print(pRoot));
    }
}