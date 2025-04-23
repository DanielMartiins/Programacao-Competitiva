def solve():
    n = int(input())  # Count for operation 1

    str = input()
    switches = 0  # Count for operation 2
    curr = "0"
    for char in str:
        if char != curr:
            curr = char
            switches += 1

    if switches >= 3:
        print(n + switches - 2)
    elif switches == 2:
        print(n + switches - 1)
    else:
        print(n + switches)


t = int(input())

for _ in range(t):
    solve()
