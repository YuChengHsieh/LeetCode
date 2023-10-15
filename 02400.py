class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        mem = {}
        MOD = 1e9+7
        start_pos = min(startPos,endPos)
        end_pos = max(startPos,endPos)
        def rec(pos,step):
            if step == 0: 
                return 1 if pos == end_pos else 0
            if pos < start_pos-k//2 or pos > end_pos+k//2: return 0
            if (pos,step) in mem: return mem[(pos,step)]
            cnt1 = rec(pos-1,step-1)%MOD
            cnt2 = rec(pos+1,step-1)%MOD
            mem[(pos,step)] = (cnt1+cnt2)%MOD
            return mem[(pos,step)]
        return int(rec(start_pos,k))
