# class Solution:
#     def restoreIpAddresses(self, s: str) -> list[str]:
#         self.s = s
#         self.ans = []
#         self.rec(0,0,'')
#         return self.ans
        
#     def rec(self,idx,cnt,ip_str):
#         if cnt == 4:# finish ip points search
#             if len(ip_str) == len(self.s)+3: # result ip length equal to s length add three points
#                 self.ans.append(ip_str)
#             return
        
#         for i in range(idx,idx+3):
#             # 1. Do not expand if idx > length or any given ip segment > 255 or 0 is leading number
#             if i>=len(self.s) or (i == idx+2 and int(self.s[idx:idx+3])) > 255 \
#                 or (i == idx+1 and self.s[idx] == '0'):
#                 return
#             ip_str += self.s[i]
#             if cnt < 3:
#                 ip_str += '.'
#             self.rec(i+1,cnt+1,ip_str)
#             if cnt < 3:
#                 ip_str = ip_str[:-1]

backtracking 
class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        ans = []
        
        def rec(idx,cnt,ip_str):
            if cnt == 4:# finish ip points search
                if len(ip_str) == len(s)+3: # result ip length equal to s length add three points
                    ans.append(ip_str)
                return
            
            for i in range(idx,idx+3):
                # 1. Do not expand if idx > length or any given ip segment > 255 or 0 is leading number
                if i>=len(s) or (i == idx+2 and int(s[idx:idx+3])) > 255 \
                    or (i == idx+1 and s[idx] == '0'):
                    return
                ip_str += s[i]
                if cnt < 3:
                    ip_str += '.'
                rec(i+1,cnt+1,ip_str)
                if cnt < 3:
                    ip_str = ip_str[:-1]
        rec(0,0,'')
        return ans

if __name__ == '__main__':
    a = Solution()
    # print(a.restoreIpAddresses("25525511135"))
    # print(a.restoreIpAddresses("0000"))
    print(a.restoreIpAddresses("101023"))