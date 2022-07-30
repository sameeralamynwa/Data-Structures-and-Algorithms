class Solution {
    public void findSubsets(int index, int[] nums, List <List <Integer> > possibleSubsets, ArrayList <Integer> currentSubset){
        possibleSubsets.add(new ArrayList (currentSubset));
        for(int next = index; next < nums.length; ++next){
            if(next > index && nums[next] == nums[next - 1]){
                continue;
            }
            currentSubset.add(nums[next]);
            findSubsets(next + 1, nums, possibleSubsets, currentSubset);
            currentSubset.remove(currentSubset.size() - 1);
        }
    }
    
    public List <List <Integer> > subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List <List <Integer> > possibleSubsets = new ArrayList <>();
        ArrayList <Integer> currentSubset = new ArrayList <>();
        findSubsets(0, nums, possibleSubsets, currentSubset);
        return possibleSubsets;
    }
}
