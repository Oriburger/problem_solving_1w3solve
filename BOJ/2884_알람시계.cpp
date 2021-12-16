#include <iostream>
using namespace std;

int H, M;

//0~1439
void PrtAnswer(int h, int m)
{
	int alarm = h*60 + m;
	
	if(alarm>=45) 
		alarm-=45;
	else
		alarm = 1439 - (45 - alarm) + 1;
	
	cout<<alarm/60<<' '<<alarm%60<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>H>>M;
	
	PrtAnswer(H, M);
	
	return 0;
}
