#include <iostream>
#include <cmath>
using namespace std;

int answer=0;

void Answer(int from, int by, int to, int cnt)
{
	if(cnt==1)
	{
		cout<<from<<' '<<to<<'\n';
		answer++;
		return;
	}
	
	Answer(from, to, by, cnt-1);
	Answer(from, by, to, 1);
	Answer(by, from, to, cnt-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	
	cin>>n;
	
	cout<<(int)pow(2, n)-1<<'\n';
	Answer(1, 2, 3, n);
	
	return 0;
}
