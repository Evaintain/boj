#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
1450번 문제 접근 방식
->
15개씩 쪼개서 배열을 만든다.
cnt = 1 시작 -> 공집합의 경우
*/

/*
태그
. 이분 탐색
. 중간에서 만나기
*/

typedef long long ll;

class middle
{
private:
    vector<int> left;
    vector<int> right;
    int cnt = 1;
    ll p = 0;
    int idx;

public:
    void make_left(int n, int *arr, int ans)
    {
        for (int i = 1; i < (1 << n); i++)
        {
            p = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    p += arr[j];
                }
            }

            if (p > ans)
            {
                continue;
            }

            left.push_back(p);
        }
        sort(left.begin(), left.end());
    }

    void make_right(int s, int n, int *arr, int ans)
    {
        for (int i = 1; i < (1 << n - s); i++)
        {
            p = 0;
            for (int j = 0; j < n - s; j++)
            {
                if (i & (1 << j))
                {
                    p += arr[s + j];
                }
            }

            if (p <= ans)
            {
                cnt++;
            }

            if (p > ans)
            {
                continue;
            }

            right.push_back(p);
        }
        sort(right.begin(), right.end());
    }

    void execute(int n, int *arr, int ans)
    {
        make_left(n / 2, arr, ans);
        make_right(n / 2, n, arr, ans);

        for (int i = 0; i < left.size(); i++)
        {
            if (left[i] <= ans)
            {
                cnt++;
            }

            idx = upper_bound(right.begin(), right.end(), ans - left[i]) - right.begin();
            cnt += idx;
        }

        printf("%d", cnt);
    }
};

int main()
{
    int n, ans;
    int arr[37];
    middle m;

    scanf("%d %d", &n, &ans);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    m.execute(n, arr, ans);
}
