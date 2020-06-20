#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
vector<double> sides;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1)
	{
		for(int i=0; i<3; i++)
		{
			int input;
			cin>>input;
			if(input==0) 
				cnt++;
			sides.push_back(input);
		}
		if(cnt==3) 
			break;
			
		sort(sides.begin(), sides.end());
		
		if(pow(sides[2],2.0) 
			== pow(sides[1], 2.0) + pow(sides[0], 2.0))
			cout<<"right\n";
		
		else
			cout<<"wrong\n";
		
		sides.clear();
		cnt=0;
	}
	return 0;
}
