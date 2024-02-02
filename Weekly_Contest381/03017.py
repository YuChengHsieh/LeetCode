# three cases & numpy
import numpy as np
class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> list[int]:
        if x == y: return [(i-1)*2 for i in range(n,0,-1)]
        ans = [(i-1)*2 for i in range(n,0,-1)]
        # print(ans)
        max_ = max(x,y)-1; min_ = min(x,y)-1
        k = max_ - min_
        
        
        ans[0] += 2
        ans[k-1] -= 2
        # print(ans)
        
        # both inside cycle
        i = 1
        while ans[k-i-1] > 0 and i < k-i-1:
            val = (i+1)*2
            ans[i] += val
            ans[k-i-1] -= val
            i += 1
        # print(ans)
        
        if max_ == n-1 and min_ == 0: return ans 
        
        # both outside cycle
        i = 1
        left_node = min_
        right_node = n-max_-1
        val = 0
        while ans[k+i-1] > 0 and k+i-1 < n:
            val = min((k+i-1)*2,(min(i,left_node,right_node)+1)*2,ans[k+i-1])
            ans[i] += val
            ans[k+i-1] -= val
            i += 1
        
        # one inside cycle and one outside cycle
        ans = np.array(ans)
        if max_ - min_ > 3:
 
            # ans = np.array([0]*n)
            # 1
            i = 2; right_idx = max_-1; cnt = 0
            while i < right_idx-min_:
                i += 1
                right_idx -= 1
                cnt += 1
            arr = [2]*cnt + [0] + [-2]*cnt if i == right_idx-min_ else [2]*cnt + [-2]*cnt
            arr = np.array(arr)
            
            idx = 2
            for i in range(min_):
                ans[idx:idx+len(arr)] += arr
                idx += 1 
            
            # 2
            i = 2; left_idx = min_+1; cnt = 0

            while i < max_+1-left_idx-1:
                left_idx += 1
                i += 1
                cnt += 1
            
            arr = [2]*cnt + [0] + [-2]*cnt if i == max_+1-left_idx-1 else [2]*cnt + [-2]*cnt
            arr = np.array(arr)

            idx = 2
            for i in range(max_+1,n):
                ans[idx:idx+len(arr)] += arr
                idx += 1
        
        return ans.tolist()
        
        
        