#include <iostream>
using namespace std;

void merge(int a[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for(int i = 0; i < n1; i++)
    {
        left[i] = a[start + i];
    }

    for(int i = 0; i < n2; i++)
    {
        right[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = start;

    while(i < n1 && j < n2)
    {
        if(left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_recursive(int a[], int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    merge_sort_recursive(a, start, mid);
    merge_sort_recursive(a, mid + 1, end);

    merge(a, start, mid, end);

}

void merge_sort_iterative(int b[], int n)
{
    int p, i, l, m, h;

    for(p = 2; p <= n; p *= 2)
    {
        for(i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            m = (l + h) / 2;
            merge(b, l, m, h);
        }
    }

    if(p / 2 < n)
    {
        merge(b, 0, p / 2, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    // merge sort using recursion
    merge_sort_recursive(a, 0, n - 1);
    cout << "Sorted array using recursive call " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // merge sort using iterative call.
    merge_sort_iterative(b, n);

    cout << "Sorted array using iterative call" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}