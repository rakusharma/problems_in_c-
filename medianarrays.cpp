#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
	public:
		double find_median_arrays(vector<int>& nums1, vector<int>& nums2)
		{

			vector<int>::iterator it = nums1.begin(), it2 = nums2.begin();
			vector<int> merg(nums1);
			//[1, 3] [2,4]
			//[1,3] [2]
			//
			/*
			for (; it2 != nums2.end(); ++it2) {
				merg.push_back(*it2);
			}
			*/

			merg.insert(merg.end(), nums2.begin(), nums2.end());

			sort(merg.begin(), merg.end());
			it = merg.begin();

			for (; it != merg.end(); ++it) {
				cout << *it <<" ";
			}

			int size = merg.size();

			

			if (size % 2 != 0) return merg[size/2];

			double x =  merg[size/2 -1];
			double y =  merg[size/2];
			return (x + y)/2;

		}
};


int main()
{

	Solution s;
	int s1[] = {1,3};
	int s2[] = {2, 4};
	vector<int> x(s1, s1 + sizeof(s1)/sizeof(s1[0])), y(s2, s2 + sizeof(s2)/sizeof(s2[0]));
	cout << "median" << s.find_median_arrays(x, y);
	return 0;
}
