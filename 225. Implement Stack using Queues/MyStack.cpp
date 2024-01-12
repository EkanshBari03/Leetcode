class MyStack
{
    int size;
    int *arr;
    int topp;

public:
    MyStack()
    {
        topp = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int x)
    {
        topp++;
        arr[topp] = x;
    }

    int pop()
    {
        int x = arr[topp];
        topp--;
        return x;
    }

    int top()
    {
        return arr[topp];
    }

    bool empty()
    {
        return topp == -1 ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */