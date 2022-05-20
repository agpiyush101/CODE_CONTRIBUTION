/* LEETCODE 155         Min Stack


Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/

// supporting stack implementation in   O(n)
/*class MinStack {
public:
    stack<int>s;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size()==0 or ss.top()>=val)
            ss.push(val);
        
        
    }
    
    void pop() {
        if(s.size()==0)
            return;
        int ans=s.top();
        s.pop();
        if(ans==ss.top())
            ss.pop();
        
    }
    
    int top() {
        if(s.size()==0)
            return -1;
       int ans= s.top();
        return ans;
        
    }
    
    int getMin() {
        
        if(ss.size()==0)
            return -1;
        return ss.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//O(1) extra space implementation
/*
class MinStack {
public:
    stack<long> st;
long min;

MinStack() {
    
}

void push(int val) 
{
    if(st.empty())
    {
        st.push(val);
        min=val;
    }
    else if(val<=min)
    {
        st.push(2ll*val-min);
        min=val;
    }
    else
    {
        st.push(val);
    }
}

void pop() 
{
     if(st.empty()) 
         return;
    long t=st.top();
    if(t<min)
    {
        min=2ll*min-t;
    }
    st.pop();
}

int top() 
{
    
    if(st.empty())
        return -1;
    long t=st.top();
    if(t<min)
    {
        return min;
    }
    else 
        return t;
}

int getMin() 
{
    if(st.empty())
        return -1;
    else
    return min;
}
};

*/