#include <bits/stdc++.h>
#define ll long long
const int M = 1e9 + 7;
const int LEN = 100000;
using namespace std;
using namespace std::chrono;

void copy(int *arr, int *brr, int len = LEN)
{
    for (int i = 0; i < len; i++)
    {
        brr[i] = arr[i];
    }
}

void readFile(int *main_arr, string address, int len = LEN)
{
    ifstream f(address, ios_base::in);

    if (!f.is_open())
    {
        cout << "Error in Reading the File" << address << endl;
        return;
    }

    int buffer;
    int ct = 0;
    while (f >> buffer && ct < len)
    {
        *(main_arr + ct) = buffer;
        ct++;
    }
}

void heapify(int *main_arr, int len, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < len && main_arr[l] > main_arr[largest])
        largest = l;
    if (r < len && main_arr[r] > main_arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(main_arr[i], main_arr[largest]);
        heapify(main_arr, len, largest);
    }
}

void heapSort(int *main_arr, int len = LEN)
{
    int *arr = new int[len];
    copy(main_arr, arr);
    auto start = high_resolution_clock::now();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(arr, len, i);
    }
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n = LEN)
{
    auto start = high_resolution_clock::now();
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}
int32_t main()
{
    int *worst_arr = new int[LEN], *average_arr = new int[LEN], *best_arr = new int[LEN];
    readFile(worst_arr, "./worst_arr.txt");
    readFile(average_arr, "./average.txt");
    readFile(best_arr, "./best_arr.txt");
    cout << "Heap" << endl;
    heapSort(worst_arr);
    heapSort(average_arr);
    heapSort(best_arr);
    cout << "Radix" << endl;
    radixsort(worst_arr);
    radixsort(average_arr);
    radixsort(best_arr);

    return 0;
}