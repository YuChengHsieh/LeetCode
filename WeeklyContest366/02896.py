class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        diff = [i for i in range(len(s1)) if s1[i] != s2[i]]
        if len(diff)%2 == 1: return -1
        if len(diff) == 0: return 0
        mem = {}
        def rec(idx):
            if idx == len(diff)-1: return x/2
            if idx == len(diff): return 0
            if idx in mem: return mem[idx]
            mem[idx] = min(rec(idx+2)+diff[idx+1]-diff[idx],
                            rec(idx+1)+x/2)
            return mem[idx]
        return int(rec(0))