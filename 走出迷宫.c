#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sx, sy, tx, ty;
int n, m;
char map[100][100];
int value[100][100] = { 0 };
int go(int x, int y,int xf,int yf)
{
	if (x == tx&&y == ty)
		return 0;
	int flagl = 0, flagr = 0, flagu = 0, flagd = 0;
	if (map[y][x - 1] != '#'&&value[y][x - 1] == 0 && x - 1 >= 0)
	{
		value[y][x - 1] = value[y][x] + 1;
		flagl = 1;
	}
	if (map[y][x + 1] != '#'&&value[y][x + 1] == 0 && x + 1 < m)
	{
		value[y][x + 1] = value[y][x] + 1;
		flagr = 1;
	}
	if (map[y - 1][x] != '#'&&value[y - 1][x] == 0 && y - 1 >= 0)
	{
		value[y - 1][x] = value[y][x] + 1;
		flagu = 1;
	}
	if (map[y + 1][x] != '#'&&value[y + 1][x] == 0 && y + 1 < n)
	{
		value[y + 1][x] = value[y][x] + 1;
		flagd = 1;
	}
	if (map[y][x - 1] != '#'&& x - 1 >= 0 && value[y][x - 1] > value[y][x] + 1)
	{
		value[y][x - 1] = value[y][x] + 1;
		flagl = 1;
	}
	if (map[y][x + 1] != '#' && x + 1 < m &&value[y][x + 1] > value[y][x] + 1)
	{
		value[y][x + 1] = value[y][x] + 1;
		flagr = 1;
	}
	if (map[y - 1][x] != '#' &&y - 1 >= 0 && value[y - 1][x] > value[y][x] + 1)
	{
		value[y - 1][x] = value[y][x] + 1;
		flagu = 1;
	}
	if (map[y+1][x]!= '#' && y + 1 < n&&value[y+1][x]>value[y][x]+1)
	{
		value[y + 1][x] = value[y][x] + 1;
		flagd = 1;
	}
	if (xf != x - 1 &&x - 1 >= 0&& map[y][x - 1] != '#'&&flagl==1)
		go(x - 1, y, x, y);
	if (xf != x + 1 &&x + 1<m&&map[y][x +1] != '#'&&flagr==1)
		go(x + 1, y, x, y);
	if (yf != y - 1 && y - 1 >= 0&&map[y-1][x ] != '#'&&flagu==1)
		go(x, y - 1, x, y);
	if (yf != y + 1 && y + 1<n&&map[y+1][x ] != '#'&&flagd==1)
		go(x, y + 1, x, y);
	return 0;
}
int main()
{
	int i = 0, j = 0, z = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("\n%c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				sx = j;
				sy = i;
			}
			if (map[i][j] == 'T')
			{
				tx = j;
				ty = i;
			}
			}
		z = getchar();
		}
	value[sy][sx] = 1;
	go(sx, sy,sx,sy);
	printf("%d", value[ty][tx]-1);
	}
