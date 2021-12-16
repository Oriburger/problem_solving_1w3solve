#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> nemo={"NEMO", "NEMo", "NEmO", "NeMO", "nEMO", 
					 "NEmo", "NeMo", "NemO", "nEMo", "nEmO",
					 "neMO", "Nemo", "nEmo", "neMo", "nemO",
					 "nemo"};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;

	while(1)
	{
		getline(cin, str);
		if(str=="EOI") break;

		bool flag = false;

		for(int i=0; i<nemo.size(); i++)
			if(str.find(nemo[i])!=string::npos)
			{
				flag = true;
				break;
			}

		if(flag) cout<<"Found\n";
		else cout<<"Missing\n";
	}



	return 0;
}
