#include<iostream>
#include<vector>

using namespace std;


class Solution {

	public :
		void print(vector<int>& v )
		{
			vector<int>::iterator i;
			cout<<"array: ->  ";
			for (i = v.begin(); i != v.end(); ++i)
				cout<< *i <<" ";
			cout<<"\n";
		}
		void find(int a, int b, int& mi, int& ma)
		{

#if 0
			if (a < b) {
				mi = a;
				ma = b;
			}
			else {
				mi = b;
				ma = a;
			}
#endif
			a < b ? ( mi = a,ma = b) : ( mi = b,ma = a);
			//cout << a <<"  "<<"  " <<b <<" " <<mi <<" "<< ma <<"\n"; 
		}
		void merge_sorted_arr(vector<int>& a, vector<int>& b, vector<int>& merg)
		{

			vector<int>::iterator it1 = a.begin(), it2 = b.begin();
			vector<int>::iterator it;
			int mi, ma;



			int lastmax = 0;
			for (; it1 != a.end(); ++it1, ++it2) {

				find(*it1, *it2, mi, ma);
				//cout <<"min " <<mi <<"max "<<ma << "it1 " << *it1 << "it2 "<< *it2<< "\n";
				//
				if (!merg.empty()){
					vector<int>::iterator t = merg.end();
					cout << "*" << mi << " " << *(t - 1) << "\n";
					if (mi <  *(t - 1)) { 
						int temp = *(t - 1 );
						merg.pop_back();
						print(merg);
						merg.push_back(mi);
						print(merg);
						if (temp < ma)  {
							merg.push_back(temp);
							merg.push_back(ma);
						}
						else {
							merg.push_back(ma);
							merg.push_back(temp);
						}

					}
					else {
				merg.push_back(mi);
				merg.push_back(ma);
					}
				}
				else {
				merg.push_back(mi);
				merg.push_back(ma);
				print(merg);
				}

					
			}

		}
};


int main()
{
	vector<int> a({2,7,9,11,20}), b({1,4,6,8,12});
	vector<int> t;
	Solution s;
	s.print(a);
	s.print(b);
	s.merge_sorted_arr(a,b, t);
	s.print(t);
	return 1;
}
