bool find132pattern(int* nums, int numsSize) {
    int i,j=0,n,min[15000],max[15000];
	for(n=0;n<numsSize-1;n++)
	{
		for(i=0;i<j;i++)
		{
			if(nums[n]>min[i] && nums[n]<max[i])return true;
		}
		if(nums[n+1]>nums[n])
		{
			min[j]=nums[n];
			for(;n<numsSize-1 && nums[n+1]>=nums[n];n++)
			{
				for(i=0;i<j;i++)
				{
					if(nums[n+1]>min[i] && nums[n+1]<max[i])return true;
				}
			}
			if(n == numsSize-1)return false;
			else max[j++]=nums[n];
		}
	}
	for(i=0;i<j;i++)
	{
		if(nums[n]>min[i] && nums[n]<max[i])return true;
	}
	return false;
}