class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        # Coin change problem
        self.candidates = candidates
        self.target = target
        self.ans_list = []
        self.rec(0,0,[])
        return self.ans_list
    
    def rec(self,current_sum:int, current_idx:int, ans_list:list[int]):
        if current_sum == self.target:
            self.ans_list.append(ans_list.copy())
            return
        elif current_sum > self.target or current_idx >= len(self.candidates):
            return
        else: # current_sum < target
            val = self.candidates[current_idx]
            ans_list.append(val)
            self.rec(current_sum+val,current_idx,ans_list)
            ans_list.pop()
            self.rec(current_sum,current_idx+1,ans_list)

if __name__ == '__main__':
    a = Solution()
    print(a.combinationSum([2,3,6,7],7))
    print(a.combinationSum([2,3,5],8))
    print(a.combinationSum([2],1))
    