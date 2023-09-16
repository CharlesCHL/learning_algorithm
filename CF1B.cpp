

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string trans_1(string);
string trans_2(string);
string trans_3(int);

int main(void)
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1;
		cin >> s1;
		string s2;
		if (s1[0] == 'R')
			s2 = trans_1(s1);
		else 
			s2 = trans_2(s1);
		cout << s2 << endl;
	}


	return 0;

}

string trans_1(string str)
{
	int i = str.find('C');
	int n1, n2;
	string s1 = str.substr(1, i - 1);
	string s2 = str.substr(i + 1, str.length() - i - 1);
	stringstream ss_2(s2);
	ss_2 >> n2;

	string ans = trans_3(n2) + s1;
	return ans;	
}

string trans_2(string str)
{

	return "222";
}


string mp = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
string trans_3(int a){
    string ans = "";
    while(a){
        bool spec = a%26==0;
        ans = mp[a%26] + ans;
        a/=26;
        if(a>0 && spec) --a;
    }
    return ans;
}




