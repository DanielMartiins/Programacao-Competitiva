t = int(input())

for _ in range(t) :
    n = input()
    ans = 0
    index_sobra = 0

    for i in range(len(n) - 1, -1, -1) :
        if (n[i] != '0') :
            index_sobra = i
            break

    for i in range(index_sobra - 1, -1, -1) :
        if n[i] != '0' : ans += 1
    
    ans += len(n) - 1 - index_sobra
    print(ans)
    