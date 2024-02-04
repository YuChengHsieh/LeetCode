class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        # cycle detection
        graph = [[] for _ in range(numCourses)]
        for i,j in prerequisites:
            graph[i].append(j)
        
        no_cycle = set()
        visited = set()
        self.exist_cycle = False

        def dfs(course):
            if course in no_cycle:
                return
            if course in visited:
                self.exist_cycle = True
                return
            
            visited.add(course)
            for nextn in graph[course]:
                dfs(nextn)
                if self.exist_cycle:
                    return
            no_cycle.add(course)
            return
            
        for i in range(numCourses):
            if i not in visited:
                dfs(i)
                if self.exist_cycle:
                    return False
        else:
            return True