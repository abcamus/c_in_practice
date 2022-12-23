/*
 * https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto k: nums1) {
            if (m.find(k) != m.end()) {
                m[k] += 1;
            } else {
                m[k] = 1;
            }
        }

        vector<int> ans;
        for (auto k: nums2) {
            if (m.find(k) != m.end()) {
                if (m[k] > 0) {
                    ans.push_back(k);
                    m[k] -= 1;
                }
            }
        }
        return ans;
    }
};