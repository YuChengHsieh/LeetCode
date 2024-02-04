# o(n) every node just go through one time
class Solution:
    def countVisitedNodes(self, edges: list[int]) -> list[int]:
        n = len(edges)
        self.visited = set()
        ans = [0]*n
        
        def rec(idx):
            if ans[idx] != 0: return idx
            if idx in self.dict: return idx
            self.dict[idx] = self.cnt
            self.dict[-self.cnt] = idx
            self.cnt += 1
            return rec(edges[idx])
        
        for i in range(n):
            if ans[i] != 0: continue
            self.dict = {}; self.cnt = 1
            final_idx = rec(i)
            # first scearnio             
            if final_idx in self.dict:
                val = self.cnt-self.dict[final_idx]
                for i in range(self.dict[final_idx],self.cnt):
                    ans[self.dict[-i]] = val
                
                cnt = 1
                for i in range(self.dict[final_idx]-1,0,-1):
                    ans[self.dict[-i]] = val+cnt
                    cnt += 1
                
            else:
                cnt = 1
                for i in range(self.cnt-1,0,-1):
                    ans[self.dict[-i]] += ans[final_idx]+cnt
                    cnt += 1
        return ans
            
        
        