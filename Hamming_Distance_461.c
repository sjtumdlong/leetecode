int hammingDistance(int x, int y) {
    int a,b,d=0;
	while(x!=0 || y!=0)
	{
		a=x-x/2*2;
		b=y-y/2*2;
		if(a!=b)d++;
		x=x/2;
		y=y/2;
	}
	return d;
}