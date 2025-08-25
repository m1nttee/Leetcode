//
// Created by Mingtian Chen on 2025/5/8.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

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
    ListNode *deleteMiddle(ListNode *head) {
        // 1 element case
        if (head->next == nullptr) {
            return nullptr;
        }

        auto indexHead = head;
        auto centerNode = head;
        int count = -1;
        while (indexHead->next != nullptr) {
            indexHead = indexHead->next;
            count++;
            if (count >= 2) {
                count = 0;
                // 第二次
                centerNode = centerNode->next;
            } else {
                // 第一次
                // 不更新 centerNode
            }
        }
        // remove centerNode's next
        auto temp = centerNode->next;
        if (temp != nullptr) {
            centerNode->next = temp->next;
            temp->next = nullptr;
        }
        return head;
    }
};
