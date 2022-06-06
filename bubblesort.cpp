#include<iostream>

#include<vector>
using namespace std;

class Solution {
	public:

		void print(vector<int>& v )
		{
			vector<int>::iterator i = v.begin();

			for (; i != v.end(); ++i)
				cout << *i <<" ";
			cout << "\n";
		}

		int swap( int &a, int& b)
		{
			int t;
			int swap = 0;
			if ( a > b ) {
				t = b;
				b = a;
				a = t; 
				swap = 1;
			}	
			return swap;
		}
		void bubblesort(vector<int>& v)
		{
			vector<int>::iterator p = v.begin();
			int sw = 0;

			for(int _i = 0; _i < v.size() - 1; ++_i) {
				p = v.begin();
				sw = 0;
			for(int i = 0; i < v.size() -  _i - 1; ++i) {
				sw = swap(*(p + i), *(p + i + 1));
				//print(v);
			}

			if (!sw) break;
			
			}

		}
};

int main()
{

	vector<int> x({9,8,7,1});
	Solution s;
	s.print(x);
	s.bubblesort(x);
	s.print(x);
	return 1;
}
