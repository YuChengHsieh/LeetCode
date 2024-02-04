class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        return 1 if n == 1 else 0.5
        """
        For n = 3
        1 2 3 * 
        1 3 2 X
        2 1 3 *
        2 3 1 X
        3 1 2 *
        3 2 1 *
        *: valid; X: invalid
        2/4 = 0.5
        """