import sys
input = sys.stdin.readline

n = int(input())
junk = list(map(int, input().split()))

mn = min(junk)
ret = junk.index(mn)

print(ret)