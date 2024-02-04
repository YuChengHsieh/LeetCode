class Solution:
    def getLastMoment(self, n: int, left: list[int], right: list[int]) -> int:
        return max(left) if len(right) == 0 else \
                n-min(right) if len(left) == 0 else \
                max(max(left),n-min(right))