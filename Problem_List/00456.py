class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        # Monotonic Stack
        stack = []
        third = float('-inf')

        for num in nums[::-1]:
            if num < third: return True
            while stack and stack[-1] < num:
                third = stack.pop()
            stack.append(num)
        return False