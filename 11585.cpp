#include <iostream>
#include <vector>

using namespace std;

/*
11585번 문제 접근 방식
->
총 가능한 패턴수 -> n
이중 겹치는 패턴수를 m이라 하면
m / n일것임.

- 이하는 구글링 이후에 작성하는 내용임-
abcd에서 회전시 나올수 있는 경우의수 4가지
abcd | bcda | cdab | dabc
=> 문자열 + 문자열(마지막 글자 제외) 한것과 같음.
그러면 찾아야하는 문자열 2 * n - 1자리.
kmp 알고리즘을 통해서 해결한다.
*/

/*
태그
. 문자열
. kmp
*/

char string_c[1000007];
char string_o[2000015];
char input[2000015];

class kmp
{
private:
    int cnt = 0;

public:
    vector<int> make_table(int n)
    {
        vector<int> table(n, 0);
        int match = 0;

        for (int i = 1; i < n; i++)
        {
            while (match > 0 && string_c[i] != string_c[match])
            {
                match = table[match - 1];
            }

            if (string_c[i] == string_c[match])
            {
                match++;
                table[i] = match;
            }
        }

        return table;
    }

    int gcd(int a, int b)
    {
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        if (b == 0)
        {
            return a;
        }

        if (a % b == 0)
        {
            return b;
        }

        return gcd(b, a % b);
    }

    void execute(int n)
    {
        vector<int> table = make_table(n);

        int match = 0;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            while (match > 0 && string_o[i] != string_c[match])
            {
                match = table[match - 1];
            }

            if (string_o[i] == string_c[match])
            {
                match++;
                if (match == n)
                {
                    cnt++;
                    match = table[match - 1];
                }
            }
        }

        int g = gcd(n, cnt);

        printf("%d/%d", cnt / g, n / g);
    }
};

int main()
{
    int n;
    kmp k;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &string_c[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &string_o[i]);
        if (i + 1 != n)
        {
            string_o[i + n] = string_o[i];
        }
    }

    k.execute(n);
}
