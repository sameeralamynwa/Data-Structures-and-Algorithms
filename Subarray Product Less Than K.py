class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        
        count = 0
        product = 1
        left_ptr = 0
        
        for right_ptr in range(len(nums)):
            product *= nums[right_ptr]
            while product >= k:
                product /= nums[left_ptr]
                left_ptr += 1
            count += right_ptr - left_ptr + 1
        
        return count
