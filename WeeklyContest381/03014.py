from collections import defaultdict
class Solution:
    def minimumPushes(self, word: str) -> int:
        dict_a = defaultdict(int)
        dict_b = defaultdict(int)
        
        max_cnt = 0
        for ch in word:
            dict_a[ch] += 1
            if dict_a[ch] > max_cnt: max_cnt = dict_a[ch]
        
        for val in dict_a.values():
            dict_b[val] += 1
        
        cnt = 0; ans = 0; times = 1
        for i in range(max_cnt,-1,-1):
            while dict_b[i] != 0:
                cnt += 1
                ans += i*times
                if cnt%8 == 0: times += 1
                dict_b[i] -= 1
                # print(cnt,ans)
        
        return ans