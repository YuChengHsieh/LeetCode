class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        nums_len = len(nums)
        start,end = 0,nums_len-1
        
        while start <= end:
            mid = start+(end-start)//2
            if nums[mid] == nums[start] == nums[end]: # o(n) can't judge in o(log(n))
                return True if target in set(nums[start:end+1]) else False 
            if target == nums[mid]:
                return True
            elif nums[mid] >= nums[start]: 
                if target < nums[mid] and target >= nums[start]:
                    end = mid-1
                else:
                    start = mid+1
            else:
                if target <= nums[end] and target > nums[mid]:
                    start = mid+1
                else:
                    end = mid-1
        return True if start+1 < nums_len and nums[start+1] == target else False

if __name__ == '__main__':
    a = Solution()
    # print(a.search([2,5,6,0,0,1,2],0))
    # print(a.search([2,5,6,0,0,1,2],3))
    # print(a.search([1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1],2))
    print(a.search([2,2,2,0,0,1],0))
            