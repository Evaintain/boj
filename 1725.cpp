#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
1725번 문제 접근 방식
->
프로그래밍 대회에서 배우는 알고리즘 문제해결전략책을 보고
19챕터의 스택부분을 보고 푸는글이다.

i번째의 높이, 오른쪽, 왼쪽으로 넓이를 구한다.

r[i] > r[i + 1]
r[i]에 대한 크기 계산 가능 (오른쪽 왼쪽이 전부 결정나므로)

r[i] < r[i + 1]
계산 불가능 둘다 오른쪽 이 결정이 나지않음.

6529번에서 한번만 돌리면 됨.
*/

/*
태그
. 자료 구조
. 세그먼트 트리
. 분할 정복
. 스택
*/

int high[100007];

class sqaure
{
private:
    vector<int> remaining;
    long long max_width = 0;

public:
    void init()
    {
        max_width = 0;
        remaining.clear();
    }

    void execute(int n)
    {
        init();

        high[n] = 0;
        for (int i = 0; i < n + 1; i++)
        {
            while(!remaining.empty() && high[remaining.back()] > high[i])
            {
                long long top = remaining.back();
                remaining.pop_back();
                long long width = i;

                if (!remaining.empty())
                {
                    width = i - remaining.back() - 1;
                }

                max_width = max(max_width, width * high[top]);
            }

            remaining.push_back(i);
        }
        printf("%lld\n", max_width);
    }
};

int main()
{
    int n;
    sqaure s;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &high[i]);
    }

    s.execute(n);
}
