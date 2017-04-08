#矩阵填充
 将矩阵即二维数组按照逆时针方向填充
 例：N = 5
     1 16 15 14 13
     2 17 24 23 12
     3 18 25 22 11
     4 19 20 21 10
     5  6  7  8  9

代码如下：

#include <iostream>
#include <iomanip>
#define N 5
using namespace std;

void FillMatrix(int a[][N], int size, int num, int offset)	//missing subscript
{
	if (size == 0)
		return;
	if (size == 1)
	{
		a[offset][offset] = num;
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		a[offset + i][offset] = num + i;
		a[offset + size - 1][offset + i] = num + size - 1 + i;
		a[offset + size - 1 - i][offset + size - 1] = num + 2 * (size - 1) + i;
		a[offset][offset + size - 1 - i] = num + 3 * (size - 1) + i;
	}
	FillMatrix(a, size - 2, num + 4 * (size - 1), offset + 1);
}

int main()
{
	int a[N][N];
	FillMatrix(a, N, 1, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
    return 0;
}

