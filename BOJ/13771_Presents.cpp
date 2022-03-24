#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<double> arr;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	printf("%.2lf\n", arr[1]);
	
	return 0;
}
