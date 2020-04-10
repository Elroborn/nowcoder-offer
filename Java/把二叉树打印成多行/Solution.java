import java.util.ArrayList;
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer> >  res = new  ArrayList<ArrayList<Integer> > ();
        if(pRoot==null){
            return res;
        }
        ArrayList<TreeNode> queue = new ArrayList<>();
        queue.add(pRoot);
        while(!queue.isEmpty()){
            int size = queue.size();
            ArrayList<Integer> t = new ArrayList<>();
            for(int i=0;i<size;i++){
                System.out.println(queue);
                TreeNode tmp = queue.get(0);
                queue.remove(0);
                if(tmp.left!=null){
                    queue.add(tmp.left);
                }
                if(tmp.right!=null){
                    queue.add(tmp.right);
                }
                t.add(tmp.val);
            }
            if(t.size()>0){
                res.add(t);
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