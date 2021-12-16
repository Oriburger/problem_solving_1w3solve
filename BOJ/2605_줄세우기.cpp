#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, input;
deque<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>input;

		if(i>1 && input==i-1)
			s.push_front(i);

		else
		{
			deque<int>::iterator iterPos=s.end();
			for(int j=0; j<input; j++, iterPos--) { }
			s.insert(iterPos, i);
		}
	}

	for(deque<int>::iterator iterPos=s.begin(); 
		iterPos!=s.end(); iterPos++)
		cout<<*iterPos<<' ';

	return 0;
}
