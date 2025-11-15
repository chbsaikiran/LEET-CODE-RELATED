char* longestCommonPrefix(char** strs, int strsSize) {
    char *out,ch;
    int i,j,k = 0,small_len = 1000;
    
    for (i = 0; i < strsSize; i++)
    {
        j = 0;
        while(strs[i][j] != '\0')
        {
            j++;
        }
        if((j) < small_len)
        {
           small_len = (j); 
        }
    }
    if(strsSize == 1)
    {
        k = 0;
        while(strs[0][k] != '\0')
        {
            k++;
        }
        out = (char*)malloc((k+1));
        for ( i = 0 ; i < k; i ++)
        {
            out[i] = strs[0][i];
        }
        out[i] = '\0';
        return out;
    }
    else if(strsSize == 2)
    {
        k = 0;
        for(i = 0 ; i < small_len; i++)
        {
            if(strs[0][i] == strs[1][i])
            {
                k++;
            }
            else
            {
                break;
            }
        }
        out = (char*)malloc((k+1));
        for ( i = 0 ; i < k; i ++)
        {
            out[i] = strs[0][i];
        }
        out[i] = '\0';
        return out;
    }
    for ( i = 0 ; i <= small_len ; i++)
    {
        ch = strs[0][i];
        if(ch == '\0')
        {
            break;
        }
        if(ch != '\0')
        {
            for (j = 1 ; j < (strsSize); j++)
            {
                if(strs[j][i] == '\0')
                {
                    break;
                }
                if(ch != strs[j][i])
                {
                    break;
                }
            }
        
            if(j == (strsSize))
            {
                k++;
            }
            else
            {
                break;
            }
        }  
    }

    if(k == 0)
    {
        out = "";
    }
    else
    {
        out = (char*)malloc((k+1));
        for ( i = 0 ; i < k; i ++)
        {
            out[i] = strs[0][i];
        }
        out[i] = '\0';
    }

    return out;
    
}