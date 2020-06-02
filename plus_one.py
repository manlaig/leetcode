def plusOne(digits):
    digits[-1] += 1
    carry = 0
    for i in range(len(digits)-1, -1, -1):
        temp = 1 if digits[i] + carry >= 10 else 0
        digits[i] = (digits[i] + carry) % 10
        carry = temp
        if carry == 0:
            break
    if carry == 1:
        digits = [1] + digits
    return digits

print(plusOne([9,9,9]))