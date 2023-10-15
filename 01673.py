class Solution:
    def mostCompetitive(self, nums: list[int], k: int) -> list[int]:
        # monotonic stack
        stack = []
        final_stack = []
        for i,num in enumerate(nums):
            while stack and num < stack[-1] and len(stack)+len(nums)-i > k:
                stack.pop()
            if len(stack) < k:
                stack.append(num)
        return stack