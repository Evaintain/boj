#include <bits/stdc++.h>

using namespace std;

/*
5430번 문제

접근 방식
->
문자열 배열(함수)을 받고,
n의 갯수를 받고,
n을 문자열 형태로 받아서
구현한다.
*/

/*
태그
. 구현
. 자료 구조
. 문자열
. 파싱
. 덱
*/

int main()
{
    int tc, n;
    int input_number;
    char fun[100007], input_n[410007]; //250007 ->에서 segfault 에러. [] 2개/ ,갯수 최대99999개/ 숫자는 100이하이므로 3 * 100000 300000개 400001 이상으로 배열 잡아야함.
    deque<int> q;
    scanf("%d", &tc);
    bool reverse_check, error;
    for (int i = 0; i < tc; i++)
    {
        error = false;
        reverse_check = false;
        q.clear();
        scanf("%s", fun);
        scanf("%d", &n);
        scanf("%s", input_n);
        int len = strlen(input_n);
        input_number = 0;

        for (int j = 1; j < len - 1; j++) //deque<int> q에 숫자를 넣는 for문
        {
            if (input_n[j] != ',')
            {
                input_number *= 10;
                input_number += input_n[j] - '0';
            }
            if (input_n[j] == ',' || j == len - 2)
            {
                q.push_back(input_number);
                input_number = 0;
            }
        }

        int fun_len = strlen(fun);
        for (int j = 0; j < fun_len; j++)
        {
            if (fun[j] == 'R')
            {
                reverse_check = !reverse_check;
            }
            else
            {
                if (q.size() == 0)
                {
                    printf("error\n");
                    error = true;
                    break;
                }

                if (reverse_check)
                {
                    q.pop_back();
                }
                else
                {
                    q.pop_front();
                }
            }
        }

        if (error) //에러가 났으면 이번 회차를 종료시키는 코드
        {
            continue;
        }

        printf("[");
        if (!reverse_check)
        {
            for (int j = 0; j < q.size(); j++)
            {
                printf("%d", q[j]);
                if (j != q.size() - 1)
                {
                    printf(",");
                }
            }
        }
        else
        {
            for (int j = q.size() - 1; j > -1 ;j--)
            {
                printf("%d", q[j]);
                if (j != 0)
                {
                    printf(",");
                }
            }
        }
        printf("]\n");
    }
}
