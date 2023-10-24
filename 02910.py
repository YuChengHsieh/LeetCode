from collections import defaultdict
class Solution:
    def minGroupsForValidAssignment(self, nums: list[int]) -> int:
        # o(n) or o(nlogn)
        cnt_dict = defaultdict(int)
        for num in nums:
            cnt_dict[num] += 1

        cnt_list = []
        for i in cnt_dict.values():
            cnt_list.append(i)

        def search(min_num):
            ans = 0
            for num in cnt_list:
                # No way to form viable split
                if num%min_num > num//min_num: return 0
                ans += (num-1)//(min_num+1)+1
            return ans
        
        left,right = 1,min(cnt_list)
        ans = float('inf')
        # search that the which group len minimum will have minimum number of groups
        for i in range(left,right+1):
            ret = search(i)
            if ret:
                ans = min(ans,ret)
        return ans

 