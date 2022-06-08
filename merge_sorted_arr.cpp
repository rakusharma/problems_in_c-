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

			a < b ? ( mi = a,ma = b) : ( mi = b,ma = a);
		}
		void merge_sorted_arr(vector<int>& a, vector<int>& b, vector<int>& merg)
		{

			vector<int>::iterator it1 = a.begin(), it2 = b.begin();
			vector<int>::iterator it;
			int mi, ma;



			int lastmax = 0;
			//for (; it1 != a.end() || it2 != b.end(); ++it1, ++it2) {
			while(1) {

				/*handling cases where the first array or second array has 1 element*/
				if (it1 == a.end()) {
					print(merg);
					vector<int>::iterator t = merg.end();
					cout << *it2 <<" " <<*(t-1) <<"\n";
					if (*it2 < *(t-1)){
						int temp = *(t - 1 );
						merg.pop_back();
						merg.push_back(*it2);
						merg.push_back(temp);
					}
					else {
						merg.push_back(*it2);
					}
					goto loop;
					//break;
				}
				if (it2 == b.end()) {
					vector<int>::iterator t = merg.end();
					if (*it1 < *(t-1)){
						int temp = *(t - 1 );
						merg.pop_back();
						merg.push_back(*it1);
						merg.push_back(temp);
					}
					else {
						merg.push_back(*it1);
					}
					//break;
					goto loop;
				}
				find(*it1, *it2, mi, ma);
				if (!merg.empty()){
					vector<int>::iterator t = merg.end();
					//cout << "*" << mi << " " << *(t - 1) << "\n";
					if (mi <  *(t - 1)) { 
						int temp = *(t - 1 );
						merg.pop_back();
						//print(merg);
						merg.push_back(mi);
						//print(merg);
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
					//print(merg);
				}
loop:
				if (it1 != a.end()) ++it1;
				if (it2 != b.end()) ++it2;

				if (it1 == a.end() && it2 == b.end())break;
     
			}

		}
};

int main()
{
	vector<int> a({2,7,9,11,20}), b({1,4,6,8,12});
	//vector<int> a({1,11}), b({8, 9, 12});
	//vector<int> a({1,11}), b({8, 9, 10,22});
	//vector<int> b({1,11}), a({8, 9, 10});
	vector<int> t;
	Solution s;
	s.print(a);
	s.print(b);
	s.merge_sorted_arr(a,b, t);
	s.print(t);
	return 1;
}
