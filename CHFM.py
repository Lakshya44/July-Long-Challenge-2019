for i in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    tot_mean = sum(a)/n
    total_sum = sum(a)
    pos = 0
    for i in range(n):
        if tot_mean == ( total_sum - a[i] ) / ( n-1 ) :
            if pos == 0 :
                pos = i + 1
            else :
                if a[i] > a[pos]:
                    pos = i + 1
    if pos == 0:
        print("Impossible")
    else:
        print(pos)
