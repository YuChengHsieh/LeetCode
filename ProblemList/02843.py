class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        for num in range(low,high+1):
            cur = num
            len_cur = len(str(num))
            if len_cur%2: continue
            cnt = 0; times = 0
            while cur != 0:
                if len_cur > 2*times: cnt += cur%10
                else: cnt -= cur%10
                cur //= 10
                times += 1
            if cnt == 0: ans += 1
        return ans
