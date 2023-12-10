class Solution:
    def minimumAddedCoins(self, coins: list[int], target: int) -> int:
        coins.sort()
        ans = 0
        max_reachable = 0

        for coin in coins:
            if max_reachable >= target: return ans

            while max_reachable+1 < coin:
                max_reachable += (max_reachable+1)
                ans += 1
                if max_reachable >= target: return ans
            
            max_reachable += coin
        
        while max_reachable < target:
            ans += 1
            max_reachable +=  (max_reachable+1)

        return ans