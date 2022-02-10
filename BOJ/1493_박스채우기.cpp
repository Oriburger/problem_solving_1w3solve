#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Cube{ int len; int cnt; };

int length, width, height;
int n, flag = false, ans;
vector<Cube> cubeInfo;

int Answer(int l, int w, int h)
{
    if(l==0 || w==0 || h==0) return 0; 

    for(int i=n-1; i>=0; i--)
    {
    	const int tmp = cubeInfo[i].len;
        if(cubeInfo[i].cnt<=0 || l-tmp<0 || w-tmp<0 || h-tmp<0) continue;
        
		cubeInfo[i].cnt-=1; flag=true;
	    return Answer(l-tmp, w, h) + Answer(tmp, w-tmp, tmp)
				 + Answer(tmp, w, h-tmp) + 1;
	}
	flag = false;
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
		cubeInfo.push_back({(1<<idx), cnt});
	}

    ans = Answer(length, width, height);
    
    if(!flag) cout<<-1<<'\n';
    else cout<<ans<<'\n';

    return 0;
}
