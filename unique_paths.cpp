class Solution:
    def fact(self, n, total = 1):
        return total if n <= 1 else self.fact(n-1, total * n)
    
    def uniquePaths(self, m: int, n: int) -> int:        
        return int(self.fact(m+n-2) / (self.fact(n-1) * self.fact(m-1)));
        
print(Solution().uniquePaths(15,15))