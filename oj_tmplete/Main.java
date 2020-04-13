import java.util.Scanner;
public class Main {
    public String delete(String str){
        int a[] = new int[26];
        int size = str.length();
        String s = "";
        for(int i=0;i<size;i++){
            if(a[str.charAt(i)-'a']==0){ //未重复
             a[str.charAt(i)-'a']+=1;
             s+=str.charAt(i);
            }
            else{ //重复
             a[str.charAt(i)-'a']+=1;
            }
        }
        return s;
 
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {//注意while处理多个case
            // int a = in.nextInt();              
            String s = in.nextLine();
            System.out.println(new Main().delete(s));
        }
    }
}
