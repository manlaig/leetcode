class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        d = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in d:
                return [i, d[diff]]
            if not nums[i] in d:
                d[nums[i]] = i
        return []

        """
        # 2 - pass approach
        d = {}
        for i in range(len(nums)):
            if not nums[i] in d:
                d[nums[i]] = i
        for i in range(len(nums)):
            if target - nums[i] in d and d[target - nums[i]] != i:
                return [i, d[target - nums[i]]]
        return []
        """