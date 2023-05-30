#include <iostream>

using namespace std;

/*
17386번 문제 접근 방식
->
각 선분을 이루는 점을
v1, v2, v3, v4라 하고 v1, v2가 짝이고, v3, v4가 짝이라면
v1, v2, (v3, v4) CCW를 곱한 값이 음수
v3, v4, (v1, v2) CCW를 곱한 값이 음수여야한다.
*/

/*
태그
. 기하학
. 선분 교차 판정
*/

struct v
{
    long long x;
    long long y;
};

class ccw
{
private:
    v arr[4];
public:
    void input(int i, int x, int y)
    {
        arr[i].x = x;
        arr[i].y = y;
    }

    int calculator(v a, v b, v c)
    {
        long long t = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
        if (t > 0)
        {
            return -1;
        }
        else if (t < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void print()
    {
        int ccw1, ccw2, ccw3, ccw4;
        ccw1 = calculator(arr[0], arr[1], arr[2]);
        ccw2 = calculator(arr[0], arr[1], arr[3]);
        ccw3 = calculator(arr[2], arr[3], arr[0]);
        ccw4 = calculator(arr[2], arr[3], arr[1]);

        if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
};

int main()
{
    ccw cw;
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &x, &y);
        cw.input(i, x, y);
    }

    cw.print();
}
