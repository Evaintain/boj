#include <iostream>
#include <queue>

using namespace std;

/*
11051번 문제 접근 방식
->
다음날 주가가 상승함 or 주가가 같음 -> 오늘 주식을 삼
다음날 주가가 하락함 -> 사둔 주식을 다 팜.

틀린 이유
->
7 6 8 경우를 어떻게 해결할 것인가?
7 - > 6 안삼
6 -> 8 사서 팖 -> 2
7, 6 사고 -> 8에서 팜 -> 3

최댓값을 저장한다.
i번 값이 i 이전 값보다 크다면, i랑 값을 바꿔준다.
아닐경우 deque에 넣는다.
(계산시에는 큐로 아닐때는 스택형태로 넣어줘야함)

질문 게시판을 보다가 뒤로 접근 한다는 것을 보게 되었다.
뒤에서 접근시
-> 비교 했을때 i, i - 1중 i - 1이 최댓값인 경우, 이경우에는 돈을 못 번다
위의 경우가 아니면 최댓값 - arr[i] 해준다.

이 문제는 뒤로 접근 해야하는거 같다.
그리디 알고리즘인데 접근 방식을 잘 몰랐다.
무작정 앞에서 접근해야 하는줄 알았다.
*/

/*
태그
. 그리디 알고리즘
*/

int arr[1000007];

class money
{
private:
    long long sum = 0;
    int money = 0;

public:
    void init()
    {
        sum = 0;
        money = 0;
    }

    void execute(int n)
    {
        init();

        for (int i = n - 1; i > -1 ; i--)
        {
            if (arr[i] > money)
            {
                money = arr[i];
            }

            else
            {
                sum += money - arr[i];
            }
        }


        printf("moeny : %lld\n", sum);
    }
};

int main()
{
    money m;
    int tc, n;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        m.execute(n);
    }
}
