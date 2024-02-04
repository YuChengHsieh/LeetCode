class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        mem = {}
        def rec(idx,k,prev,cnt):
            if k < 0: return float('inf')
            if idx >= len(s): return 0
            if (idx,k,prev,cnt) in mem: return mem[(idx,k,prev,cnt)]

            # delete one char
            result = rec(idx+1,k-1,prev,cnt)

            if s[idx] != prev:
                result = min(result, 1+rec(idx+1,k,s[idx],1))
            else:
                if cnt in [1,9,99]:
                    result = min(result,1+rec(idx+1,k,s[idx],cnt+1))
                else:
                    result = min(result,rec(idx+1,k,s[idx],cnt+1))
            mem[(idx,k,prev,cnt)] = result
            return mem[(idx,k,prev,cnt)] 

        return rec(0,k,' ',0)