for _ in range(int(input())):
    n=int(input())
    k=int(input())
    sum2=0
    if n>k :
        sum2=min(n-k,k)*2
        if k==n-k :
            sum2-=1
    else :
        sum2=min(n-(k%n),k%n)*2
        if n&1==0:
            if n==(k%n)*2:
                sum2-=1
    print(sum2)
