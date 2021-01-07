def numIdenticalPairs(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    out = 0
    table = {}
    for i in range(len(nums) - 1, -1, -1):
        if nums[i] in table:
            out += table[nums[i]]
        table[nums[i]] = table[nums[i]] + 1 if nums[i] in table else 1
    return out