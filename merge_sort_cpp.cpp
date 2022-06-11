#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int compare(int a, int b)
{
	return(a < b);
}
int decr(int a , int b)
{
	return ( a > b);
}


class Solution {
	public:
		void print(vector<int>& v)
		{
			cout << "array value:  ";
			if (v.empty())
				cout << "empty array\n";
			for (auto i : v)
				cout << i << " ";
			cout << "\n";
		}

		void sort_all(vector<int> &a)
		{
			sort(a.begin(), a.end(), compare);
		}


		void insert(vector<int>& a, vector<int>& b)
		{
			vector<int>::iterator t = b.begin();

			for(; t != b.end(); ++t)
				a.push_back(*t);


		}

		void swap(int& a, int& b)
		{
			int t;
			if (a > b) {
				t = a;
				a = b;
				b = t;
			}
		}

		void ms(vector<int>& n, vector<int>& res)
		{

			int size = n.size();
			vector<int> l, r;

			//3/2 = 1,2 5/2 2,3
			size = n.size() / 2 ;
			vector<int> vl(n.begin(), n.begin() + size);
			vector<int> vr(n.begin()  + size, n.end());
			if (vl.size() > 2) ms(vl, l);
			if (vr.size() > 1) ms(vr, r);
			l = vl;
			r = vr;
			insert(res, l);
			insert(res, r);
			sort_all(res);
		}
};

int main()
{
	Solution s;
	int a[] = {2,1,6,19,29,11,23,12,99,123,12,555,222,888,33,121,12121};
	//int a[] = {1,2,3,4,6};
	vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
	vector<int>t;
	t = v;
	sort(t.begin(), t.end(), decr);
	s.print(t);
	vector<int> r;
	s.ms(v, r);
	s.print(r);
	return 0;
}

