"""TLE cases"""
# class Solution:
#     def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        
#         self.candidates = list(reversed(sorted(candidates)))
#         self.target = target
#         self.ans_list = []
#         self.rec(0,0,[])
#         return self.ans_list
    
#     def rec(self, cur_sum:int, cur_idx:int, ans_list:list[int]):
#         if cur_sum == self.target:
#             if sorted(ans_list) not in sorted(self.ans_list):
#                 self.ans_list.append(sorted(ans_list).copy())
#             return
#         elif cur_sum > self.target or cur_idx >= len(self.candidates) or \
#             cur_sum + sum(self.candidates[cur_idx:]) < self.target:
#             return
#         else: #cur_sum < self.target
#             for idx,val in enumerate(self.candidates[cur_idx:]):
#                 ans_list.append(val)
#                 self.rec(cur_sum+val,cur_idx+idx+1,ans_list)
#                 ans_list.pop()
#         return

class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        # Coin change problem
        self.use_dict = {}
        candidates_rm = candidates.copy()
        
        # calculate times(次數) that I can use in every number 
        for num in candidates:
            if num not in self.use_dict.keys():
                self.use_dict[num] = 1
            else:
                self.use_dict[num] += 1
                candidates_rm.remove(num)
        self.candidates = candidates_rm
        self.target = target
        self.ans_list = []
        self.rec(0,0,[],0)
        return self.ans_list
    
    def rec(self,current_sum:int, current_idx:int, ans_list:list[int], count:int):
        #could somehow exceed the times(次數) that I can use in every number, so put it first
        if current_sum > self.target or current_idx >= len(self.candidates)\
            or count > self.use_dict[self.candidates[current_idx]]: 
            return
        elif current_sum == self.target:
            self.ans_list.append(ans_list.copy())
            return
        else: # current_sum < target
            val = self.candidates[current_idx]
            ans_list.append(val)
            self.rec(current_sum+val,current_idx,ans_list,count+1)
            ans_list.pop()
            self.rec(current_sum,current_idx+1,ans_list,0)
    
if __name__ == '__main__':
    a = Solution()
    print(a.combinationSum2([10,1,2,7,6,1,5],8))
    print(a.combinationSum2([2,5,2,1,2],5))
    print(a.combinationSum2([1,2],4))
    print(a.combinationSum2([1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],27))
    print(a.combinationSum2([1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],30))