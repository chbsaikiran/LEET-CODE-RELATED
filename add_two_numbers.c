/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *l1_ptr,*l2_ptr,*l3_ptr,*l3,*l3_temp;
    int len1 = 0,len2 = 0,carry = 0,len_max,len_min,i;

    l1_ptr = (struct ListNode*)(l1);
    l2_ptr = (struct ListNode*)(l2);

    while(l1_ptr != NULL)
    {
        l1_ptr = l1_ptr->next;
        len1++;
    }
    while(l2_ptr != NULL)
    {
        l2_ptr = l2_ptr->next;
        len2++;
    }

    len_max = len1 > len2 ? len1 : len2;
    len_min = len1 < len2 ? len1 : len2;

    l1_ptr = (struct ListNode*)(l1);
    l2_ptr = (struct ListNode*)(l2);
    l3_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3 = l3_ptr;

    for(i = 0 ; i < len_min; i++)
    {
        carry = l1_ptr->val + l2_ptr->val + carry;
        l3_ptr->val = carry%10;
        carry = carry/10;
        l1_ptr = l1_ptr->next;
        l2_ptr = l2_ptr->next;
        l3_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3_temp = l3_ptr;
        l3_ptr = l3_ptr->next;
    }

    if(len_max == len1)
    {
        for (i = 0; i < (len_max - len_min); i++)
        {
            carry = l1_ptr->val + carry;
            l3_ptr->val = carry%10;
            carry = carry/10;
            l3_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3_temp = l3_ptr;
            l3_ptr = l3_ptr->next;
            l1_ptr = l1_ptr->next;
        }
    }
    else
    {
       for (i = 0; i < (len_max - len_min); i++)
        {
            carry = l2_ptr->val + carry;
            l3_ptr->val = carry%10;
            carry = carry/10;
            l3_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3_temp = l3_ptr;
            l3_ptr = l3_ptr->next;
            l2_ptr = l2_ptr->next;
        } 
    }

    if(carry == 0)
    {
        free(l3_ptr);
        l3_temp->next = NULL;
    }
    else
    {
        l3_ptr->val = carry;
        l3_ptr->next = NULL;
    }
    return l3;
}