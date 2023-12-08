class Solution {
    public int longestValidParentheses(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        Stack<Integer> stack = new Stack<>();
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (!stack.isEmpty() && s.charAt(stack.peek()) == '(') {
                    stack.pop();
                    if (!stack.isEmpty()) {
                        maxLength = Math.max(maxLength, i - stack.peek());
                    } else {
                        maxLength = Math.max(maxLength, i + 1);
                    }
                } else {
                    stack.push(i);
                }
            }
        }
        
        return maxLength;
    }
}
