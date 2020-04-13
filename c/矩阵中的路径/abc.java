import java.util.ArrayList;
public class abc{
    static ArrayList<ArrayList<Integer>>res = new ArrayList<ArrayList<Integer>>();

    public void dfs(int n,int i,boolean[] flag,int k,ArrayList<Integer>tmp){
        if(i<n && flag[i]==true){
            return;
        }
        if(k==n-1){
            res.add((ArrayList<Integer>) tmp.clone());
            return;
        }
        for(int j=0;j<n;j++){
            flag[j] = true;
            tmp.add(j);
            dfs(n,j+1, flag, k+1, tmp);
            tmp.remove(new Integer(j));
            flag[j] = false;
        }

    }

    public static void main(String[] args) {
        int n = 3;
        boolean book[]  = new boolean[3];
        ArrayList<Integer>tmp = new ArrayList<>();
        new abc().dfs(3,0, book, 0, tmp);
        System.out.println(res);
        
    }
}