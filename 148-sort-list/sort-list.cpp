class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }

        cur->next = a ? a : b;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};