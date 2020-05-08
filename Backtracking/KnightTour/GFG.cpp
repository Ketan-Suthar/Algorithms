#include <bits/stdc++.h>

using namespace std;

#define N 8
int cells[N][N];
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void printSolution()
{
	for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", cells[x][y]);
        printf("\n");
    }
}

bool isSafe(int x, int y)
{
	return (x>=0 && x < N && y>=0 && y < N && cells[x][y] == -1);
}

void initCells()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cells[i][j] = -1;
}

bool knightTour(int x, int y, int moves)
{
	int nextX, nextY;
	if(moves == N*N)
		return true;
	// cout << "\nmoves: " << moves << "\n";
	// printSolution();

	for (int i = 0; i < 8; ++i)
	{
		nextX = x + xMove[i];
		nextY = y + yMove[i];

		if(isSafe(nextX, nextY))
		{
			cells[nextX][nextY] = moves;

			if(knightTour(nextX, nextY, moves + 1))
				return true;
			else
				cells[nextX][nextY] = -1;
		}
 	}
 	return false;
}

void solve(int x, int y)
{
	initCells();
	cells[x][y] = 0;

	if(knightTour(x, y, 1))
		printSolution();
	else
		cout << "\nKnight Tour is not possible!!";
}

int main(int argc, char const *argv[])
{
	int x,y;
	cin >> x >> y;
	solve(x, y);
	return 0;
}