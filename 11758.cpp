#include <iostream>

using namespace std;

/*
11758번 문제 접근 방식
->
CCW(Counter Clock Wise) 알고리즘 사용,
2차원 외적이기에 z좌표는 0이다.
x = (a, b)
y = (c, d)
z = (e, f)
xy벡터는 = (c - a, d - b)
yz벡터는 = (e - c, f - d)

잇는 순서대로 외적을 곱해서 0일경우 일직선 0보다 작을경우 시계방향, 클경우 반시계 방향이다.
*/

/*
태그
. 기하학
*/

struct location
{
    int x;
    int y;
};

class ccw
{
private:
    long long v;

public:
    int calculator_v(location a, location b, location c)
    {
        v = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
        if (v > 0)
        {
            return 1;
        }
        else if (v < 0)
        {
            return -1;
        }

        return 0;
    }
};

int main()
{
    int x, y;
    location arr[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &x, &y);
        arr[i] = location({x, y});
    }

    ccw cw;
    printf("%d", cw.calculator_v(arr[0], arr[1], arr[2]));
}
