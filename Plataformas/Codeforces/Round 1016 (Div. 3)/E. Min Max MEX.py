t = int(input())


def possible(mex) -> bool:
    partitions = 0  # Qty of subarrays containing [0, 1,..., mex-1]
    covered = 0
    found = [False for _ in range(mex)]  # Found numbers from 0 to mex - 1

    for num in array:
        if num < mex and not found[num]:
            covered += 1
            found[num] = True
        if covered == mex:
            partitions += 1
            covered = 0
            for i in range(mex):
                found[i] = False
        if partitions == k:
            return True
    return False


def solve() -> int:
    lo = 0
    hi = (n // k) + 1
    ans = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if possible(mid):
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return ans


while t != 0:
    n, k = map(int, input().split())
    array = list(map(int, input().split()))
    print(solve())
    t -= 1
