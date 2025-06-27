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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev_node = new ListNode(head->val, nullptr) ;
        ListNode* curr_node = head->next;
        while (curr_node != nullptr) {
            ListNode* new_node = new ListNode(curr_node->val, prev_node);
            prev_node = new_node;
            curr_node = curr_node->next;
        }
        return prev_node;
    }
};