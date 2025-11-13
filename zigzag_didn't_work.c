char* convert(char* s, int numRows) {
    int i,len = 1,j,k,l,temp,m,*offs,n,p;
    char *temp_str;

    i = 0;
    while(s[i] != '\0')
    {
        len++;
        i++;
    }

    if(len == 2 || (len-1) == numRows)
    {
        return s;
    }

    temp_str = (char*)malloc(len);
    i = 0;
    while(s[i] != '\0')
    {
        temp_str[i] = s[i];
        i++;
    }
    temp_str[i] = '\0';
    if(numRows > 3)
    {
        offs = (int*)(malloc((2*(numRows-2)+2)*sizeof(int)));
        offs[0] = (numRows - 1)*2;
        offs[2*(numRows-2)+1] = (numRows - 1)*2;

        for(i = 0 ; i < (numRows-2); i++)
        {
            if(i % 2 == 0)
            {
                offs[2*i+1] = (numRows - 1)*2 - 2*(i+1);
                offs[2*i+2] = offs[2*i+1] - 2;
            }
            else
            {
                offs[2*i+1] = (numRows - 1)*2 - 2*(i+1);
                offs[2*i+2] = offs[2*i+1] + 2;
            }
        }
    }
    else if(numRows >= 2)
    {
        offs = (int*)(malloc((2*(numRows-2)+2)*sizeof(int)));
        offs[0] = (numRows - 1)*2;
        offs[2*(numRows-2)+1] = (numRows - 1)*2;
        offs[1] = 2;
        offs[2] = 2;
    }
    else
    {
        offs = (int*)(malloc(sizeof(int)));
    }

    if(numRows == 1 || len == 1)
    {
        return s;
    }

    k = 0;
    m = len - 1;
    p = 0;
    for(j = 0 ; j < numRows; j++)
    {
        if(j != 0 && j != (numRows-1))
        {
            l = j;
            m = len - 1;
            while( k < (len-1) && m > 0)
            {
                for(n = (j+p) ; n < (j  + 2 + p) && k < (len-1) && m > 0; n++)
                {
                    s[k] = temp_str[l];
                    k++;
                    l = l + offs[n];
                    m = len - 1 - l;
                }
            }
            p++;

        }
        else
        {
            l = j;
            m = len - 1;
            while( k < (len-1) && m > 0)
            {
                s[k] = temp_str[l];
                k++;
                l = l + offs[2*(numRows-2)+1];
                m = len - 1 - l;
            }
        }
    }
    s[k] = '\0';

    free(temp_str);
    free(offs);

    return s;  
}