class MyStack {
private:
    queue <int> queueStack;
        
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queueStack.push(x);
        for(int i = 0; i + 1 < (int) queueStack.size(); ++i){
            queueStack.push(queueStack.front());
            queueStack.pop();
        }
    }
    
    int pop() {
        int poppedElement = queueStack.front();
        queueStack.pop();
        return poppedElement;
    }
    
    int top() {
        return queueStack.front();
    }
    
    bool empty() {
        return queueStack.empty();
    }
};
