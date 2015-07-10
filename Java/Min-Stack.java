public class Solution {
    private Stack<Integer> stk1;
    private Stack<Integer> stk2;
    public Solution() {
        // do initialize if necessary
        stk1 = new Stack<Integer>();
        stk2 = new Stack<Integer>();
    }

    public void push(int number) {
        // write your code here
        stk1.push(number);
        if (stk2.empty() || number <= min()) {
            stk2.push(number);
        } else {
            stk2.push(min());
        }
    }

    public int pop() {
        // write your code here
        stk2.pop();
        return stk1.pop();
    }

    public int min() {
        // write your code here
        return stk2.peek();
    }
}

