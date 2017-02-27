int findComplement(int num) {
    int com;
    long long int t=2;
	for(;t<=num;t*=2);
	com = t-1-num;
	return com;
}