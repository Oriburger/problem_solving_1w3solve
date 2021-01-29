#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> GetPartialMatch(const string &str)
{
	int m = str.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while(begin + matched < m)
	{
		if(str[begin + matched] == str[matched])
		{
			matched++;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if(matched == 0) begin++;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi;
}

//'짚더미' h의 부분 문자열로 '바늘'n이 출현하는 시작 위치 집합을 반환
vector<int> kmpSearch(const string &h, const string &n)
{
	int hlen = h.size(), nlen = n.size();
	vector<int> ret;
	
	//pi[i]=n[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = GetPartialMatch(n);

	//begin = matched = 0 에서부터 시작
	int begin = 0, matched = 0;
	while(begin <= hlen - nlen)
	{
		//만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if(matched < nlen && h[begin + matched] == n[matched])
		{
			matched++;
			//결과적으로 nlen 글자가 모두 일치했다면 답에 추가
			if(matched == nlen) ret.push_back(begin);
		}
		else
		{
			//예외 : matched가 0인 경우에는 다음 칸에서부터 계속
			if(matched == 0) begin++;
			else 
			{
				begin += matched - pi[matched-1];
				//begin을 옮겼다고 처음부터 다시 비교할 필요는 없다.
				//옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문.
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string h, n;

	getline(cin, h);
	getline(cin, n);

	vector<int> ans = kmpSearch(h, n);
	
	cout<<ans.size()<<'\n';
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]+1<<' ';

	return 0;
}
