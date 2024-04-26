import sys
input = sys.stdin.readline 

n = int(input())
ans = 0

def GetIsWeirdNum(k): #자기자신 % 자릿수를 모두 더한 수가 0인지??
    a = k
    b = 0
    while k > 0:
        b += k % 10
        k //= 10
    return a % b == 0

for i in range(1, n+1): #1부터 n까지 시도해요
    ans += GetIsWeirdNum(i)

print(ans)
