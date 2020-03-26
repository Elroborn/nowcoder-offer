import java.util.Stack;
public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void push(int node) {
        stack1.push(node);

        // if(!stack1.full()){
            // stack1.push(node);
        // }else if(!stack2.full()){
        //     while(!stack1.empty()){
        //         stack2.push(stack1.pop());
        //     }
        //     stack1.push(node);
        // }else{
        //     System.out.println("队满");
        // }
    }
    
    public int pop() {
        if(stack1.empty() && stack2.empty()){
            throw new RuntimeException("Empty");
        }
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}