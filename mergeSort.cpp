#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int *arr1 = new int[end - start + 1];
    int k = 0;
    int index1 = start, index2 = mid + 1;
    while (index1 <= mid && index2 <= end)
    {
        if (arr[index1] < arr[index2])
        {
            arr1[k++] = arr[index1++];
        }
        else
        {
            arr1[k++] = arr[index2++];
        }
    }
    while (index1 <= mid)
    {
        arr1[k++] = arr[index1++];
    }

    while (index2 <= end)
    {
        arr1[k++] = arr[index2++];
    }
    int m = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = arr1[m++];
    }
    delete[] arr1;
}

void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;

    mergesort(arr, start, mid);

    mergesort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {8,4,3,71,8,3,1,0,7,69};
    int n = 10;
    int e = n - 1;
    mergesort(arr, 0, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}