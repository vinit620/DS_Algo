#include <iostream>
using namespace std;

void SelectionSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);


int main(void)
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int a[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    
    InsertionSort(a, size);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}


void SelectionSort(int a[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    return;
}


void BubbleSort(int a[], int n)
{
    int counter = 0;
    while (counter < (n - 1))
    {
        for (int i = 0; i < (n - counter); i++)
        {
            if (a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        counter++;
    }
}


void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > current)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }

    return;
}