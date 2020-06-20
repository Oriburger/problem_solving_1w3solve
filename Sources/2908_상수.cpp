/*i can make the messiest code*/

#include <iostream>
#include <string>
using namespace std;

string str1, str2; 
int answer=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>str1>>str2;
	
	str1 = {str1[2],str1[1],str1[0]};
	str2 = {str2[2],str2[1],str2[0]};
	
	cout<< ((str1[0]-'0') > (str2[0]-'0') ? str1
			: (str1[0]-'0') < (str2[0]-'0') ? str2
			: (str1[1]-'0') > (str2[1]-'0') ? str1
			: (str1[1]-'0') < (str2[1]-'0') ? str2
			: (str1[2]-'0') > (str2[2]-'0') ? str1
			: (str1[2]-'0') < (str2[2]-'0') ? str1 : str2) <<'\n';
	
	return 0;
}
