/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list3,*list_temp,*list3_new,*list3_new1;

    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    if(list1 == NULL || list2 == NULL)
    {
        if(list1 == NULL)
        {
            return list2;
        }
        else
        {
            return list1;
        }
    }

    list3 = (struct ListNode*)(malloc(sizeof(struct ListNode)));
    list_temp = list3;

    if(list1->val > list2->val)
    {
        list3->val = list2->val;
        list3->next = NULL;
        list2 = list2->next;
    }
    else if(list1->val < list2->val)
    {
        list3->val = list1->val;
        list3->next = NULL;
        list1 = list1->next;
    }
    else
    {
        list3->val = list1->val;
        list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
        list3_new->val = list2->val;
        list3->next = list3_new;
        list3_new->next = NULL;
        list1 = list1->next;
        list2 = list2->next;
    }
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val > list2->val)
        {
            list3 = list_temp;
            while(list3->next != NULL)
            {
                list3 = list3->next;
            }
            list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new->val = list2->val;
            list3->next = list3_new;
            list3_new->next = NULL;
            list2 = list2->next;
        }
        else if(list1->val < list2->val)
        {
            list3 = list_temp;
            while(list3->next != NULL)
            {
                list3 = list3->next;
            }
            list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new->val = list1->val;
            list3->next = list3_new;
            list3_new->next = NULL;
            list1 = list1->next;
        }
        else
        {
            list3 = list_temp;
            while(list3->next != NULL)
            {
                list3 = list3->next;
            }
            list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new1 = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new->val = list1->val;
            list3->next = list3_new;
            list3_new1->val = list2->val;
            list3_new->next = list3_new1;
            list3_new1->next = NULL;
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    if(list1 == NULL)
    {
        while(list2 != NULL)
        {
            list3 = list_temp;
            while(list3->next != NULL)
            {
                list3 = list3->next;
            }
            list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new->val = list2->val;
            list3->next = list3_new;
            list3_new->next = NULL;
            list2 = list2->next;
        }
    }
    else if(list2 == NULL)
    {
        while(list1 != NULL)
        {
            list3 = list_temp;
            while(list3->next != NULL)
            {
                list3 = list3->next;
            }
            list3_new = (struct ListNode*)(malloc(sizeof(struct ListNode)));
            list3_new->val = list1->val;
            list3->next = list3_new;
            list3_new->next = NULL;
            list1 = list1->next;
        }
    }
    return list_temp;
}