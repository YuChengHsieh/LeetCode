class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
#         sliding window
        
        def cmp(cur,ans):
            if len(cur) > len(ans): return False
            for i in range(len(cur)):
                if int(cur[i]) < int(ans[i]): return True
                elif int(cur[i]) > int(ans[i]): return False
            return False
        
        def find_left(left,s):
            while left < len(s) and s[left] == '0': 
                left += 1
            return left
    
        ans = '1'*101; cur_str = ''
        n = len(s)
        left = right = find_left(0,s)
        ones_cnt = 0
        
        while right < n:
            if s[right] == '1': ones_cnt += 1
            cur_str += s[right]
            # print(left,right,ones_cnt,cur_str)
            if ones_cnt == k:
                if len(cur_str) < len(ans) or cmp(cur_str,ans): 
                    ans = cur_str
                # print(left+1)
                new_left = find_left(left+1,s)
                cur_str = cur_str[new_left-left:]
                left = new_left
                ones_cnt -= 1
            right += 1
                
        return "" if ans == '1'*101 else ans