class MyStack {
    private int size;
    private int[] arr;
    private int top;

    public MyStack() {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    public void push(int x) {
        top++;
        arr[top] = x;
    }

    public int pop() {

        int x = arr[top];
        top--;
        return x;
    }

    public int top() {

        return arr[top];
    }

    public boolean empty() {
        return top == -1;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */