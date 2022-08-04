class Maths {
    static int min(int x, int y){
        return x < y ? x : y;
    }
}

class MinStack {
    Stack <Pair <Integer, Integer> > stack;
    
    public MinStack() {
        stack = new Stack <>();
    }
    
    public void push(int val) {
        if(stack.empty()){
            stack.push(new Pair(val, val));
        }
        else{
            stack.push(new Pair(val, Maths.min(stack.peek().getValue(), val)));
        }
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().getKey();
    }
    
    public int getMin() {
        return stack.peek().getValue();
    }
}
