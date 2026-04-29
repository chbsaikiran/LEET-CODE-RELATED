/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {

    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;
    
    struct ListNode* temp;
    int temp_val;

    temp = head;

    while(temp != NULL)
    {
        if(temp->next == NULL)
            return head;
        
        temp_val = temp->next->val;
        temp->next->val = temp->val;
        temp->val = temp_val;

        if(temp->next != NULL)
            temp = temp->next->next;
        else
            return head;
    }

    return head;
    
}
