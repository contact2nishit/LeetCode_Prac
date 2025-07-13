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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* currNode = head;
        int size = 0;
        while (currNode) {
            ++size;
            currNode = currNode->next;
        }
        cout << size << endl;
        if (size == 1) return nullptr;
        if (size == n) {
            return head->next;
        }
        currNode = head;
        for (int i = 1; i < size - n; ++i) {
            currNode = currNode->next;
        }
        currNode->next = currNode->next->next;
        return head;
    }
};