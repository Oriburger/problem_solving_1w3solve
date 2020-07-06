#include <iostream>
#include <vector>
using namespace  std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	vector<int> s(n);

	for(int i=0; i<n; i++) cin>>s[i];

	bool deFlag = true, inFlag = true;
	int deCnt=0, inCnt=0, deAns=0, inAns=0;
	for(int i=1; i<n; i++)
	{
		if(s[i-1] <= s[i])
		{
			if(deFlag) deCnt++;
			inAns = max(inCnt+1, inAns);
			inCnt=0;
			deFlag = true;
			inFlag = false;
		}
		else if(s[i-1] <= s[i])
		{
			if(inFlag) inCnt++;
			deAns = max(deCnt+1, deAns);
			deCnt=0;
			inFlag = true;
			deFlag = false;
		}
	}

	cout<<max(deAns, inAns)<<'\n';

	return 0;
}
