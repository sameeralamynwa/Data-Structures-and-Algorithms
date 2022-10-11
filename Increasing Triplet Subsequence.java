class Solution {
    public boolean increasingTriplet(int[] nums) {
        int firstNumber = Integer.MAX_VALUE, secondNumber = Integer.MAX_VALUE;
        for(int x : nums){
            if(x <= firstNumber){
                firstNumber = x;
            }
            else if(x <= secondNumber){
                secondNumber = x;
            }
            else{
                return true;
            }
        }
        return false;
    }
}
