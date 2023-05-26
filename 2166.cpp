#include <iostream>
#include <vector>

using namespace std;

/*
2166번 문제 접근 방식
->
신발끈 공식을 위키피디아에서 찾아보고 다각형의 면적에 대해서 적는다
0.5 * abs(x1y2 ..... xny1 - x2y1 - x3y2... - x1yn)
가 공식이다.
*/

/*
태그
. 기하학
. 다각형의 넓이
*/

struct location
{
    double x;
    double y;
};

class width
{
private:
    vector<location> v;
    double sum = 0;
public:
    void input(int x, int y)
    {
        v.push_back({x, y});
    }

    void sum_arr(int n)
    {
        // xiy(i+1) 더하기 + x(i+1)yi 빼기
        for (int i = 0; i < n - 1; i++)
        {
            sum += v[i].x * v[i + 1].y;
            sum -= v[i + 1].x * v[i].y;
        }
        sum += v[n - 1].x * v[0].y;
        sum -= v[0].x * v[n - 1].y;
    }

    void print()
    {
        printf("%.1lf", 0.5 * abs(sum));
    }
};

int main()
{
    width wd;

    int n;
    int x, y;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        wd.input(x, y);
    }

    wd.sum_arr(n);
    wd.print();
}
