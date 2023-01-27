# kadane's algorithm
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        global_max,cur_sum = -10000,0
        
        for num in nums:
            cur_sum = max(num,cur_sum+num)
            global_max = cur_sum if cur_sum > global_max else global_max
        
        return global_max

if __name__ == '__main__':
    a = Solution()
    print(a.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
    print(a.maxSubArray([1]))
    print(a.maxSubArray([5,4,-1,7,8]))