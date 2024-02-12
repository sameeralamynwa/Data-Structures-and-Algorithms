class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        current_index = 0

        while current_index < n:
            if nums[current_index] != current_index + 1:
                correct_index = nums[current_index] - 1
                if nums[correct_index] != nums[current_index]:
                    nums[correct_index], nums[current_index] = nums[current_index], nums[correct_index]
                else:
                    return nums[current_index]
            else:
                current_index += 1
