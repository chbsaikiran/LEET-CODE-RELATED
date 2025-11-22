int divide(int dividend, int divisor) {
    int temp1, temp2, quetiont = 0, saturated = 0;

    if((dividend == 2147483647) && (divisor == -2147483648))
    {
        return 0;
    }
    if(dividend == 2147483647)
    {
        if(divisor == 1)
        {
            return 2147483647;
        }
        else if(divisor == -1)
        {
            return -2147483647;
        }
    }

    if(dividend == -2147483648)
    {
        temp1 = 2147483647;
        saturated = 1;
    }
    else
    {
        temp1 = dividend > 0 ? dividend : (0-dividend);
    }

    if(divisor == -2147483648)
    {
        temp2 = 2147483647;
    }
    else
    {
        temp2 = divisor > 0 ? divisor : (0-divisor);
    }
    if(saturated)
    {
        if(divisor == 1)
        {
            quetiont = -2147483648;
            return quetiont;
        }
        else if(divisor == -1)
        {
            quetiont = 2147483647;
            return quetiont;
        }
        else if(divisor == -2147483648)
        {
            quetiont = 1;
            return quetiont;
        }
    }

    while(temp1 >= temp2)
    {
        quetiont++;
        temp1 = temp1 - temp2;
    }
    
    if(saturated && temp2 <= (temp1 + 1))
    {
      quetiont++;  
    }
    if(((dividend >> 31) == -1) ^ ((divisor >> 31) == -1))
    {
        quetiont = 0 - quetiont;
    } 
    return quetiont;
}