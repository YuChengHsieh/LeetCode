class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans_str = ''
        choose_list = [f'{i+1}' for i in range(n)] # list to choose in answer
        permu_possible = 1 #all permutation possisble in this order
        for i in range(1,n):
            permu_possible *= i
        k -= 1
        
        for order in range(n-1,0,-1):
            idx = int(k//permu_possible)# get index of all possible chooses
            num = choose_list.pop(idx)
            ans_str += num
            k = k%permu_possible
            permu_possible /= order
        ans_str += choose_list.pop()
    
        return ans_str

if __name__ == '__main__':
    a = Solution()
    print(a.getPermutation(3,3))
    print(a.getPermutation(4,9))
    print(a.getPermutation(100,257))
            