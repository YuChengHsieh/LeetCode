from collections import defaultdict
class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        dict_ = defaultdict(int)
        for num in nums:
            dict_[num] += 1
        
        ans = max(dict_[1] if dict_[1]%2 == 1 else dict_[1]-1,1)
        del dict_[1]
        visited = set()
        for key in sorted(dict_.keys()):
            if key in visited: continue
            tmp_cnt = 0
            while key in dict_:
                visited.add(key)
                if dict_[key] >= 2: 
                    tmp_cnt += 2
                    if tmp_cnt-1 > ans: ans = tmp_cnt-1
                elif dict_[key] == 1:
                    tmp_cnt += 1
                    if tmp_cnt > ans: ans = tmp_cnt
                    break
                key **= 2
        return ans