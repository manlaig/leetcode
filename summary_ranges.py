def summaryRanges(self, nums):
    if len(nums) == 0:
        return nums
    elif len(nums) == 1:
        return [str(nums[0])]
    """
    :type nums: List[int]
    :rtype: List[str]
    """
    out = []
    left = 0
    right = 1
    while right < len(nums):
        while right < len(nums) and nums[right] - nums[right-1] == 1:
            right += 1
        if left != right-1:
            out += [str(nums[left]) + "->" + str(nums[right-1])]
        else:
            out += [str(nums[left])]
        left = right
        right = right + 1
    if left == len(nums) - 1:
        out += [str(nums[left])]
    return out
