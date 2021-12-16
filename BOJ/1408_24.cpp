#include <cstdio>
#include <string>
using namespace std;


int main()
{
	int st[3], fin[3], ans[3]={0};
	int stSec=0, finSec=0, ansSec=0;
	char blank;

	scanf("%d%c%d%c%d", &st[0], &blank, &st[1], &blank, &st[2]);
	scanf("%d%c%d%c%d", &fin[0], &blank, &fin[1], &blank, &fin[2]);

	stSec = st[0]*3600+st[1]*60+st[2];
	finSec = fin[0]*3600+fin[1]*60+fin[2];

	if(finSec < stSec) finSec += 24*3600;

	ansSec = finSec-stSec;

	ans[0] = ansSec / 3600;
	ans[1] = (ansSec - ans[0]*3600) / 60;
	ans[2] = ansSec - ans[0]*3600 - ans[1]*60;
	printf("%02d:%02d:%02d", ans[0], ans[1], ans[2]);

	return 0;
}
