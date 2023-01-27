class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        # prefix sum
        max_ = 0
        cur = 0
        for i in gain:
            cur += i
            if cur > max_:
                max_ = cur

        return max_