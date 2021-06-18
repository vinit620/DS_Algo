#include <iostream>
#include <climits>
using namespace std;

void Max_till_i(int a[], int n);
void First_repeating_element(int a[], int n);
void Smallest_missing_positive_number(int a[], int n);

int main(void)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Smallest_missing_positive_number(a, n);

    return 0;
}


void Max_till_i(int a[], int n)
{
    int max_till_i = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_till_i = max(max_till_i, a[i]);
        cout << max_till_i << " ";
    }
    cout << endl;
    return;
}


void First_repeating_element(int a[], int n)
{
    const int N = 1e5;
    int A[N];
    int minIndex = INT_MAX;
    for (int i = 0; i < N; i++)
        A[i] = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        if (A[a[i]] > -1)
        {
            minIndex = min(minIndex, A[a[i]]);
        }
        else
        {
            A[a[i]] = i;
        }
    }

    cout << minIndex + 1 << endl;
    return;
}


void Smallest_missing_positive_number(int a[], int n)
{
    const int N = 1e6;
    bool A[N];
    for (int i = 0; i < N; i++)
        A[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            A[a[i]] = true;
    }

    for (int i = 1; i < N; i++)
    {
        if (!A[i])
        {
            cout << i << endl;
            return;
        }
    }
}