def combinations(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = range(r)
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)

def MAXOR(subset):
    res = 0
    for item in subset:
        res ^= item
    return res

N = int(raw_input())

if N == 1:
    print(0)
    quit()

items = []

for i in range(N):
    items.append(int(raw_input()))
    #items.append(raw_input())

counter = 0
results = []

for i in range(N):
    for c in combinations(items, i+1):
        maxor = MAXOR(c)
        if maxor in results:
            counter += 1
        else:
            results.append(maxor)

#print(results)
MODULO = 1000000007
print(counter % MODULO)
