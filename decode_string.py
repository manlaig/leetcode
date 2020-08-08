"""
    This solution uses Divide and Conquer, very similar to quick sort
    Time Complexity: O(NlogN) in average and O(N^2) in the worst case
    Space Complexity: The worst can happen in situations like 1[2[3[4[5[6[a]]]]]]
    So, the upper bound of the space complexity is O(N/2)
"""

def getFactor(s, start, end):
    buf = ""
    for i in range(start, end):
        if s[i] >= '0' and s[i] <= '9':
            buf += s[i]
        else:
            return (int(buf), i)

def getClose(s, start, end):
    curr = 0
    for i in range(start, end):
        if s[i] == '[':
            curr += 1
        elif s[i] == ']':
            curr -= 1
        if curr == 0:
            return i

def decode(s, start, end):
    open = -1
    close = -1
    startNum = -1
    
    # find mult factor and index of the closing brace
    for i in range(start, end):
        # the mult factor is guaranteed to be > 0
        if s[i] >= '1' and s[i] <= '9':
            startNum = i
            (freq, endNum) = getFactor(s, i, end)
            open = endNum
            close = getClose(s, endNum, end)
            break

    if open == close or startNum == -1:
        return s[start:end]

    # skip the [...]
    s1 = decode(s, open+1, close)
    # skip the ]
    s2 = decode(s, close+1, end)

    # s[start:startNum] = the word before the number
    return s[start:startNum] + (s1 * freq) + s2

def decodeString(s):
    return decode(s, 0, len(s))
