class MinStack {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        st1.push(number);
        if (st2.empty()) {
            st2.push(number);
        } else {
            if (number <= st2.top()) {
                st2.push(number);
            } else {
                st2.push(this.min())
            }
        }
    }

    int pop() {
        int cnt = st1.top();
        st1.pop();
        st2.pop();
        return cnt;
        // write your code here
    }

    int min() {
        return st2.top();
        // write your code here
    }
};
