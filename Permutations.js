var permute = function(nums) {

    const allPermutations = []

    const backtrack = (currentPermutation) => {

        if(currentPermutation.length === nums.length){
            allPermutations.push(currentPermutation.slice());
            return;
        }
        
        for(const num of nums){
            if(currentPermutation.includes(num)){
                continue;
            }

            currentPermutation.push(num);
            backtrack(currentPermutation);
            currentPermutation.pop()
        }
    }

    backtrack([])
    return allPermutations;
};
