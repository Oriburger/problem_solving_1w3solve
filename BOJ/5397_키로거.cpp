#include <iostream>
#include <list>
using namespace std;

int t;
string str;
list<char> buffer;
list<char>::iterator it;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t; 
	
	while(t--)
	{
		cin>>str; 
		
		buffer.clear();
		it = buffer.begin();
		
		for(auto &c : str)
		{
			switch(c)
			{
			case '-':
				//가리키고 있는걸 제거, 그 제거 위치 다음을 반환 
				//이전 것을 지워서 백 스페이스 구현 
				if(it != buffer.begin()) 
					it = buffer.erase(--it);
				break;
			case '<':
				if(it != buffer.begin()) it--;
				break;
			case '>':
				if(it != buffer.end()) it++;
				break;
			default:
				//가리키고 있는 앞부분에 삽입
				//it는 원래 숫자를 가리킴 
				buffer.insert(it, c);
				break;
			}
		}
		for(auto &c : buffer)
			cout<<c;
		cout<<'\n';
	}
	
	return 0;
}
