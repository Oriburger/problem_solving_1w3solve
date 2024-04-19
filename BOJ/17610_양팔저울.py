import sys
input = sys.stdin.readline

def get_answer(idx, k):
    global ans
    if idx == n:
        if k >= 0:
            check[k] = True
        return
    get_answer(idx + 1, k - arr[idx])
    get_answer(idx + 1, k)
    get_answer(idx + 1, k + arr[idx])


n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
check = [False] * (2600001)
ans = 0

get_answer(0, 0)
for i in range(1, s + 1):
    if not check[i]:
        ans += 1

print(ans)
