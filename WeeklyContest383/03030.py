class Solution:
    def resultGrid(self, image: list[list[int]], threshold: int) -> list[list[int]]:
        m = len(image); n = len(image[0])
        region_cnt = [[[True]*4 for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                region_cnt[i][j][0] = True if (i-1 < 0 or (i-1 >= 0 and abs(image[i-1][j]-image[i][j]) <= threshold)) else False
                region_cnt[i][j][1] = True if (i+1 >= m or (i+1 < m and abs(image[i+1][j]-image[i][j]) <= threshold)) else False
                region_cnt[i][j][2] = True if(j-1 < 0 or (j-1 >= 0 and abs(image[i][j-1]-image[i][j]) <= threshold)) else False
                region_cnt[i][j][3] = True if (j+1 >= n or (j+1 < n and abs(image[i][j+1]-image[i][j]) <= threshold)) else False
        regions_time = [[0]*n for _ in range(m)]
        ans = [[0]*n for _ in range(m)]
        for i in range(m-2):
            for j in range(n-2):
                is_region = True
                val = 0
                for k in range(3):
                    for l in range(3):
                        if k == 0:
                            if l == 0:
                                if not (region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 1:
                                if not (region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][2] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 2:
                                if not (region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][2]):
                                    is_region = False
                                    break
                        elif k == 1:
                            if l == 0:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 1:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][2] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 2:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][1] and region_cnt[i+k][j+l][2]):
                                    is_region = False
                                    break
                        elif k == 2:
                            if l == 0:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 1:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][2] and region_cnt[i+k][j+l][3]):
                                    is_region = False
                                    break
                            elif l == 2:
                                if not (region_cnt[i+k][j+l][0] and region_cnt[i+k][j+l][2]):
                                    is_region = False
                                    break
                        
                        val += image[i+k][j+l]
                    if not is_region: break
                
                if is_region:
                    val //= 9
                    for k in range(3):
                        for l in range(3):
                            regions_time[i+k][j+l] += 1
                            ans[i+k][j+l] += val
        
        for i in range(m):
            for j in range(n):
                if regions_time[i][j] == 0: ans[i][j] = image[i][j]
                else: ans[i][j] = ans[i][j]//regions_time[i][j]
        return ans
                    