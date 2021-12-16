#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int n;
double sum;
vector<int> arr;
vector<P> check(8001, {0, 0});

bool Comp(const P a, const P b)
{
	if(a.first > b.first) return true;
	else if(a.first < b.first) return false;
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	scanf("%d", &n);

	arr.resize(n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];

		if(arr[i]<0) 
			check[abs(arr[i])+4000] = {check[abs(arr[i])+4000].first+1, arr[i]};
		else 
			check[arr[i]] = {check[arr[i]].first+1, arr[i]};
	}

	sort(arr.begin(), arr.end());
	sort(check.begin(), check.end(), Comp);

	//--산술평균--

	printf("%.0lf\n", round(sum/(double)n));

	//--중앙값--
	printf("%d\n",arr[n/2]);

	//--최빈값--
	int cnt=0;

	if(check[0].first > check[1].first) 
		printf("%d\n", check[0].second);
	else if(check[1].first == check[0].first )
		printf("%d\n", check[1].second);

	//--범위--
	printf("%d\n", arr[n-1]-arr[0]);

	return 0;
}
