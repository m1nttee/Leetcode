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
        // 2. 截断后半部分链表
        // 3. 反转后半部分链表
        // 4. 双指针同时遍历两个链表，然后计算最大值
    }
};
