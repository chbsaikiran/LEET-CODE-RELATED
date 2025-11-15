int removeDuplicates(int* nums, int numsSize) {
    int i,temp,j;

    temp = nums[0];
    j = 0;
    for (i = 1; i < numsSize; i++)
    {
        if(nums[i] == temp)
        {
            continue;
        }
        else
        {
            nums[j] = temp;
            j++;
            temp = nums[i];
        }
    }
    nums[j] = temp;
    j++;

    return j;
}