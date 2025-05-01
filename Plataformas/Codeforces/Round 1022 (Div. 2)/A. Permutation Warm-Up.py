def solve() :
    n = int(input())
    fp_max = 0
    p = [i for i in range(n, 0, -1)]
    for i in range(n) :
        fp_max += abs(p[i] - (i+1))
    
    ans = 0
    while (fp_max >= 0) :
        ans += 1
        fp_max -= 2

    print(ans)
        



t = int(input())

for _ in range(t) :
    solve()