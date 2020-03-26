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
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
		ArrayList<Integer> res = new  ArrayList<Integer>();
		ArrayList<TreeNode> queue = new ArrayList<TreeNode>();
		if(root==null){
			return res;
		}else{
			queue.add(root);
		}
		while(!queue.isEmpty()){
			TreeNode t = queue.get(0);
			res.add(t.val);
			if(t.left!=null){
				queue.add(t.left);
			}
			if(t.right!=null){
				queue.add(t.right);
			}
			queue.remove(0);
		}
		return res;
        
	}
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.right.left = new TreeNode(4);
		ArrayList<Integer> res = new Solution().PrintFromTopToBottom(root);
		System.out.println(res);
		
	}
}