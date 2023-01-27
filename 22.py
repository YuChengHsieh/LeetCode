class Solution:         
    def generateParenthesis(self, n: int) -> list[str]:
        ret_list = []
        def rec(num:int,cnt:int,rev_cnt:int,ret_str:str):
            if cnt < num:
                ret_str += '('
                cnt += 1
                rec(num,cnt,rev_cnt,ret_str)
                ret_str = ret_str[:-1]
                cnt -= 1
            
            if rev_cnt < num and rev_cnt < cnt:#parentheses constraint
                ret_str += ')'
                rev_cnt += 1
                rec(num,cnt,rev_cnt,ret_str)
                ret_str = ret_str[:-1]
                rev_cnt -= 1
            
            if cnt == num and rev_cnt == num :
                ret_list.append(ret_str)
            
        rec(n,0,0,'')
        return ret_list
    
if __name__ == '__main__':
    a = Solution()
    print(a.generateParenthesis(3))