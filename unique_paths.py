"""
    This solution uses combinatorics to solve.
    For any path where we're only allowed to move right or down,
    the resulting path will look similar to RDRDRRD, where R is right and D is down.
    In that case since the length is fixed,
    the number of unique paths is the number of ways to arrange the Rs or Ds in the path.
"""
class Solution:
    def fact(self, n, total = 1):
        return total if n <= 1 else self.fact(n-1, total * n)
    
    def uniquePaths(self, m: int, n: int) -> int:        
        return int(self.fact(m+n-2) / (self.fact(n-1) * self.fact(m-1)));
        
print(Solution().uniquePaths(15,15))