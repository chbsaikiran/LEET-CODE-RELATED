int strStr(char* haystack, char* needle) {
    char *ptr1 = haystack,*ptr2 = needle,*ptr3;
    int i = 0;

    while(*ptr1 != '\0')
    {
        ptr3 = ptr1;
        while(*ptr1 == *ptr2 && *ptr2 != '\0' && *ptr1 != '\0')
        {
            ptr1++;
            ptr2++;
        }
        if(*ptr2 != '\0')
        {
            if(*ptr1 == '\0')
            {
                return -1;
            }
            ptr3++;
            ptr2 = needle;
            ptr1 = ptr3;
            i = (int)(ptr1 - haystack);
        }
        else
        {
            return i;     
        }
    }

    return -1;   
}