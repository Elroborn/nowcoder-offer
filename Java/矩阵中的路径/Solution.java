public class Solution {
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
        boolean is_book[] = new boolean[matrix.length];//是否走过
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                //类似于走迷宫，只是迷宫出发点是0,0这里出发点是任意位置
                if(dfs(matrix,i,j,rows,cols,is_book,str,0)){
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[] matrix,int i,int j,int rows,int cols,boolean[] flag,char[]str,int k){
        int index = i*cols +j; //映射到matrix的位置
        // 边界条件
        if(i<0 || j<0 || i>=rows ||j>=cols || matrix[index]!=str[k]|| flag[index]==true){
            return false;
        }
        if(k==str.length-1){
            return true;
        }
        flag[index] =true;
        //遍历四个方向
        if(dfs(matrix, i-1, j, rows, cols, flag, str, k+1)|| 
        dfs(matrix,i+1, j, rows, cols, flag, str, k+1)||
        dfs(matrix, i, j-1, rows, cols, flag, str, k+1)||
        dfs(matrix, i, j+1, rows, cols, flag, str, k+1)){
            return true;
        }
        flag[index] = false;
        return false;
        
    }
    public static void main(String[] args) {
        char[] matrix = {'a','b','c','d'};
        char[] str = {'a','b','d'};
        System.out.println(new Solution().hasPath(matrix, 2, 2, str));
    }


}