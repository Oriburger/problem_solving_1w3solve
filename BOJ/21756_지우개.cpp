import sys
input = sys.stdin.readline 

n = int(input())
arr = list(range(1, n+1)) #1부터 n까지의 리스트를 미리 만들어둬요

while len(arr) != 1: # 리스트의 길이가 1이 될때까지 반복해요
    tmp = [] # 임시로 쓸 리스트를 만들어요 
    for i in range(1, len(arr), 2): #짝수번째 원소들을 돌며 
        tmp.append(arr[i]) #하나씩 임시 리스트에 넣어요
    arr = tmp #임시 리스트를 arr에 넣어요

print(arr[0])
