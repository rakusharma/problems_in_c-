#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

/*solution of https://leetcode.com/problems/longest-string-chain*/

using namespace std;

struct str_sort {
	bool operator() (const string a, const string b) const
	{
		return a.size() < b.size();
	}
}sort_str;

class Solution {
	public:

		int compare(string a, string b)
		{
			/*xc xyc*/

			string::iterator it = a.begin();
			size_t pos, old;

			pos = b.find_first_of(*it);
			old = pos;
			++it;
			for (; it != a.end(); ++it){

				old = pos;
				pos = b.find_first_of(*it, old);
				/*if char in sequence occur before, quit*/
				if (pos < old || pos == string::npos) return 0;
				old = pos;
			}
			return 1;
		}
		int longest_str_chain(vector<string> &words) 
		{

			vector<string>::iterator it = words.begin();
			vector<string>::iterator next = it + 1;
			int i = 0, c = 0;

			/*
			 *it and next, if it.size() > next.size() move to next pair (it = next, next = ++it)
			 *walk through from first char of it and search in next. if first matches with next, move the 2nd of first in next. 
			 if first of it does not matches with next, abort
			 loop through all first and if all the character matches , increase the count
			 matching algo: Match first character. record the pos in the next. find next of it from the pos of next and so on.
			 */
			for (; next != words.end(); ++next){
				i = compare(*it, *next);
				it = next;
				if (i) ++c;
			}
			return c;

		}
};


int main()
{

	Solution s;
	int count;

	vector<string> v = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
	sort(v.begin(), v.end(), sort_str);
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it <<"  " ;
	cout << "\n";
	count = s.longest_str_chain(v);
	cout << "longest string " << count;

	return 1;

}



