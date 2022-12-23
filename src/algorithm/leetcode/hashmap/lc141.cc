/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include <memory>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> nodemap;

        ListNode *current = head;
        while (current != nullptr) {
            if (nodemap.find(current) != nodemap.end()) {
                return true;
            }
            nodemap.insert(current);
            current = current->next;
        }
        return false;
    }

    /* fast-slow pointers */
    bool hasCycle2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};