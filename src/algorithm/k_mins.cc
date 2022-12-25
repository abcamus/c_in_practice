#include <vector>
#include <algorithm>

using namespace std;

static bool compare(pair<int, int> &lhs, pair<int, int> &rhs) {
    return lhs.first < rhs.first;
}

vector<int> find_k_mins(vector<int> &list, int k)
{
    /* 时间：O(n)， 空间：O(n) */
    vector<pair<int, int>> l;
    for (int i = 0; i < list.size(); ++i) {
        l.push_back(make_pair(list.at(i), i));
    }
    /* 时间: O(nlogn) */
    sort(l.begin(), l.end(), compare);

    vector<int> ans;
    for (int i = 0; i < min((size_t)k, list.size()); ++i) {
        ans.push_back(l.at(i).second);
    }

    return ans;
}

