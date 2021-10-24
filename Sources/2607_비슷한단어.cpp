#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans=0;
vector<string> arr;

//s1과 s2이 비슷한 문자열인지를 반환
bool is_similar(string s1, string s2)
{
	vector<int> cnt[2];
	cnt[0] = cnt[1] = vector<int>(29, 0);

	for(int i=0; i<2; i++)
	{
		string target = (i ? s1 : s2);
		for(const char &c : target)
			cnt[i][c-'A']++; //각 문자열의 알파벳 개수를 카운팅
 	}
	
	//(조건)
	// - 두 문자열의 길이차가 2 이상이면 절대 비슷하지 않다
	// - 구성 알파벳의 개수가 2 이상 차이가 나면 비슷하지 않다. 
	
	int diff = abs((int)s1.length()-(int)s2.length()); // 두 문자열의 길이 차
	for(int i=0; i<29; i++)
		diff += abs(cnt[0][i]-cnt[1][i]); //구성 알파벳의 개수 차

	return diff <= 2;
}	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr = vector<string>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	string cmp = arr[0];
	for(int i=1; i<n; i++)
		ans += is_similar(cmp, arr[i]);

	cout<<ans<<'\n';

	return 0;
}
