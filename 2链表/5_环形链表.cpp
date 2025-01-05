ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *s = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (s != slow) {
                s = s->next;
                slow = slow->next;
            }
            return s;
        }
    }
    return NULL;
}