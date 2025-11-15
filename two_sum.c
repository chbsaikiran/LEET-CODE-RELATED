/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret_indices;
    int i,j,target1,target2,flag = 0;
    for( i = 0; i < numsSize; i++)
    {
        target1 = nums[i];
        //if(target1 == target)
        //{
        //    *returnSize = 1;
        //    ret_indices = (int*)malloc((*returnSize)*sizeof(int));
        //    ret_indices[0] = i;
        //    break;
        //}
        target2 = target - target1;
        for(j = (i+1); j < numsSize; j++)
        {
            if(target2 == nums[j])
            {
                flag = 1;
                break;
            }

        }
        if(flag)
        {
            break;
        }

    }
    if(flag)
    {
        *returnSize = 2;
        ret_indices = (int*)malloc((*returnSize)*sizeof(int));
        ret_indices[0] = i;
        ret_indices[1] = j;
    }
    return ret_indices;
}