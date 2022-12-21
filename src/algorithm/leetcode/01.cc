#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nmap;
        int idx = 0;
        for (auto v: nums) {
            auto another = nmap.find(target-v);
            if (another != nmap.end()) {
                return {idx, (*another).second};
            }
            nmap[v] = idx++;
        }
        
        return {};
    }
};