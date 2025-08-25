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
    ListNode *oddEvenList(ListNode *head) {
        ListNode oddHead = ListNode();
        ListNode evenHead = ListNode();

        auto oddHeadIndexPtr = &oddHead;
        auto evenHeadIndexPtr = &evenHead;

        bool dealWithOdd = true;
        while (head) {
            if (dealWithOdd) {
                dealWithOdd = false;
                oddHeadIndexPtr->next = head;
                head = head->next;
                oddHeadIndexPtr = oddHeadIndexPtr->next;
                oddHeadIndexPtr->next = nullptr;
            } else {
                dealWithOdd = true;
                evenHeadIndexPtr->next = head;
                head = head->next;
                evenHeadIndexPtr = evenHeadIndexPtr->next;
                evenHeadIndexPtr->next = nullptr;
            }
        }

        oddHeadIndexPtr->next = evenHead.next;
        return oddHead.next;
    }
};
