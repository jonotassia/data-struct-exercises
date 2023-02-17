#include <stack>

using std::stack;

class MyQueue {
public:
    stack<int> first;
    stack<int> second;
    
    MyQueue() {

    }

    
    void push(int x) {
        if (first.size() == 0 && second.size() == 0) {
            first.push(x);
        }
        else if (first.size() == 0) {
            second.push(x);
        }
        else {
            first.push(x);
        }
        
    }
    
    int pop() {
        int next;
        
        if (first.size() > 0) {
            while (first.size() > 0) {
                second.push(first.top());
                first.pop();
            }
            second.pop();
            next = second.top();
            return next;
        }

        else if (second.size() > 0) {
            while (second.size() > 0) {
                first.push(second.top());
                second.pop();
            }
            first.pop();
            next = first.top();
            return next;
        }

        return 0;
    }
    
    int peek() {
        int next;
        
        if (first.size() > 0) {
            while (first.size() > 0) {
                second.push(first.top());
                first.pop();
            }
            next = second.top();
            return next;
        }

        else if (second.size() > 0) {
            while (second.size() > 0) {
                first.push(second.top());
                second.pop();
            }
            next = first.top();
            return next;
        }

        return 0;
    }
    
    bool empty() {
        if (first.size() == 0 && second.size() == 0) {
            return true;
        } else {
            return false;
        }
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