#include <iostream>
using namespace std;

int input;
int sieve[246913];
int pn_cnt[246913]; //prime number count

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=2; i<=246912; i++)
	for(int j=2; i*j<=246912; j++)
		sieve[i*j]++;
	
	for(int i=2; i<=246912; i++)
	{
		pn_cnt[i] = pn_cnt[i-1];
		
		if(sieve[i]==0)
			pn_cnt[i]++;
	}

	while(1)
	{
		cin>>input;
		if(input==0) break;
		
		cout<<pn_cnt[input * 2] - pn_cnt[input]<<'\n';
	}
	
	return 0;
} 
