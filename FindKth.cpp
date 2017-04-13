#寻找第k小的数
使用快排，先将序列排为有序，再输出第k个元素

对vector类的使用
vector<int> array(n);//n在使用前必须有确定的值，可以是定义的变量，可以是从键盘输入的值
注意：vector是类模板，必须遵循类、对象等的使用规则
例如：对函数定义时不能用数组的定义方式：MyQsort(int array[],int low,int high)
     对其调用时就不能以数组的调用方式：MyQsort (array,0,n-1）
     正确的定义方式和调用方式：
     MyQsort(vector <int> &array,int low,int high)
     MyQsort(array,int low,int high)


#include <iostream>
#include <vector>
using namespace std;


int Qsort(vector<int> &array, int low,int high)
{
	int pivot = array[low];
	while(low<high)
	{
		while (low < high&&array[high] >= pivot)
			high--;
		array[low] = array[high];
		while (low < high&&array[low] <= pivot)
			low++;
		array[high] = array[low];
	}
	array[low] = pivot;
	return low;
 }

void MyQsort(vector<int> &array, int low, int high)
{
	if(low<high)
	{
		int pivotpos = Qsort(array, low, high);
			MyQsort(array, low, pivotpos - 1);
			MyQsort(array, pivotpos + 1, high);
	}
}



int main()
{
	
	int m, k;
	cin >> m >> k;
	
	vector<int> array(m);
	
	for (int i = 0; i < m; i++)
		cin >> array[i];

	MyQsort(array, 0, m - 1);

	cout << array[k - 1] << endl;

    return 0;
}
