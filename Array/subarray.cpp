#include <iostream>
using namespace std;

void sum_of_all_subarrays(int a[], int n);
void longest_arithmetic_subarray(int a[], int n);
void record_breaker(int a[], int n);
void subarr_with_given_sum(int a[], int n);
void maximum_subarray_sum(int a[], int n);           // Kadane's algo use
int kadanes_algo(int a[], int n);                    // V.imp - Kadane's algo
void maximum_circular_subarray_sum(int a[], int n);  // Kadane's algo use
bool pair_sum(int a[], int n);


int main(void)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    pair_sum(a, n);

    return 0;
}


void sum_of_all_subarrays(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            cout << sum << " ";
        }
        cout << endl;
        sum = 0;
    }
}


void longest_arithmetic_subarray(int a[], int n)
{
    int answer = 2, current_length = 2;
    int current_difference, previous_difference = a[1] - a[0];
    for (int i = 1; i < (n-1); i++)
    {
        current_difference = a[i+1] - a[i];
        if (current_difference == previous_difference)
            current_length += 1;
        else
            current_length = 2;
        answer = max(current_length, answer);
        previous_difference = current_difference;
    }
    cout << answer << endl;
}


void record_breaker(int a[], int n)
{
    int answer = 0;
    int max_till_now = a[0];

    if (a[0] > a[1])
        answer += 1;

    for (int i = 1; i < (n-1); i++)
    {
        if (a[i] > max_till_now && (a[i] > a[i+1]))
            answer += 1;
        max_till_now = max(max_till_now, a[i]);
    }

    if (a[n-1] > max_till_now)
        answer += 1;
    
    cout << answer << endl;
}


void subarr_with_given_sum(int a[], int n)
{
    int given_sum;
    cin >> given_sum;
    int start = 0, end = 0;
    while (start < n)
    {
        int sum = a[start];
        for (end = (start + 1); end < n; end++)
        {
            sum += a[end];
            if (sum == given_sum)
            {
                cout << start << " " <<  end << endl;
                return;
            }
            else if (sum > given_sum)
                break;
        }
        start++;
    }
    cout << -1 << endl;
}


void maximum_subarray_sum(int a[], int n)
{
    // 1. Brute force approach - O(n^3)
    // Find sum of all sub arrays individually and compare

    // 2. Cumulative sum approach
    int cumulative_sum[n], max_sum;
    for (int i = 1; i < n; i++)
        cumulative_sum[i] = 0;
    
    cumulative_sum[0] = a[0];
    for (int i = 1; i < n; i++)
        cumulative_sum[i] = cumulative_sum[i-1] + a[i];
    
    max_sum = cumulative_sum[n-1];
    for (int i = 0; i < n; i++)
        max_sum = max(max_sum, (max_sum - cumulative_sum[i]));
    cout << max_sum << endl;

    // Kadane's algo
    cout << kadanes_algo(a, n) << endl; 
}


int kadanes_algo(int a[], int n)
{
    int current_sum, max_sum = 0;
    current_sum = max(0, a[0]);
    for (int i = 1; i < n; i++)
    {
        current_sum = current_sum + a[i];
        if (current_sum < 0)
            current_sum = 0;
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}


void maximum_circular_subarray_sum(int a[], int n)
{
    // CASE 1: contributing elements are non wraping
    // Same as maximum_subarray_sum
    int wrap_sum = kadanes_algo(a, n);


    // CASE 2: contributing elements are wraping
    // 1. Calculate total sum of array
    int total_sum = 0;
    for (int i = 0; i < n; i++)
        total_sum += a[i];
    
    // 2. Sum of non-contributing elements
    // Kadane's algo on -array
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = -a[i];
    int non_contributing_sum = kadanes_algo(b, n);

    // 3. Max_subarray_sum = total_sum - (-non_contributing_sum)
    int non_wrap_sum = total_sum + non_contributing_sum;

    // ANSWER:
    int answer = max(wrap_sum, non_wrap_sum);
    cout << answer << endl;
}


bool pair_sum(int a[], int n)
{
    // Array should be sorted
    // Two pointer approach
    int given_sum;
    cin >> given_sum;

    int st = 0, en = (n - 1);
    while (st < en)
    {
        if (a[st] + a[en] < given_sum)
            st++;
        else if (a[st] + a[en] > given_sum)
            en--;
        else
        {
            cout << st << " " << en << endl;
            return true;
        }
    }
    cout << -1 << endl;
    return false;
}