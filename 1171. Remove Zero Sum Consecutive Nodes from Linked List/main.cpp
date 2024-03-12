/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// we'll follow some given hints and convert the list into a vector for an effective access and calculate the sum if it's == 0 then we delete the elements.
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::vector<int> tmp;
        
        // Convert linked list to vector
        while (head) {
            tmp.push_back(head->val);
            head = head->next;
        }
        int sum = 0;
        for (size_t i = 0; i < tmp.size(); i++) {
            sum = 0;
            for (size_t j = i; j < tmp.size(); j++) {
                sum += tmp[j];
                if (sum == 0) {
                    tmp.erase(tmp.begin() + i, tmp.begin() + j + 1);
                    i--;  // Adjust i to recheck the merged sequence
                    break;
                }
            }
        }
        // Convert vector back to linked list
        ListNode* result = nullptr;
        ListNode* current = nullptr;

        for (int value : tmp) {
            if (!result) {
                result = new ListNode(value);
                current = result;
            } else {
                current->next = new ListNode(value);
                current = current->next;
            }
        }

        return result;
    }
};
