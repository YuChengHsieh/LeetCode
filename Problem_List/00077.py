# backtracking
class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        list_ = [i+1 for i in range(n)]
        ans_list = []
        def rec(idx,tmp_list):
            if len(tmp_list) == k:
                ans_list.append(tmp_list.copy())
                return
            
            for i in range(idx,n):
                tmp_list.append(list_[i])
                rec(i+1,tmp_list)
                tmp_list.pop()
            return
        rec(0,[])
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.combine(4,2))
    print(a.combine(1,1))