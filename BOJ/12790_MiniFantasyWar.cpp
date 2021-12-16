#include <iostream>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		int hp, mp, atk, def;
		int a, b, c, d;
		
		cin>>hp>>mp>>atk>>def>>a>>b>>c>>d;
		
		cout<< 1*((hp+a) < 1 ? 1 : (hp+a)) + 5*((mp+b) < 1 ? 1 : (mp+b)) + 2*((atk+c)<0 ? 0 : (atk+c)) + 2*(def+d)<<'\n';                            
	}
	
	return 0;
}
