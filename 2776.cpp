#include <bits/stdc++.h>

using namespace std;

/*
2776 문제

접근 방식
->
탐색인데 n개가 100만개 m개가 100만개니 n * m 이면 1억이기에, 이진탐색을 해야함.
1회 오답 -> 범위초과 에러가 났음. -> 배열 100만개인데 10만개로 잡아서 오답이 났음.
2, 3회 오답 -> 시간초과가 났음. -> vector는 함수에 매개변수로 주면 값을 일일히 복사한다고함.
*/
int arr[1000007];

int binary(vector<int> &sort_arr, int num)
{
    int mid, lo = 0, hi = sort_arr.size() - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        //printf("%d %d %d\n", lo, mid, hi);
        if (sort_arr[mid] == num) return 1;
        if (sort_arr[mid] > num) hi = mid - 1;
        if (sort_arr[mid] < num) lo = mid + 1;
    }
    return 0;
}

int main()
{
    vector<int> v;
    int tc, n, m, in_v, in_arr;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &in_v);
            v.push_back(in_v);
        }

        sort(v.begin(), v.end());

        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &in_arr);
            arr[j] = in_arr;
        }

        for (int j = 0; j < m; j++)
        {
            printf("%d\n", binary(v, arr[j]));
        }

        v.clear();
    }
}
