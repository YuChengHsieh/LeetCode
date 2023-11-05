class Solution:
    def numTrees(self, n: int) -> int:
        # DP[i] means that total ways to construct total DP[i] trees by using i nodes
        DP = [0 for _ in range(n+1)]
        DP[0] = 1
        DP[1] = 1
        
        for i in range(2,n+1):
            """
            eg. DP[3] = DP[0]*DP[2]+DP[1]*DP[1]+DP[2]*DP[0]
            DP[2]*DP[0]:                DP[1]*DP[1]:                    DP[2]*DP[0]:    
                    1                           2                               3
                   / \                         / \                             / \
                      2                       1   3                           2
                       \                                                     /   
                        3                                                   1
            left subtree: 0 nodes       left subtree: 1 nodes           left subtree: 2 nodes
            right subtree: 2 nodes      right subtree: 1 nodes          right subtree: 0 nodes
            => DP[2]*DP[0]              => DP[1]*DP[1]                  => DP[2]*DP[0]
            """
            idx1 = 0
            idx2 = i-1
            for _ in range(0,i):
                DP[i] += DP[idx1]*DP[idx2]
                idx1 += 1
                idx2 -= 1
        return DP[n]

if __name__ == '__main__':
    a = Solution()
    print(a.numTrees(4))         