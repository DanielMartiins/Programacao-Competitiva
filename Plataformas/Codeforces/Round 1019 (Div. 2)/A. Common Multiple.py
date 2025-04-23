def solve() :
    n = int(input())
    diffNumbers = set(map(int, input().split()))
    print(len(diffNumbers))

t = int(input())
for _ in range(t) :
    solve()