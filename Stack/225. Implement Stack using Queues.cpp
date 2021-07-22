class MyStack
{
public:
    queue<int> q1;
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        int n = q1.size();
        for (int i = 0; i < n - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (!q1.empty())
        {
            int popped = top();
            q1.pop();
            return popped;
        }
        else
            return -1;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
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