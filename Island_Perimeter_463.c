int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int row=0;
	int col=0;
	int p=0;
	for(row=0;row<gridRowSize;row++)
	{
		for(col=0;col<gridColSize;col++)
		{
			if(grid[row][col]==1)
			{
				if(!(col>0 && grid[row][col-1]==1))p++;
				if(!(col<gridColSize-1 && grid[row][col+1]==1))p++;
				if(!(row>0 && grid[row-1][col]==1))p++;
				if(!(row<gridRowSize-1 && grid[row+1][col]==1))p++;
			}
		}
	}
	return p;
}