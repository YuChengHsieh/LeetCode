# greedy
class Solution:
    def jump(self, nums: list[int]) -> int:
        cur_position = 0
        end_position = len(nums) - 1
        cnt = 0
        
        while cur_position + nums[cur_position] < end_position:

            # find next length
            max_next_position = -1
            max_next_val = -1
            for next_position in range(cur_position+1,cur_position+nums[cur_position]+1):
                if nums[next_position]+next_position > max_next_val:
                    max_next_val = nums[next_position]+next_position
                    max_next_position = next_position
            
            cur_position = max_next_position
            cnt += 1

        return cnt if cur_position == end_position else cnt+1 #deal with [0] problem
    
if __name__ == '__main__':
    a = Solution()
    print(a.jump([1,2,1,1,1]))
    print(a.jump([2,3,1,1,4]))
    print(a.jump([2,3,0,1,4]))
    print(a.jump([10,9,8,7,6,5,4,3,2,1,1,0]))