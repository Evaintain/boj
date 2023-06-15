#include <iostream>

using namespace std;

/*
2460번 문제 접근 방식
->
10번 입력을 받는데 입력 한번 마다 max값이 갱신 가능할 경우 갱신할것
*/

/*
태그
. 수학
. 구현
. 사칙연산
*/

class cal
{
private:
    int max_val = 0;
    int cnt = 0;
    int _add, _minus;

public:
    void execute()
    {
        for (int i = 0; i < 10; i++)
        {
            scanf("%d %d", &_minus, &_add);
            cnt += (_add - _minus);
            max_val = max(max_val, cnt);
        }

        printf("%d", max_val);
    }
};

int main()
{
    cal c;
    c.execute();
}
