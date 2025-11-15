int myAtoi(char* s) {
    char *p = s,*p1;
    int flag = 1,temp;
    long long number = 0,tens = 1;
    bool saturated = false;

    while (*p == ' ' || *p == '\t')
    {
        p++;
    }
    p1 = p;
    if(*p1 == '-' || *p1 == '+')
    {
        *p1++;
    }

    while(*p1 == '0')
    {
        *p1++;
    }
    while(*p1 == '0' || *p1 == '1' || *p1 == '2' || *p1 == '3' || *p1 == '4'
        || *p1 == '5' || *p1 == '6' || *p1 == '7' || *p1 == '8' || *p1 == '9')
    {
        if(tens > 21474836470)
        {
            break;
        }
        else
        {
            tens *= 10;
        }
        p1++;
    }
    tens = tens/10;
    if(*p == '-' || *p == '+')
    {
        if(*p == '-')
        {
            flag = -1;
        }
        *p++;
    }
    while(*p == '0')
    {
        *p++;
    }
    while(*p != '\0')
    {
        if(*p == '0' || *p == '1' || *p == '2' || *p == '3' || *p == '4'
           || *p == '5' || *p == '6' || *p == '7' || *p == '8' || *p == '9')
        {
            number += ((int)(*p - '0'))*tens;
            if(number > 2147483647)
            {
                number = 2147483647;
                saturated = true;
                break;
            }
            tens /= 10;
            p++;
        }
        else
        {
            break;
        }
    }
    if(flag == -1 && saturated == true)
    {
        number = -2147483648;
    }
    else
    {
        number = number * flag;
    }

    return number;   
}