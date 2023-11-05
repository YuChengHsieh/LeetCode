class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        ans = []

        def rec(tmp_ans,total,idx):
            if len(tmp_ans) == k and total == n:
                ans.append(tmp_ans.copy())
                return 
            elif len(tmp_ans) > k or total > n:
                return

            for i in range(idx,10):
                rec(tmp_ans+[i],total+i,i+1)
            return
        rec([],0,1)
        return ans