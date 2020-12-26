#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str; 
	cin>>str;

	if(str=="A+") cout<<"4.3"<<'\n';
	else if(str=="A0") cout<<"4.0"<<'\n';
	else if(str=="A-") cout<<"3.7"<<'\n';
	else if(str=="B+") cout<<"3.3"<<'\n';
	else if(str=="B0") cout<<"3.0"<<'\n';
	else if(str=="B-") cout<<"2.7"<<'\n';
	else if(str=="C+") cout<<"2.3"<<'\n';
	else if(str=="C0") cout<<"2.0"<<'\n';
	else if(str=="C-") cout<<"1.7"<<'\n';
	else if(str=="D+") cout<<"1.3"<<'\n';
	else if(str=="D0") cout<<"1.0"<<'\n';
	else if(str=="D-") cout<<"0.7"<<'\n';
	else if(str=="F") cout<<"0.0"<<'\n';

	return 0;
}
