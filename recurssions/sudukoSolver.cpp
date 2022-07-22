#include<iostream>
using namespace std;

bool check(int num, int a[10][10], int i, int j)
{
	for (int x = 0; x < 9; x++)
	{
		if (a[x][j] == num || a[i][x] == num)
			return false;
	}

	for (int m = (i / 3) * 3; m < ((i / 3) * 3) + 3; m++)
	{
		for (int n = (j / 3) * 3; n < ((j / 3) * 3) + 3; n++)
		{
			if (a[m][n] == num)
				return false;
		}
	}
	return true;
}

bool sudokuSolver(int n, int a[10][10], int i, int j)
{
	//base case
	if (i == n)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				cout << a[x][y] << " ";
			}
			cout << endl;
		}
		return true;
	}

	if (j == n)
		return sudokuSolver(n, a, i + 1, 0);

	//recursive case
	if (a[i][j] == 0)
	{
		for (int num = 1; num < 10; num++)
		{
			if (check(num, a, i, j) == true)
			{
				a[i][j] = num;
				bool possible = sudokuSolver(n, a, i, j + 1);
				if (possible)
					return true;

			}
		}
		a[i][j] = 0;
		return false;
	}
	else
		return sudokuSolver(n, a, i, j + 1);


	return false;
}

int main()
{
	int n;
	cin >> n;

	int a[10][10];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	bool chk = sudokuSolver(n, a, 0, 0);

	if (!chk)
		cout << "Not Possible \n";

	return 0;
}
