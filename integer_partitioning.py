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

out = []
partition(5, [], out, 5)
print(out)
