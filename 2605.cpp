#include <iostream>

using namespace std;

/*
2605번 문제

접근 방식
n이 들어올 때
0 -> n - 1자리에 그대로 둔다
1 -> n - 2자리에 두고 원래 n - 2자리는 뒤로 민다.(미는게 우선이고 자리에 넣는게 순서상 뒤이다.)
n - 1 -> 0칸부터 싹 1칸씩 뒤로 민뒤, 0번째에 n을 대입한다.

예제 기준
5
0 1 1 3 2
0 -> 1
1 -> 2, 1
1 -> 2, 3, 1
3 -> 4, 2, 3, 1
2 -> 4, 2, 5, 3, 1
*/

/*
태그
. 구현
. 자료구조
*/

int main()
{
    int student, order;
    int cnt = 0;
    int arr[107];
    for (int i = 0; i < 107; i++)
    {
        arr[i] = 0;
    }

    scanf("%d", &student);
    for (int i = 0; i < student; i++)
    {
        scanf("%d", &order);
        for (int j = 0; j < order; j++) //순서가 주어진다. 0 부터 order - 1 까지. for문을 돌린다.
        {
            arr[cnt - j] = arr[cnt - j - 1]; //cnt = 배열 크기 - 1, 뒤부터 order - 1 까지 한칸씩 뒤로 민다.
        }
        arr[cnt - order] = i + 1; //cnt - order 칸에 자료를 넣는다 (이전 코드에서 order - 1 까지 한칸씩 밀었으니 order칸에 자리가 남는다.)
        cnt++;
    }

    for (int i = 0; i < student; i++)
    {
        printf("%d ", arr[i]);
    }
}
