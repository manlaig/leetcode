def factorial(n, out=1):
    if n <= 1:
        return out
    return factorial(n-1, out*n)

def choose(n, k):
    return factorial(n) / factorial(k) / factorial(n-k)

def catalan_number(n):
    return int(choose(2*n, n) / (n+1))

def numTrees(n):
    return catalan_number(n)
