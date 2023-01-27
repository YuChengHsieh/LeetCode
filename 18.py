class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        ans_list = []
        nums.sort()
        check_dict = {}
        num_len = len(nums)
        
        for i in range(num_len):
            for j in range(i+1,num_len):
                left = j+1
                right = num_len - 1
                
                while left < right:
                    sum_ = nums[i]+nums[j]+nums[left]+nums[right]
                    if sum_ > target:
                        right -= 1
                    elif sum_ < target:
                        left += 1
                    else:
                        if check_dict.get(tuple([nums[i],nums[j],nums[left],nums[right]])) is None:
                            ans_list.append([nums[i],nums[j],nums[left],nums[right]])
                            check_dict[tuple([nums[i],nums[j],nums[left],nums[right]])] = 1
                        left += 1
                        right -= 1

        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.fourSum([1,0,-1,0,-2,2],0))
    print(a.fourSum([2,2,2,2,2],8))
            