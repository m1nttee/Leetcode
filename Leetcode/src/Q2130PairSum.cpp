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

class Solution {
public:
    int pairSum(ListNode *head) {
        // 1. 找到中间点
        ListNode *node1 = head, *node2 = head->next->next;
        while (node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next->next;
        }
        // 2. 截断后半部分链表
        ListNode *toReverseList = node1->next;
        node1->next = nullptr;
        // 3. 反转后半部分链表
        if (toReverseList == nullptr || toReverseList->next == nullptr) {
        } else if (toReverseList->next->next == nullptr) {
            ListNode *first = toReverseList, *second = toReverseList->next;
            toReverseList = second;
            second->next = first;
            first->next = nullptr;
        } else {
            ListNode *newList = toReverseList;
            ListNode *second = toReverseList->next, *third = toReverseList->next->next;
            while (third != nullptr) {
                second->next = newList;
                newList = second;
                second = third;
                third = third->next;
            }
            second->next = newList;
            newList = second;
            toReverseList = newList;
        }
        // 4. 双指针同时遍历两个链表，然后计算最大值
        node1 = head;
        node2 = toReverseList;

        int maxSum = 0;
        while (node1 != nullptr) {
            int sum = node1->val + node2->val;
            if (sum > maxSum) {
                maxSum = sum;
            }
            node1 = node1->next;
            node2 = node2->next;
        }

        return maxSum;
    }
};
