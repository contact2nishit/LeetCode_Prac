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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (list1 || list2) {
            int list1_val = (list1) ? list1->val : 101;
            int list2_val = (list2) ? list2->val : 101;
            cur->val = min(list1_val, list2_val);
            if (list1 && cur->val == list1_val) {
                list1 = list1->next;
            } else if (list2 && cur->val == list2_val) {
                list2 = list2->next;
            }
            if (!list1 && !list2) continue;
            ListNode* newNode = new ListNode();
            cur->next = newNode;
            cur = newNode;
        }
        return head;
    }
};