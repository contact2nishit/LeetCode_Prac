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
    void reorderList(ListNode* head) {
        ListNode* currNode = head;
        int full_size = 0;
        while (currNode != nullptr) {
            ++full_size;
            currNode = currNode->next;
        }
        if (full_size == 1) return;
        currNode = head;
        for(int i = 0; i < full_size/2; ++i) {
            if (i == full_size/2 - 1) {
                ListNode* temp = currNode;
                currNode = currNode->next;
                temp->next = nullptr;
                continue;
            }
            currNode = currNode->next;
        }
        ListNode* prev = nullptr;
        //reverse second half
        while(currNode != nullptr) {
            ListNode* temp = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = temp;
        }
        bool fromL1 = true;
        currNode = head;
        while (currNode) {
            ListNode* temp = prev->next;
            prev->next = currNode->next;
            currNode->next = prev;
            prev = temp;
            if (!currNode->next->next) {
                currNode->next->next = prev;
                break;
            }
            currNode = currNode->next->next;
        }
    }
};