var minimizeMax = function minimizeMaxDifference(nums, p) {
    nums.sort((a, b) => a - b);
    
    let minMaxDifference = 0;
    let left = 0, right = nums[nums.length - 1] - nums[0];
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (canFormPairsWithinMaxDifference(nums, mid, p)) {
            minMaxDifference = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return minMaxDifference;
}

function canFormPairsWithinMaxDifference(nums, maxDiff, pairCount) {
    let formedPairs = 0;
    for (let index = 0; index < nums.length - 1 && formedPairs < pairCount;) {
        if (nums[index + 1] - nums[index] <= maxDiff) {
            formedPairs++;
            index += 2;
        } else {
            index++;
        }
    }
    return formedPairs >= pairCount;
}
