#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int cache[51][51][51];

int Answer(int p, int q, int k)
{
	int& ret = cache[p][q][k];
	if(ret != -1) return ret;
	if(p<=0 || q<=0 || k<=0) return 1;
	else if(p>20 || q>20 || k>20) return ret = Answer(20, 20, 20);
	else if(p<q && q<k) return ret = Answer(p, q, k-1) + Answer(p, q-1, k-1) - Answer(p, q-1, k);
	return ret= Answer(p-1, q, k) + Answer(p-1, q-1, k) + Answer(p-1, q, k-1) - Answer(p-1, q-1, k-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));
	
	while(1)
	{
		cin>>a>>b>>c;

		if(a==-1 && b==-1 && c==-1) break; 

		cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
		cout<<Answer(max(a, 0), max(b, 0), max(c, 0))<<'\n';
	}
	
	return 0;
}
