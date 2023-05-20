#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
12014번 문제 접근 방식
->
tc만큼 lis를 구하고 k와 비교한다.
*/

/*
태그
. 이분 탐색
. 가장 긴 증가하는 부분 수열: o(n log n)
*/

int arr[10007];

int main()
{
    int tc;
    int n;
    int k;
    int idx;
    scanf("%d", &tc);
    for (int i = 1; i < tc + 1; i++)
    {
        vector<int> lis;

        scanf("%d %d", &n, &k);

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        lis.push_back(arr[0]);

        for (int j = 1; j < n; j++)
        {
            if (lis.back() < arr[j])
            {
                lis.push_back(arr[j]);
            }
            else
            {
                idx = lower_bound(lis.begin(), lis.end(), arr[j]) - lis.begin();
                lis[idx] = arr[j];
            }
        }

        printf("Case #%d\n", i);
        if (lis.size() >= k)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}
