#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = s, count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[pivot] >= arr[i])
        {
            count++;
        }
    }
    swap(arr[pivot], arr[s + count]);
    pivot += count;
    int x = s, y = e;
    while (x < pivot && y > pivot)
    {

        while (arr[x] <= arr[pivot])
        {
            x++;
        }

        while (arr[y] > arr[pivot])
        {
            y--;
        }

        if (x < pivot && y > pivot)
        {
            swap(arr[x++], arr[y--]);
        }
    }
    return pivot;
}

void quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[10] = {5, 4, 3, 9, 2, 1, 5, 7, 8, 0};
    int n = 10;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}