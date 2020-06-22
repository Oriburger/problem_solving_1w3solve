#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n;
int sum; //각 자리수 합 
bool zflag=true; //zero의 존재여부 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	if(n.find('0') == string::npos)
		zflag=false;
	
	for(int i=0; i<n.size(); i++)
		sum+=n[i]-'0';
	
	sort(n.begin(), n.end(), greater<char>());
	
	if(sum%3==0 && zflag)
		cout<<n;
	
	else
		cout<<-1<<'\n';
	
	return 0;
}
