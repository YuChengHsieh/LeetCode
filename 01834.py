# priority queue

class Solution:
    def getOrder(self, tasks: list[list[int]]) -> list[int]:
        import heapq
        n = len(tasks)
        tasks = sorted((task[0],task[1],i) for i,task in enumerate(tasks))
        pq = []
        task_complete = 0; task_num = 0
        time = tasks[0][0]
        ans = []
        while task_complete < n:
            while task_num < n and tasks[task_num][0] <= time:
                heapq.heappush(pq,(tasks[task_num][1],tasks[task_num][-1]))
                task_num += 1
            if len(pq) == 0: 
                time = tasks[task_num][0]
            else:
                span_time,idx = heapq.heappop(pq)
                time += span_time
                ans.append(idx)
                task_complete += 1
        return ans