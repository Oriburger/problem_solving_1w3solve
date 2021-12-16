#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int neg = 0, pos = 0, zero = 0;
deque<int> arr;

int GetAndPop(bool bIsFront)  //deque의 앞과 뒤에서 데이터를 뽑아옴
{
	int ret = (bIsFront ? arr.front() : arr.back()); 
	if(bIsFront) arr.pop_front();
	else arr.pop_back();
	return ret;
}

int main()
{
	ios::sync_with_stdio(false); // IO 최적화
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int tmp; cin>>tmp;
		arr.push_back(tmp);

		neg += (tmp<0); //음수의 개수
		pos += (tmp>0); //양수의 개수
		zero += (tmp==0); //0의 개수 (boolean으로 둬도 괜찮을듯)
	}
	sort(arr.begin(), arr.end());

	for(int sel=0; sel<=1; sel++) //양수, 음수 순으로 더함
	{
		const int curr = (sel ? neg : pos); 
		for(int i=0; i<curr/2; i++) //2개씩 짝을 지어 곱해서 더함
		{
			int mul[2]={}; //짝 지을 값들을 넣을 배열
			for(int j=0; j<2; j++)
				mul[j] = GetAndPop(sel);
			ans += max(mul[0]*mul[1], mul[0]+mul[1]); //반례! 더하는게 더 클 수도 있음
		}
		if(curr%2==1) //나머지를 더함
		{
			if(sel==0) ans += GetAndPop(sel); //양수가 하나 남았을 경우 그냥 더한다
			else ans += (zero > 0 ? 0 : GetAndPop(sel)); //0이 있다면 0으로 만들어서 더함
		}
	}
	cout<<ans<<'\n';

	return 0;
}
