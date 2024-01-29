class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {

        int res = 0;
        while (s1.size() > 1)
        {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        res = s1.top();
        s1.pop();
        while (s2.size() > 0)
        {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        int res = 0;
        while (s1.size() > 1)
        {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        res = s1.top();
        while (s2.size() > 0)
        {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.size() == 0 ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */