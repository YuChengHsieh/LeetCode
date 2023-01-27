class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        len_s = len(s)
        left_1_list = [0 for _ in range(len_s)]
        right_0_list = [0 for _ in range(len_s)]
        
        # cal left hand side 1 of every index
        for i in range(1,len_s):
            left_1_list[i] += left_1_list[i-1]
            if s[i-1] == '1':
                left_1_list[i] += 1

        # cal right hand side 0 of every index
        for i in reversed(range(len_s-1)):
            right_0_list[i] += right_0_list[i+1]
            if s[i+1] == '0':
                right_0_list[i] += 1
        
        # find the minimum number of left_1_list[i] + right_0_list[i]
        min = len_s
        for i in range(len_s):
            sum = left_1_list[i] + right_0_list[i]
            if sum < min : 
                min = sum
        
        return min
        
if __name__ == '__main__':
    a = Solution()
    print(a.minFlipsMonoIncr("0101100011"))
    print(a.minFlipsMonoIncr("010110"))
    print(a.minFlipsMonoIncr("00011000"))
    