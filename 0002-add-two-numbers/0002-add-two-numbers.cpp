using namespace std;
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
    size_t toNumber(ListNode* l) {
    size_t number = 0;
    int counter = 0;
    while (l != nullptr) {
        number += (l->val)*pow(10,counter);
        l = l->next;
        counter++;
    }
    return number;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = new ListNode();
        ListNode* cur_node = first;
        bool carry = false;
        while ((l1->val + l2->val + carry > 0) || ((l1->next!=nullptr) || (l2->next != nullptr))) {
            int sum = l1->val + l2->val + carry;
            if (sum > 9) {
                sum = sum%10;
                carry = true;
            } else {
                carry = false;
            }
            cur_node->val = sum;
            if (l1->next == nullptr) {
                l1->val = 0;
            } else {
                l1 = l1->next;
            }
            if (l2->next == nullptr) {
                l2->val = 0;
            } else {
                l2 = l2->next;
            }
            if ((l1->val + l2->val + carry > 0)|| ((l1->next!=nullptr) || (l2->next != nullptr))) {
                cur_node->next = new ListNode(sum);
            }
            cur_node = cur_node->next;
        }
        return first;
    }
};