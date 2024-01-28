#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
vector<P> d = { {0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0} };
const vector<int> offset = {1, 0, 1, 1, 1, 1};

int getAnswer(int a, int b)
{
	P st = {0, 0};
	if(a+b == 0) return 1;
	
	int count = 0;
	for(int i=1; i<1e4; i++)
	{		
		for(int j=0; j<6; j++)
		{
			for(int k=1; k<offset[j] + i; k++) 
			{
				st.first += d[j].first;
				st.second += d[j].second;
				
				count += 1;
				if(st == P(a, b)) return count+1;
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int a, b; 
	cin>>a>>b; 
	
	cout<<getAnswer(a, b)<<'\n';
	
	return 0;
}
