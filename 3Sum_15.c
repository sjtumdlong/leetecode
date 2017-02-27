/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quicksort(int *nums, int low, int high)
{
        int k=nums[low],tmp,l=low,h=high;
        if(low>=high)return;
        while(low<high)
        {
                for(;low<high && nums[high]>=k;high--);
                if(low<high){nums[low]=nums[high];low++;}
                for(;low<high && nums[low]<=k;low++);
                if(low<high){nums[high]=nums[low];high--;}
        }
        nums[low]=k;
        quicksort(nums,l,low-1);
        quicksort(nums,low+1,h);
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int low=0,high=numsSize-1,i,j,k,n,r,size=numsSize*100,s,flag;
	int **array=(int **)malloc(sizeof(int *)*size),**tmp;
	if(numsSize<3)
	{
		*returnSize=0;
		return array;
	}
	s=0;
	quicksort(nums,low,high);
	for(j=1; j<numsSize-1; j++)
	{
		i=j-1;
		k=j+1;
		while(i>=0 && k<numsSize)
		{
			r=nums[i]+nums[j]+nums[k];
			if(r>0)i--;
			if(r<0)k++;
			if(r==0)
			{
				if(s==0)
				{
					array[0]=(int*)malloc(sizeof(int)*3);
					array[0][0]=nums[i];
					array[0][1]=nums[j];
					array[0][2]=nums[k];
					s++;
					i--;
					k++;
				}
				else
				{
					if(s>size)
					{
						size*=2;
						tmp=(int **)malloc(sizeof(int *)*size);
						for(n=0;n<s;n++)tmp[n]=array[n];
						free(array);
						array=tmp;
					}
					flag=1;
					for(n=s-1;n>=0 && array[n][1]==nums[j];n--)
					{
						if(nums[i]==array[n][0]&&nums[k]==array[n][2])
						{
							flag=0;
						}
					}
					if(flag)
					{
						array[s]=(int*)malloc(sizeof(int)*3);
						array[s][0]=nums[i];
						array[s][1]=nums[j];
						array[s][2]=nums[k];
						s++;
					}
					i--;
					k++;
					
				}
			}
		}
	}
	*returnSize = s;
	return array;
}