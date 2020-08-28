/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    //利用两个栈，处理每一次push时的操作
    stack<int> s, helper;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {                 
        while(!s.empty()){
            helper.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!helper.empty()){
            s.push(helper.top());
            helper.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = s.top();
        s.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
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
// @lc code=end

