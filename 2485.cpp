#include <bits/stdc++.h>

using namespace std;

/*
2485번 문제

접근 방식
->
나무 사이 거리의 최대 공약수를 구해서.
max - min / 최대공약수 - n + 1 이 공식일것이다.
*/

int eugcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0) return a;
    return eugcd(b, a % b);
}

int main()
{
    int arr[100007];
    int n, in_arr, gcd, min_val, max_val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_arr);
        arr[i] = in_arr;
        if (i == 0)
        {
            min_val = max_val = arr[i];
        }
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    int gcd_val = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        gcd_val = eugcd(gcd_val, arr[i] - arr[i - 1]);
    }
    printf("%d", (max_val - min_val) / gcd_val - (n - 1));
}
