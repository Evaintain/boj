#include <bits/stdc++.h>

using namespace std;

/*
1018번 문제

접근 방식
->
WBWB...
BWBW...

BWBW...
WBWB... 를 비교 해본다.
그중 최소 횟수를 따짐.
*/

int main()
{
    char bw[] = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
    char wb[] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};
    char arr[57][57];
    char in_arr;
    int n, m, result = 64, bw_result, wb_result;
    int bw_check, wb_check;
    bw_check = wb_check = 1;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) //입력
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &in_arr);
            if(in_arr == '\n') //%c가 \n도 입력받으니, 입력받을경우 j--하고 다시 돌림.
            {
                j--;
                continue;
            }
            arr[i][j] = in_arr;
        }
    }

    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            bw_result = wb_result = 0;
            for (int y = i; y < i + 8; y++)
            {
                for (int x = j; x < j + 8; x++)
                {
                    if (bw_check == 1 && arr[y][x] != bw[x - j])
                    {
                        bw_result++;
                    }
                    if (bw_check == 0 && arr[y][x] != wb[x - j])
                    {
                        bw_result++;
                    }

                    if (wb_check == 1 && arr[y][x] != wb[x - j])
                    {
                        wb_result++;
                    }
                    if (wb_check == 0 && arr[y][x] != bw[x - j])
                    {
                        wb_result++;
                    }
                }
                //WB -> BW | BW -> WB로 탐색순서 바꿔주는 부분.
                if (bw_check == 1)
                {
                    bw_check = 0;
                }
                else
                {
                    bw_check = 1;
                }

                if (wb_check == 1)
                {
                    wb_check = 0;
                }
                else
                {
                    wb_check = 1;
                }
            }
            // 결과값 바꿔주는 부분.
            if (bw_result < result)
            {
                result = bw_result;
            }
            if (wb_result < result)
            {
                result = wb_result;
            }
        }
    }
    printf("%d", result);
}
