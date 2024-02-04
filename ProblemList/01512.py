from collections import defaultdict
class Solution:
    def numIdenticalPairs(self, nums: list[int]) -> int:
        pair = defaultdict(int)
        cnt = 0
        for num in nums:
            cnt += pair[num]
            pair[num] += 1
        return cnt 