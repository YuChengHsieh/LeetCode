class Solution:
    def findSubsequences(self, nums: list[int]) -> list[list[int]]:
        self.ans_list = []
        self.nums = nums
        self.check_dict = {}
        self.rec(0,[])
        return self.ans_list
    
    def rec(self,idx,num_list):
        if len(num_list) >= 2:
            # valid
            if self.check_dict.get(tuple(num_list)) is None:
                self.ans_list.append(num_list.copy())
                self.check_dict[tuple(num_list)] = 1
            
        for i in range(idx,len(self.nums)):
            if len(num_list) == 0 or self.nums[i] -  num_list[-1] >= 0: # check if it is non-decreasing
                num_list.append(self.nums[i])
                self.rec(i+1,num_list)
                num_list.pop()
    
        return 

if __name__ == '__main__':
    a = Solution()
    print(a.findSubsequences([4,6,7,7]))
    print(a.findSubsequences([4,4,3,2,1]))