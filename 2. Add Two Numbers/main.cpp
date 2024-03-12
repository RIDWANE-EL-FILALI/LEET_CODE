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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string str1, str2;
        
        // Convert the values of l1 to a string
        while (l1) {
            str1 += std::to_string(l1->val);
            l1 = l1->next;
        }

        // Convert the values of l2 to a string
        while (l2) {
            str2 += std::to_string(l2->val);
            l2 = l2->next;
        }

        // Calculate the sum of the two numbers
        int res = std::stoi(str1) + std::stoi(str2);

        // Convert the result back to a string
        std::string result_string = std::to_string(res);

        ListNode* result = nullptr;
        ListNode* current = nullptr;
        std::reverse(result_string.begin(), result_string.end());

        // Build the resulting linked list from the string representation of the sum
        for (char digit : result_string) {
            if (!result) {
                result = new ListNode(digit - '0');
                current = result;
            } else {
                current->next = new ListNode(digit - '0');
                current = current->next;
            }
        }

        return result;
    }
};
