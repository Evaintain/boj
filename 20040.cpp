#include <iostream>

using namespace std;

/*
20040번 문제 접근 방식
->
a, b가 주어질때
a, b의 부모가 같다면 사이클이 만들어 진것이다.
그렇게 제일 빨리 사이클이 만들어 지는 횟수를 저장하고, bool로 찾았는지 못찾았는지 판별
*/

/*
태그
. 자료 구조
. 분리 집합
*/

int arr[500007];

// 경로 압축이 적용된 부모 찾기.
int find_set(int x)
{
    if (x == arr[x])
    {
        return x;
    }

    return find_set(arr[x]);
}

int union_set(int a, int b)
{
    int x = find_set(a);
    int y = find_set(b);

    // 작은 쪽으로 합치게 하기 위함.
    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    if (x == y)
    {
        return 0;
    }

    else
    {
        arr[x] = y;
        return 1;
    }
}

int main()
{
    // 배열 초기화
    for (int i = 0; i < 500007; i++)
    {
        arr[i] = i;
    }

    int n, m;
    int sv,ev;
    int result;
    int end_num = 0;
    bool check = false;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &sv, &ev);
        result = union_set(sv, ev);
        if (result == 0 && !check)
        {
            check = true;
            end_num = i + 1;
        }
    }

    if (!check)
    {
        printf("0");
    }

    if (check)
    {
        printf("%d", end_num);
    }
}
