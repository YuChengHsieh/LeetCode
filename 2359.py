# DFS find node that minimize of maximum distance between node and node1, node and node2
class Solution:
    def closestMeetingNode(self, edges: list[int], node1: int, node2: int) -> int:
        
        def rec_dict(node,connected_dict,counter):
            if connected_dict.get(node) is not None:
                return connected_dict
            connected_dict[node] = counter
            return connected_dict if edges[node] == -1 else rec_dict(edges[node],connected_dict,counter+1)
            
        node1_dict = rec_dict(node1,{},0) #maximum
        node2_dict = rec_dict(node2,{},0) #minimum

        min_dist = 100000
        min_node = -1
        for tmp_node in range(len(edges)):
            if node1_dict.get(tmp_node) is None or node2_dict.get(tmp_node) is None:
                continue
            max_dist = max(node1_dict[tmp_node],node2_dict[tmp_node])
            if max_dist < min_dist:
                min_dist = max_dist
                min_node = tmp_node
        return min_node

if __name__ == '__main__':
    a = Solution()
    print(a.closestMeetingNode([2,2,3,-1],0,1))
    print(a.closestMeetingNode([4,3,0,5,3,-1],0,4))
    print(a.closestMeetingNode([4,4,4,5,1,2,2],1,1))
    print(a.closestMeetingNode([4,4,8,-1,9,8,4,4,1,1],5,6))
                