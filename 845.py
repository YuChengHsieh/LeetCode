class Solution:
    def longestMountain(self, arr: list[int]) -> int:
        tmp_cnt = 1
        max_cnt = 0
        inc = dec = False
        arr_len = len(arr)
        for i in range(1,arr_len):
            if arr[i] > arr[i-1]:
                inc = True
                # if first dec then inc => not mountain => reset dec
                if dec:
                    dec = False
                    tmp_cnt = 1
                tmp_cnt += 1
            elif arr[i] < arr[i-1]:
                dec = True
                tmp_cnt += 1
                # check if inc first and dec and tmp_cnt > max_cnt, update max_cnt to tmp_cnt
                if inc and tmp_cnt > max_cnt:
                    max_cnt = tmp_cnt
            else: #arr[i] == arr[i-1]
                # flat, reset inc and dec
                inc = dec = False
                tmp_cnt = 1
        return max_cnt

if __name__ == '__main__':
    a = Solution()
    print(a.longestMountain([4,3,2,1,2,3,4,3,2,1]))
    print(a.longestMountain([2,1,4,7,3,2,5]))
    print(a.longestMountain([1,2,3,4,5]))
    print(a.longestMountain([1,2,2,3,4,5,4,3,2,1]))