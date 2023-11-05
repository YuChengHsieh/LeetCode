from numpy import inf
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        y_cnt = 0
        for char in customers:
            if char == 'Y': y_cnt += 1
        
        min_penalty = inf; idx = -1; cur_penalty = 0
        for i in range(len(customers)+1):
            if y_cnt+cur_penalty < min_penalty:
                min_penalty = y_cnt+cur_penalty
                idx = i
            if i != len(customers):
                if customers[i] == 'N': cur_penalty += 1
                else: y_cnt -= 1
        return idx