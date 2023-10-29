# 
from collections import defaultdict
class Solution:
    def numFactoredBinaryTrees(self, arr: list[int]) -> int:
        MOD = 1e9+7
        n = len(arr)
        arr.sort()
        dp = defaultdict(lambda:1)
        multiply_dict = defaultdict(list)
        for i in range(n):
            for j in range(i,n):
                multiply_dict[arr[i]*arr[j]].append((arr[i],arr[j]))

        for i in range(n):
            if arr[i] in multiply_dict:
                for sub1,sub2 in multiply_dict[arr[i]]:
                    if sub1 == sub2: dp[arr[i]] += int((dp[sub1]*(dp[sub1]+1)//2)%MOD + \
                    (dp[sub1]*(dp[sub1]-1)//2)%MOD)
                    else: dp[arr[i]] += int((dp[sub1]*dp[sub2]*2)%MOD)
            else: dp[arr[i]] = 1
        return int(sum(dp.values())%MOD)

class Solution:
    def numFactoredBinaryTrees(self, arr: list[int]) -> int:
        MOD = 10**9+7
        n = len(arr)
        arr.sort()
        arr_indexed = {arr[i]:i for i in range(n)}
        dp = [1]*n
        for i in range(n):
            for j in range(i):
                if arr[i]%arr[j] == 0:
                    ret = arr[i]//arr[j]
                    if ret in arr_indexed:
                        dp[i] += dp[j]*dp[arr_indexed[ret]]
                        dp[i] %= MOD
        return sum(dp)%MOD
