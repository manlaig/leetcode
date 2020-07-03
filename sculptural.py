def sculptural(semicolon, k):
    """
        Find the largest number of length 'k' or fewer,
        composed of digits from 'semicolon', in order.
    """
    if k == 0 or semicolon == 0:
        return 0
    
    a = sculptural(semicolon // 10, k-1) * 10 + semicolon % 10
    b = sculptural(semicolon // 10, k)

    return max(a, b)

print(sculptural(1234, 1))
print(sculptural(32749, 2))
print(sculptural(1917, 2))
print(sculptural(32749, 18))