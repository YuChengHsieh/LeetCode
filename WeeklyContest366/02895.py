class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        #   greedy
        processorTime.sort()
        tasks.sort()
        tasks.reverse()
        n = len(processorTime)
        ans = 0
        for i in range(n):
            ans = max(ans,tasks[i*4]+processorTime[i])
        return ans