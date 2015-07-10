public class Solution {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public Solution() {
        // do initialization if necessary
        stack1 = new Stack<Integer>();
        stack2 = new Stack<Integer>();
    }

    public void push(int element) {
        // write your code here
        stack1.push(element);
    }

    public void helper() {
        while (!stack1.empty()) {
            stack2.push(stack1.peek());
            stack1.pop();
        }
    }

    public int pop() {
        // write your code here
        if (stack2.empty()) {
            helper();
        }
        return stack2.pop();
    }

    public int top() {
        // write your code here
        if (stack2.empty()) {
            helper();
        }
        return stack2.peek();
    }
}