#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


/*solution: https://leetcode.com/problems/two-sum*/


using namespace std;
class Sol {
	public:

		vector<int> twosum_o(vector<int>& nums, int target)
		{
			vector<int>::iterator it = nums.begin();
			sort(nums.begin(), nums.end());
			t = target - *it;
			for (it = it + 1; it != nums.end(); ++it){
				if t 
			}

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
				if ( *it == *nexti && i == j) continue;
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

	r = s.twosum(i, 9);
	cout<<"[ ";
	for(it = r.begin(); it !=r.end(); ++it)
		cout << *it <<" ";
	cout<<"]";
	cout<<"\n";

	return 1;
}
