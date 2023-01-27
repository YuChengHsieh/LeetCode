class Solution:
    # Coin change problem
    def maximumRequests(self, n: int, requests: list[list[int]]) -> int:
        self.ans = 0
        def rec(cur,in_and_out,cnt):
            if cur == len(requests):
                for i in in_and_out:
                    if i != 0:
                        return
                self.ans = max(cnt,self.ans)
                return
            in_and_out[requests[cur][0]] -= 1
            in_and_out[requests[cur][1]] += 1
            rec(cur+1,in_and_out,cnt+1)
            in_and_out[requests[cur][0]] += 1
            in_and_out[requests[cur][1]] -= 1

            rec(cur+1,in_and_out,cnt)
            return
        
        rec(0,[0 for _ in range(n)],0)
        return self.ans