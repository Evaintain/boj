#include <iostream>

using namespace std;

/*
1138번 문제

접근 방식
->
1부터 N까지 차례대로 배치한다
*/

/*
조건
N <= 10 자연수
*/

/*
태그
. 구현
*/

/*
느낀점
생각하는데는 오래걸리지 않았으나 구현하는데 오래 걸렸다.
*/

int main()
{
    int arr[17];
    for (int i = 0; i < 17; i++)
    {
        arr[i] = 0;
    }
    int n;
    int order;
    int cnt = 0;
    int index = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        cnt = 0;
        index = 0;
        scanf("%d", &order);
        for (int j = 0; j < n; j++)
        {
            if (cnt == order && arr[cnt + index] == 0)
            {
                arr[cnt + index] = i;
            }

            //0이면 cnt를 올려준다 -> order와 같지 않으면 큰수가 올 자리이기 떄문
            else if (arr[j] == 0) 
            {
                cnt++;
            }
            
            //0 이 아니라면 이미 숫자가 있으므로 0을 찾을때까지 올려주는것이다.
            else
            {
                index++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
