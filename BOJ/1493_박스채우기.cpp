#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Cube{ int len; int cnt; };

int length, width, height;
int n, flag = false, ans, cube[20]; 

int Answer(int l, int w, int h) //크기가 l*w*h인 박스를 채울 수 있는 최소 큐브 수
{
    if(l==0 || w==0 || h==0) return 0; //더 채울 수 없다면?

    for(int i=n-1; i>=0; i--) //큰 정육면체 큐브 부터 시도
    {
    	const int tmp = (1<<i); //2^i
        if(cube[i]<=0 || l-tmp<0 || w-tmp<0 || h-tmp<0) continue; //불가능한 경우는 패스
        
		cube[i]-=1; flag=true; //가능하다면 해당 큐브 개수 1 감소 
	    return Answer(l-tmp, w, h) + Answer(tmp, w-tmp, tmp) 
				 + Answer(tmp, w, h-tmp) + 1; //세 구간에서 재귀적 호출
	}
	flag = false; //채울 수 있는 경우가 없다면? flag = false
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>length>>width>>height>>n;
	
    for(int i=0; i<n; i++)
	{	
		int idx, cnt;
		cin>>idx>>cnt;
		cube[idx] = cnt;
	}
    ans = Answer(length, width, height);
    
    if(!flag) cout<<-1<<'\n'; //채우기가 불가능하다면 -1
    else cout<<ans<<'\n';

    return 0;
}
