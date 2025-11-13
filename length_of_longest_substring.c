int lengthOfLongestSubstring(char* s) {

    int i,j,cnt = 0,k = 0,cnt_max = 0,k1;

    if(s[0] == '\0')
    {
        return 0;
    }
    if(s[1] == '\0')
    {
        return 1;
    }
    for(i = 1; s[i] != '\0';i++)
    {
        cnt = 1;
        for(j = k ; j < i; j++)
        {
            if(s[j] != s[i])
            {
                cnt++;
            }
            else
            {
                if(cnt_max < cnt)
                {
                    cnt_max = cnt;
                }
                k = j;
                break;
            }
        }
        k1 = k;
        for ( j = k; j < i; j++)
        {
            if(s[j] == s[i])
            {
                k1++;
            }
        }
        k = k1;
        if(cnt_max < cnt)
        {
            cnt_max = cnt;
        }
    }

    return cnt_max;
    
}