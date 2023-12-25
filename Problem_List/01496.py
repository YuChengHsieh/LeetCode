class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = set()
        cur_pt = [0,0]
        visited.add(tuple(cur_pt))
        for cmd in path:
            if cmd == 'N': cur_pt[1] -= 1
            elif cmd == 'S': cur_pt[1] += 1
            elif cmd == 'E': cur_pt[0] += 1
            elif cmd == 'W': cur_pt[0] -= 1
            if tuple(cur_pt) in visited: return True
            visited.add(tuple(cur_pt))
        return False