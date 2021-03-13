#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;
const int d[2] = {-1, 1}; //탐색 시 curr이 1씩 증감

int ans = INF;
int cache[101][MAX][(1<<MAX)]; //﻿남은 자릿수 k, 수들의 picked 여부를 나타내는 state,
                               //현재 pick한 수 curr이 주어졌을때, 계단수의 개수

int Answer(int k, int curr, int state)
{
	if(k==0) //수를 다 골랐다면?
	{
		if(state!=(1<<(MAX+1))-1) return -1; //0~9가 다 포함되지 않았다면 -1반환
		return 1; //조건에 맞는 계단수라면?
	}

	int &ret = cache[k][curr][state];
	if(ret!=0) return ret;

	for(int i=0; i<2; i++)
	{
		int next = curr + d[i]; 
		if(next<0 || next>=MAX) continue; //범위(0~9)에 벗어나는 수라면

        //OR연산으로 next자리의 비트를 켜주기 때문에,
        //이미 해당 자리의 비트가 켜져 있어도 상관없다. 
		int nextVal = Answer(k-1, next, (state | (1<<next)))%INF; 
		if(nextVal != -1) 
			ret = (ret + nextVal)%INF;
	}

	return ret%INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	if(n<10) ans=0;
	else
	{
		for(int i=1; i<MAX; i++)
			ans = (ans + Answer(n-1, i, ((1<<MAX)|(1<<i)) ) %INF) %INF;
	}

	cout<<ans<<'\n';

	return 0;
}
