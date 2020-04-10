class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
public class Solution {
	int index = -1;
	StringBuilder sb = new StringBuilder();

    String Serialize(TreeNode root) {
		// StringBuilder sb = new StringBuilder();
		if(root==null){
			sb.append("#,");
			return sb.toString();
		}
		sb.append(root.val+",");
		// sb.append(Serialize(root.left));
		// sb.append(Serialize(root.right));
		Serialize(root.left);
		Serialize(root.right);
		return sb.toString();
        
  }
    TreeNode Deserialize(String str) {
		String[] sstr = str.split(",");
		return Deserialize(sstr);

	}
    TreeNode Deserialize(String[] str) {
		index+=1;
		if(str[index].equals("#")){
			return null;
		}

		TreeNode node = new TreeNode(Integer.valueOf(str[index]));
		node.left = Deserialize(str);
		node.right = Deserialize(str);
		return node;
		
	}
  public static void main(String[] args) {
	  TreeNode root = new TreeNode(1);
	  root.left = new TreeNode(2);
	  String s = new Solution().Serialize(root);
	  System.out.println(s);
	//   root = new Solution().Deserialize(s);
	//   System.out.println(root.left.val);
  }
}