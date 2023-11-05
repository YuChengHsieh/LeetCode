class Solution:
    def partition(self, s: str) -> list[list[str]]:
        ans = []
        s_len = len(s)
        def rec(start,end,palin_list):
            # test every time, if it's not palindrome string, return
            if s[start:end] != s[start:end][::-1]: 
                return
            # make sure that pass here, every string in palin_list is palindrome string
            # if end == length s, answer list appends
            if end == s_len:
                ans.append(palin_list.copy())
                return
            
            tmp_str = ''  
            for i in range(end,s_len):
                tmp_str += s[i] # keep adding, will not pop
                palin_list.append(tmp_str)
                rec(end,i+1,palin_list)
                palin_list.pop()
            return
            
        rec(0,0,[])
        return ans

if __name__ == '__main__':
    a = Solution()
    print(a.partition("aab"))
    print(a.partition("a"))