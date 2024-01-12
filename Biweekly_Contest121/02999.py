class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        cnt = [0]*20
        def count(num: str):
            res = cnt[len(num)-1] # # of powerful integer in len(num)-1 digits
            size = len(num)-len(s)
            for i in range(size+1):
                res += num[i:] >= s if i == size else cnt[len(num)-i-1]*(min(limit,int(num[i])-1)+(i>0))
                if int(num[i]) > limit: 
                    break
             
            return res

        cnt[len(s)] = 1
        for i in range(len(s)+1,16):
            cnt[i] = (limit+1)*cnt[i-1]
        return count(str(finish)) - count(str(start-1))
