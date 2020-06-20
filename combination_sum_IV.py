def combinationSum4(self, nums, target):
    arr = [0] * (target+1)
    arr[0] = 1
    
    for i in range(1, target+1, 1):
        total = 0
        for j in nums:
            if i-j >= 0:
                total += arr[i-j]
        arr[i] = total
    
    return arr[target]