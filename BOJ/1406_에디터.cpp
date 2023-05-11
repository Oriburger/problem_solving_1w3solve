#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    string str; int n;
    stack<char> left, right;

	cin>>str>>n;
    reverse(str.begin(), str.end());
    while(str.size())
    {
        left.push(str.back());
        str.pop_back();
    }

	for(int i=0; i<n; i++)
	{
		char c, k;
		cin>>c; 
		switch(c)
		{
		case 'L':
            if(left.empty()) continue;
            right.push(left.top());
            left.pop();
            break;
		case 'D':
            if(right.empty()) continue;
            left.push(right.top());
            right.pop();
			break;
		case 'B':
            if(left.empty()) continue;
            left.pop();
			break;
		case 'P':
			cin>>k;
            left.push(k);
			break;
		}
	}
    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty())
    {
        cout<<right.top();
        right.pop();
    }

	return 0;
}
