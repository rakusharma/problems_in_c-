#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
class Sol {
	public:
		vector<int> twosum(vector<int>& nums, int target)
		{

			sort(nums.begin(), nums.end());
			vector<int>::iterator it = nums.begin(), next = it + 1;
			vector<int> sums;
			int s;

			for (; next != nums.end(); ++next) {
				if (*it > target) break;
				s = *it + *next;

				if (s == target) {
					sums.push_back(*it);
					sums.push_back(*next);
					break;
				}
				else if (s > target)
					//options are exhausted. why to loop more
					break;
				else 
					it = next;
			}

			return sums;



		}
};

int main()
{

	Sol s;
	//int x[] = {2,7,11,15};
	int x[] = {3, 2, 4};
	vector<int> i(x, x + sizeof(x)/sizeof(x[0])), r;
	vector<int>::iterator it;

	r = s.twosum(i, 6);

	for(it = r.begin(); it !=r.end(); ++it)
		cout << *it <<" ";
	cout<<"\n";

	return 1;
}
