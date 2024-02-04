class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        mat = [poured]
        for i in range(query_row):
            new_mat = []
            for j in range(len(mat)):
                mat[j] = max(0,mat[j]-1)
            for j in range(i+2):
                if j == 0:
                    new_mat.append(max(0,(mat[0])/2))
                elif j == i+1:
                    new_mat.append(max(0,(mat[-1])/2))
                else:
                    new_mat.append(max(0,(mat[j-1]+mat[j])/2))
            mat = new_mat
        return 1 if mat[query_glass] > 1 else mat[query_glass]

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glass = [poured]
        for i in range(query_row):
            new_glass = [0]*(i+2)
            for j in range(i+1):
                pour = (glass[j]-1)/2.0
                if pour < 0: continue
                new_glass[j] += pour
                new_glass[j+1] += pour
            glass = new_glass
        return min(1,glass[query_glass])