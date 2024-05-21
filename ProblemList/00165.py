class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        v1_len = len(v1); v2_len = len(v2)
        for i in range(max(v1_len, v2_len)):
            if(i >= v1_len):
                if(int(v2[i]) > 0): return -1
            elif(i >= v2_len):
                if(int(v1[i]) > 0): return 1
            
            elif(int(v1[i]) > int(v2[i])): return 1
            elif(int(v1[i]) < int(v2[i])): return -1

        return 0