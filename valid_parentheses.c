bool isValid(char* s) {
    char *arr_str;
    int i,len = 1,top;
    i = 0;
    while(s[i] != '\0')
    {
        len++;
        i++;
    }
    if(len == 2 || s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }
    arr_str = (char*)(malloc(len*sizeof(char)));

    i = 0;
    top = 0;
    while(s[i] != '\0')
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            arr_str[top] = s[i];
            top++;
        }
        else
        {
            top--;
            if(top < 0)
            {
                return false;
            }
            if(arr_str[top] == '(' && s[i] == ')')
            {
                i++;
                continue;
            }
            else if(arr_str[top] == '{' && s[i] == '}')
            {
                i++;
                continue;
            }
            else if(arr_str[top] == '[' && s[i] == ']')
            {
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if(top == 0)
    {
        return true;  
    }
    else
    {
        return false;
    } 
}