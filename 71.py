# Python 
# class Solution:
#     def simplifyPath(self, path: str) -> str:
#         path_list = path.split('/')[1:]
#         ans_path_list = []
#         for str_ in path_list:
#             if str_ == '' or str_ == '.':
#                 continue
#             elif str_ == '..':
#                 if len(ans_path_list) > 0:
#                     ans_path_list.pop()
#             else:
#                 ans_path_list.append(str_)
        
#         return '/'+'/'.join(ans_path_list)

# stack
class Solution:
    def simplifyPath(self, path: str) -> str:
        ans_stack = []
        path_len = len(path)
        idx = 0
        while idx+1 < path_len:
            # make sure that path[idx] == '/'
            end_idx = idx+1
            tmp_str = ''
            while end_idx < path_len and path[end_idx] != '/':
                tmp_str += path[end_idx]
                end_idx += 1
            if tmp_str == '' or tmp_str == '.': # do not push
                pass 
            elif tmp_str == '..':
                if len(ans_stack) > 0:
                    ans_stack.pop()
            else:
                ans_stack.append(tmp_str)
            idx = end_idx
        
        in_ = False
        ans = '/'
        for str_ in ans_stack:
            ans += f'{str_}/'
            in_ = True
        return ans[:-1] if in_ else ans                    
            
if __name__ == '__main__':
    a = Solution()
    print(a.simplifyPath("/home/"))
    print(a.simplifyPath("/a//b////c/d//././/.."))
    print(a.simplifyPath("/home/./foo/"))
        
        
                   