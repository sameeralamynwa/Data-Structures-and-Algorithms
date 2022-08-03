class MyQueue {
    Stack <Integer> stackQueue, anotherStackQueue;
    
    public MyQueue() {
        stackQueue = new Stack <>();
        anotherStackQueue = new Stack <>();
    }
    
    public void push(int x) {
        while(stackQueue.empty() == false){
            anotherStackQueue.push(stackQueue.pop());
        }
        anotherStackQueue.push(x);
        while(anotherStackQueue.empty() == false){
            stackQueue.push(anotherStackQueue.pop());
        }
    }
    
    public int pop() {
        return stackQueue.pop();
    }
    
    public int peek() {
        return stackQueue.peek();
    }
    
    public boolean empty() {
        return stackQueue.empty();
    }
}
