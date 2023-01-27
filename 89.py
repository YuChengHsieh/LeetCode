class Solution:
    def grayCode(self, n: int) -> list[int]:
        ans_list = [0 for i in range(2**n)]
        # gray code algorithm 
        # eg. n = 3, 5 = 101 => gray code= 101 XOR 010(shift 1 bit to right) = 111
        #            4 = 100 XOR 010 = 110
        for i in range(len(ans_list)):
            ans_list[i] = (i >> 1)^i
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.grayCode(3))