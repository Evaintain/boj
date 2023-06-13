#include <iostream>
#include <queue>

using namespace std;

/*
26042번 문제 접근 방식
->
1일때만 크기를 비교해봄.(2일때는 어쩌피 pop이니 의미 x)
pop할때 empty인 경우는 생각 할필요 x
*/

/*
태그
. 자료 구조
. 큐
*/

class que
{
private:
    queue<int> q;
    int order;
    int human;
    int cnt = 0;
    int num = 100001;

public:
    void execute(int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &order);
            if (order == 2)
            {
                q.pop();
            }

            else
            {
                scanf("%d", &human);
                q.push(human);

                if (cnt <= q.size())
                {
                    if (cnt == q.size())
                    {
                        num = min(num, human);
                    }
                    else
                    {
                        num = human;
                    }
                    cnt = q.size();
                }
            }
        }

        printf("%d %d", cnt, num);
    }
};

int main()
{
    que q;
    int n;

    scanf("%d", &n);
    q.execute(n);
}
