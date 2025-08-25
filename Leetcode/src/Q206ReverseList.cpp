//
// Created by Mingtian Chen on 2025/5/8.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            auto second = head->next;
            second->next = head;
            head->next = nullptr;
            return second;
        }

        auto first = head;
        auto second = head->next;
        auto third = second->next;

        while (third != nullptr) {
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        head->next = nullptr;
        return second;
    }
};