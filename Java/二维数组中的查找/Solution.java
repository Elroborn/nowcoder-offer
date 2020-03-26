public class Solution {
    public boolean Find(int target, int [][] array) {
        int hang = array.length;
        int lie = array[0].length;
        int row = 0;
        int col = lie -1;
        while(row<hang && col>=0){
            int value = array[row][col];
            if(target>value){
                row +=1;
            }
            else if(target<value){
                col-=1;
            }
            else{
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int [][] arr =  {{1,2,3}};
        System.out.print(new Solution().Find(3,arr));
    }
}