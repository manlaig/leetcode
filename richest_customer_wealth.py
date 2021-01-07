def maximumWealth(self, accounts):
    """
    :type accounts: List[List[int]]
    :rtype: int
    """
    ret = 0
    for arr in accounts:
        ret = max(ret, sum(arr))
    return ret