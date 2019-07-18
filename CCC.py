for _ in range(int(input())):
    n,z=[int(i) for i in input().split()]
    a=[int(i) for i in input().split()]
    a.sort(reverse=True)
    mini=1000000007
    for i in range(1,10001):
        s=0
        r=0
        for j in range(n):
            if a[j] > i:
                s += i
            else:
                r+=1
                s+=a[j]
                if r==z:
                    if s<=mini:
                        mini=s
                        break
    print(mini)                