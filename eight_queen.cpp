#按列来枚举


code:

#include <iostream>
using namespace std;

const int Normalize = 9;  //用来统一数组下标

int num;  //方案数
int q[9];   //8个皇后的行号

bool S[9];    //s1-s8 当前行是否安全
bool R[17];    //R2-R16 (i + j)对角线是否安全
bool L[17];    //L2-L16 (i - j)对角线是否安全

void Try(int col);

int main()
{
    num = 0;
	for (int i = 0; i < 9; i++)
		S[i] = true;

	for (int i = 0; i < 17; i++)
	{
		R[i] = true;
		L[i] = true;
	}

	Try(1); //从第一行开始

	cout << "方案数:" << num << endl;

	return 0;
}


void Try(int col)
{
	if (col == 9)
	{
		num++;
		return;
	}
	//按行枚举
	for (int row = 1; row < 9; row++) {
		//判断拟放置皇后的位置是否安全
		if (S[row] && R[col + row] && L[col - row + Normalize]) {
			//记录位置信息（行号）
			q[col] = row;
			
			//修改三个方向的安全标记
			S[row] = false;
			R[col + row] = false;
			L[col - row + Normalize] = false;

			//递归尝试放下一列
			Try(col + 1);

			//回溯，恢复三个方向原来的安全性
			S[row] = true;
			R[col + row] = true;
			L[col - row + Normalize] = true;

		}
	}
}
    
  
