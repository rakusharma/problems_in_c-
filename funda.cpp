#include<iostream>
#include<vector>
#include<string>
using namespace std;

class funda {
	public:

		void check(string a, string b)
		{

			cout << a << b;

		}
		void sol()
		{
			vector<string> s({"hello", "world"});
			//check(*(s.begin()), *(s.end()));
			check(*(s.begin()), *(s.end() - 1));
			
		}
};


int main()
{

	funda f;
	f.sol();

	return 0;
}
