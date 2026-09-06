#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 1, 4, 2, 8 }; // 위키피디아 예시
	// int arr[] = { 5, 4, 3, 2, 1 }; // Worst Case : 비교 횟수 많다(효율성 낮음)
	// int arr[] = { 1, 2, 3, 5, 4 }; // Best Case : 바로 종료 가능
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);
	cout << endl;

	// Bubble Sort
	{
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
		}
		Print(arr, n);
		cout << endl;
	}

	// Best case
		for (int i = 0; i < n - 1; i++) {

			bool swapped = false;

			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
		Print(arr, n);
		cout << endl;
	
	// Stability
}
