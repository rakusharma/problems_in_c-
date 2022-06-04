#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>


/*solution: https://leetcode.com/problems/two-sum*/


using namespace std;
class Sol {
	public:

		vector<int> twosum_o(vector<int>& nums, int target)
		{
			vector<int>::iterator it = nums.begin();
			sort(nums.begin(), nums.end());
			vector<int> sums;

			//{2,3,11,16}, 27  2,25 3,24 11,16 16,11
			map<int, int> m;
			int t, i=0;
			for (it = it ; it != nums.end(); ++it, ++i){
				 t  = target - *it;
				 m[t] = *it;
			}


			size_t f;

			for (it = nums.begin(), i = 0; it != nums.end(); ++it, ++i){
				if ( (f = m.count(*it)) > 0) {

					sums.push_back(*it);
					sums.push_back(target - *it);
					break;

				}
			}

			return sums;

		}
		vector<int> twosum(vector<int>& nums, int target)
		{

			sort(nums.begin(), nums.end());
			vector<int>::iterator it = nums.begin(), next = it;
			int i = 0, j = 0;
			vector<int> sums;
			int s;

			for (; it != nums.end(); ++it,++i)
			for (; next != nums.end(); ++next, ++j) {
				if (*it > target) break;
				if ( *it == *next && i == j) continue;
				s = *it + *next;

				if (s == target) {
					sums.push_back(i);
					sums.push_back(j);
					break;
				}
				else if (s > target)
					//options are exhausted. why to loop more
					break;
			}

			return sums;



		}
};

int main()
{

	Sol s;
	int x[] = {2,7,11,15};
	//int x[] = {3, 2, 4};
	int t = 9;
	vector<int> i(x, x + sizeof(x)/sizeof(x[0])), r;
	vector<int>::iterator it;

	r = s.twosum_o(i, 9);
	cout<<"[ ";
	for(it = r.begin(); it !=r.end(); ++it)
		cout << *it <<" ";
	cout<<"]";
	cout<<"\n";

	return 1;
}
