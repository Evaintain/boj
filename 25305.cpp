#include <bits/stdc++.h>

using namespace std;

/*
25305번 문제

접근 방식
->
N이 1천이하라 선택정렬 쓰려고 했는데 합병정렬 써보려함.
처음 구현해보기에 인터넷의 힘을 빌린다.
*/

int arr[1007];
int sorted[1007];

void merge_arr(int left, int right)
{
    int i, j, k, mid;
    mid = (left + right) / 2;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        //분할 했을때 양쪽에서 따져보는데, i 는 왼쪽에서 중간 까지, j는 중간부터 오른쪽 까지
        //만약 i와 j를 비교했는데 j가 작으면 j를 배열에 넣음.
        if (arr[i] > arr[j])
        {
            sorted[k++] = arr[j++];
        }
        else
        {
            sorted[k++] = arr[i++];
        }
    }

    if (i > mid) //만약 한쪽의 분할된 배열이 다 정렬되면 나머지 배열을 정렬해줌.
    {
        while (j <= right)
        {
            sorted[k++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            sorted[k++] = arr[i++];
        }
    }

    for (int i = left ; i <= right; i++)
    {
        arr[i] = sorted[i];
    }
}

void divide(int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        divide(left, mid);
        divide(mid + 1, right);
        merge_arr(left, right);
    }
}

int main()
{
    int n, k, in_arr;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in_arr);
        arr[i] = in_arr;
    }
    divide(0, n - 1);

    printf("%d", arr[n - k]);
}
