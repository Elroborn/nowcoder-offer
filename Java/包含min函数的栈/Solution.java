import java.util.Stack;

public class Solution {
    Stack<Integer> stack = new Stack<Integer>();
    Stack<Integer> min_stack = new Stack<Integer>();
    int min= Integer.MAX_VALUE;
    public void push(int node) {
        stack.push(node);
        if(node<=min){
            min_stack.push(node);
            min = node;
        }else{
            min_stack.push(min);
        }
    }
    
    public void pop() {
        stack.pop();
        min_stack.pop();
        min = min_stack.peek();
    }
    
    public int top() {
        return stack.firstElement();
    }
    
    public int min() {
        return min;
        
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        s.push(3);
        s.push(5);
        s.push(2);
        s.pop();
        System.out.println(s.min());
    }
}