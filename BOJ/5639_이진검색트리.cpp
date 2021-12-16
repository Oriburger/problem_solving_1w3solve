#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr, ans;

void Answer(int l, int r)
{
	ans.push_back(arr[l]);
	if(l==r) return;

	int sl=l+1, sr=r, bl=l+1, br=r;

	for(int i=l; i<=r; i++)
	{
		if(arr[l]<arr[i])
		{
			bl=i;
			sr=i-1;
			break;
		}
	}
	
	if(sl != bl || sr != br) Answer(bl, br);
	if(sl <= sr) Answer(sl, sr);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;
		if(cin.eof()) break;
		arr.push_back(n);
	}

	Answer(0, arr.size()-1);

	for(int i=ans.size()-1; i>=0; i--)
		cout<<ans[i]<<'\n';

	return 0;
}
