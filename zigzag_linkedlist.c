char* convert(char* s, int numRows) {
    int i,len = 1,j,k,l,temp1,temp2,temp3,m,*offs,n,p;
    char *temp_str;
    struct list_str
    {
        char x;
        struct list_str *next;
    };
    struct list_str *row[1000],*temp_struct,*start_temp;
    i = 0;
    while(s[i] != '\0')
    {
        len++;
        i++;
    }
    if(len == 2 || (len-1) <= numRows)
    {
        return s;
    }
    for(i = 0 ; i < numRows; i++)
    {
        row[i] = (struct list_str *)malloc(sizeof(struct list_str));
        row[i]->x = s[i];
        row[i]->next = NULL;
    }
    m = numRows; 
    while(m <= (len-1))
    {
        i = (numRows - 2);
        while(i > 0)
        {
            start_temp = row[i];
            while(start_temp->next != NULL)
            {
                start_temp = start_temp->next;
            }
            temp_struct = (struct list_str *)malloc(sizeof(struct list_str));
            temp_struct->x = s[m];
            start_temp->next = temp_struct;
            temp_struct->next = NULL;
            i--;
            m++; 
            if(m >= (len - 1))
            {
                break;
            }   
        }
        if(m >= (len - 1))
        {
            break;
        }
        i = 0;
        while(i < numRows)
        {
            start_temp = row[i];
            while(start_temp->next != NULL)
            {
                start_temp = start_temp->next;
            }
            temp_struct = (struct list_str *)malloc(sizeof(struct list_str));
            temp_struct->x = s[m];
            start_temp->next = temp_struct;
            temp_struct->next = NULL;
            i++;
            m++;
            if(m >= (len - 1))
            {
                break;
            }    
        }
        if(m >= (len - 1))
        {
            break;
        }
    }
    m = 0;
    for(i = 0 ; i < numRows; i++)
    {
        start_temp = row[i];
        while(start_temp->next != NULL)
        {
            s[m] = start_temp->x;
            start_temp = start_temp->next;
            m++;
        }
        s[m] = start_temp->x;
        m++;
    }

    return s;   
}