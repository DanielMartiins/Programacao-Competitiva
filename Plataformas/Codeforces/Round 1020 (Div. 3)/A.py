def solve() :
    str = input()
    sum = 0 # qty of 1's in the original string
    for digit in str :
        if digit == '1' : sum += 1

    ans = 0
    for digit in str :
        if digit == '0' : ans += sum + 1
        else : ans += sum - 1
    print(ans)

t = int(input())

for _ in range(t) :
    ignore = int(input())
    solve()