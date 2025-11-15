int reverse(int x){
    long long y = 0;

    while( x != 0)
    {
        y *= 10;
        y += (x % 10);
        x = (x/10);
    }

    if(y > 2147483647 || y < -2147483648)
    {
        y = 0;
    }
    return ((int)y);
}