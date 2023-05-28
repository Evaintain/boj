#include <iostream>

/*
2495번 문제 접근 방식
->
for문 3번, 입력후 for문 8번으로 길이를 구한다.
*/

int main()
{
    char input[17];
    int total = 0;
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", input);
        total = result = 1;
        for (int j = 1; j < 8; j++)
        {
            if (input[j] == input[j - 1])
            {
                result++;
            }
            else
            {
                total = total > result ? total : result;
                result = 1;
            }
        }
        
        // 사례(모든게 같을시)
        total = total > result ? total : result;
        
        printf("%d\n", total);
    }
}
