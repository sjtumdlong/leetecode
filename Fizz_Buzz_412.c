/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **result;
	int i,j,k;
	result = (char**)malloc(n*sizeof(char*));
	for(i=1;i<=n;i++)
	{
		result[i-1]=(char *)malloc((10+i/10)*sizeof(char));
		if(i%3==0)
		{
			if(i%5==0)
			{
				result[i-1]="FizzBuzz";
			}
			else
			{
				result[i-1]="Fizz";
			}
		}
		else
		{
			if(i%5==0)
			{
				result[i-1]="Buzz";
			}
			else
			{
				k=0;
				for(j=i;j!=0;j/=10)k++;
				result[i-1][k]='\0';
				for(j=i;j!=0;j/=10)
				{
					result[i-1][k-1] = '0'+(j%10);
					k--;
				}
			}
		}
	}
	*returnSize =n;
	return result;
}