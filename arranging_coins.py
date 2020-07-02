def arrangeCoins(self, n: int) -> int:
    if n < 0:
        return -1
    s = 0;
    
    while s * (s+1) // 2 < n:
        s += 1;
    while s * (s+1) // 2 > n:
        s -= 1;
    return s;