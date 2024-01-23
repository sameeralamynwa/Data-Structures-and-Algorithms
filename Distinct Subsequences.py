class Solution:
    def numDistinct(self, source: str, target: str) -> int:
        memo = {}

        def helper(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            if j == len(target):
                result = 1
            elif i == len(source):
                result = 0
            elif source[i] == target[j]:
                include_current = helper(i + 1, j + 1)
                exclude_current = helper(i + 1, j)
                result = include_current + exclude_current
            else:
                result = helper(i + 1, j)

            memo[(i, j)] = result
            return result

        return helper(0, 0)
