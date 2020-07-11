#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{ int y; int x; };

bool CompPos(Pos a, Pos b)
{
	if(a.x < b.x) return true;

	else if(a.x > b.x) return false;

	else 
	{
		if(a.y < b.y) return true;

		else if(a.y > b.y) return false;
	}

	return false;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<Pos> arr(n);

	for(int i=0; i<n; i++)
		cin>>arr[i].x>>arr[i].y;

	sort(arr.begin(), arr.end(), CompPos);

	for(int i=0; i<n; i++)
		cout<<arr[i].x<<' '<<arr[i].y<<'\n';

	return 0;
}
