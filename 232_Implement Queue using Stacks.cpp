
class Queue {
public:
    stack<int> ans;
    stack<int> tmp;
    // Push element x to the back of queue.
    void push(int x) {
        tmp.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if ( ans.empty() )
            while ( !tmp.empty() ) {
                ans.push(tmp.top());
                tmp.pop();
            }
        ans.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if ( ans.empty() )
            while ( !tmp.empty() ) {
                ans.push(tmp.top());
                tmp.pop();
            }
        return ans.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return ans.empty() && tmp.empty() ? true : false;
    }
};