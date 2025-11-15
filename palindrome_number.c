bool isPalindrome(long long x) {
    long long y = 0,temp,x1 = x;
    if(x < 0)
    {
        return 0;
    }
    while(x)
    {
        temp = x%10;
        y += temp;
        x = x/10;
        if(x)
        {
            y = y * 10; 
        }
    }
    if(y == x1)
        return 1;
    else
        return 0;
}