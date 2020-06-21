"""
    buf keeps the latest partitioning
    we pass limit to get rid of permutations in the answer
"""
def partition(num, buf, out, limit):
    if(num <= 0):
        # add the partition to the output array
        out += [buf]
    else:
        for i in range(limit, 0, -1):
            if num - i >= 0:
                partition(num - i, buf + [i], out, i)

# partition using the available vals
def partition2(vals, num, buf, out, curr):
    if num == 0:
        out += [buf]
    elif num > 0:
        for i in range(curr, len(vals), 1):
            if num - vals[i] >= 0:
                partition2(vals, num - vals[i], buf + [vals[i]], out, i)

out = []
partition(5, [], out, 5)
out2 = []
partition2([1,3,5], 5, [], out2, 0)
print(out)
print(out2)
