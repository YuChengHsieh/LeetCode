class Solution:
    def minimizeMax(self, nums: list[int], p: int) -> int:
        nums.sort()
        def valid(val):
            i = 0; count = 0
            while i < len(nums)-1 and count < p:
                if nums[i+1]-nums[i] <= val:
                    count += 1
                    i += 2
                else:
                    i += 1

            return count >= p

        start = 0; end = nums[-1]-nums[0]

        while start <= end:
            mid = start + (end-start)//2
            if valid(mid):
                end = mid-1
            else:
                start = mid+1
        
        return start 