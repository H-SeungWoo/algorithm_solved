import sys
input =sys.stdin.readline

a, b= map(int, input().split())

if a < b or (a+b) % 2!=0:
    print(-1)
else:
    x = (a+b)//2
    y = (a-b)//2

    if y < 0:
        print(-1)
    else:
        print(x, y)