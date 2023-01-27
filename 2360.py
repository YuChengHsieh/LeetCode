# BFS TLE
# class Solution:
#     def longestCycle(self, edges: list[int]) -> int:
#         remaining_list = [i for i in range(len(edges))]
#         ans = -1
#         while len(remaining_list) != 0:
#             queue = []
#             queue.append(remaining_list[0])
#             cnt = 0
#             move_dict = {}
#             while len(queue) != 0:
#                 cur_node = queue.pop(0)
#                 if cur_node not in set(remaining_list):
#                     break
#                 if move_dict.get(cur_node) is not None:
#                     if cnt- move_dict[cur_node] > ans:
#                         ans = cnt-move_dict[cur_node]
#                 else:
#                     move_dict[cur_node] = cnt
#                     if edges[cur_node] != -1:
#                         queue.append(edges[cur_node])
#                 cnt += 1
#             remaining_list = [i for i in remaining_list if move_dict.get(i) is None]
#         return ans

class Solution:
    def longestCycle(self, edges: list[int]) -> int:
        ans = -1
        time = 1
        visited = [0]*len(edges)
        for i,node in enumerate(edges):
            if visited[i] > 0:
                continue
            start_time = time
            nextn = node
            # DFS
            while nextn != -1 and visited[nextn] == 0:
                visited[nextn] = time
                time += 1
                nextn = edges[nextn]

            if nextn != -1 and visited[nextn] >= start_time:
                if time-visited[nextn] > ans:
                    ans = time-visited[nextn]
        return ans
if __name__ == '__main__':
    a = Solution()
    # print(a.longestCycle([3,3,4,2,3]))
    print(a.longestCycle([2,-1,3,1]))
