def addDigits(self, num: int) -> int:
    if num < 10:
        return num
    out = 0
    while num > 0:
        out += num % 10
        num //= 10
    return self.addDigits(out)
