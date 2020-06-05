def addBinary(a: str, b: str) -> str:
    total = str(int(a) + int(b))
    out = ""
    carry = 0
    
    for i in range(len(total) - 1, -1, -1):
        temp = 1 if int(total[i]) + carry >= 2 else 0
        out = str((int(total[i]) + carry) % 2) + out
        carry = temp

    # we can result in a new digit after the addition
    if carry == 1:
        out = "1" + out
    return out

print(addBinary("1111111", "1111111111111"))
print(addBinary("1111111", "1001"))