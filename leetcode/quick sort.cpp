#include <iostream>

using namespace std;

void Qsort(int arr[], int low, int high) 
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (true)
	{
		/*���������ұ�key���ֵ*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*���������ұ�keyС��ֵ*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*����i,j��Ӧ��ֵ*/
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	/*����ֵ��j��Ӧֵ����*/
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	Qsort(arr, low, j - 1);
	Qsort(arr, j + 1, high);
}

int main2()
{
	int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };

	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*����ԭ�ĵ���������Ҫ��1�����ڴ�Խ��*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << "";
	}

	return 0;
}