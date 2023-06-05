#include <iostream>

using namespace std;

/*
22864번 문제 접근 방식
->
피로도 검사후, 일이 가능하면 일을 하고,
불가능하면 쉰다.
24번 반복.
*/

/*
태그
. 수학
. 구현
. 그리디 알고리즘
. 사칙연산
. 시뮬레이션
*/

class work
{
private:
    int tried = 0;
    int work_value = 0;
    int add_tried;
    int working;
    int minus_tried;
    int limit_tried;

public:
    void init(int a, int b, int c, int m)
    {
        add_tried = a;
        working = b;
        minus_tried = c;
        limit_tried = m;
    }

    void execute()
    {
        for (int i = 0; i < 24; i++)
        {
            if (add_tried + tried > limit_tried)
            {
                tried -= minus_tried;
                if (tried < 0)
                {
                    tried = 0;
                }
            }

            else
            {
                tried += add_tried;
                work_value += working;
            }
        }

        printf("%d", work_value);
    }
};

int main()
{
    int a, b, c, m;
    scanf("%d %d %d %d", &a, &b, &c, &m);

    work w;
    w.init(a, b, c, m);
    w.execute();
}
