#include <iostream>

using namespace std;

/*
2239번 문제 접근 방식
->
행, 렬, 3*3칸을 확인하며 스도쿠를 완성한다.
만약 다 체크를 했는데 그 칸이 0 이라면 return한다. -> 아무값도 넣을수 있지 않기 때문이다.
그리고 처음 최댓값에 도달하면 종료한다(exit 말고도 종료하는 방법이 있을거 같다) -> bool 형으로 체크해도 될듯.
*/

/*
태그
. 구현
. 백트래킹
*/

int arr[17][17];

class check
{
public:
    bool row_check(int y, int n)
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[y][i] == n)
            {
                return false;
            }
        }
        return true;
    }

    bool col_check(int x, int n)
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][x] == n)
            {
                return false;
            }
        }
        return true;
    }

    bool _3x3check(int x, int y, int n)
    {
        int _x = x / 3;
        int _y = y / 3;

        _x *= 3;
        _y *= 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[_y + i][_x + j] == n)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checking(int x, int y, int n)
    {
        return row_check(y, n) && col_check(x, n) && _3x3check(x, y, n);
    }
};

int a = 0;

class sudoku : check
{
public:
    void backtrack(int cnt)
    {
        if (cnt == 81)
        {
            print();
            exit(0);
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                for (int k = 1; k < 10; k++)
                {
                    if (arr[i][j] == 0 && checking(j, i, k))
                    {
                        arr[i][j] = k;
                        backtrack(cnt + 1);
                        arr[i][j] = 0;
                    }
                }
                if (arr[i][j] == 0)
                {
                    return;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
    }
};

int main()
{
    int n;
    char k;
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%c", &k);
            if (k == '\n')
            {
                j--;
            }
            else
            {
                arr[i][j] = k -'0';
                if (arr[i][j] != 0)
                {
                    cnt++;
                }
            }
        }
    }

    sudoku sdk;
    sdk.backtrack(cnt);
}
