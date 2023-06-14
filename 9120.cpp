#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
9120번 문제 접근 방식
->
kmp 알고리즘을 통한 문자열 비교.
시행마다 초기화하는것 잊지 말기
*/

/*
태그
. 문자열
. kmp
*/

char string_c[10007];
char string_o[1000007];

class kmp
{
private:
    int cnt = 0;
    int n;

public:
    void init(int len)
    {
        cnt = 0;
        this->n = len;
    }

    vector<int> make_table()
    {
        vector<int> table(n, 0);

        int start = 1;
        int match = 0;
        while (start + match < n)
        {
            if (string_c[start + match] == string_c[match])
            {
                match++;
                table[start + match - 1] = match;
            }

            else
            {
                if (match == 0)
                {
                    start++;
                }

                else
                {
                    start += match - table[match - 1];
                    match = table[match - 1];
                }
            }
        }

        return table;
    }

    void execute(int c_len, int o_len)
    {
        init(c_len);
        vector<int> table = make_table();

        int start = 0;
        int match = 0;
        for (int i = 0; i < o_len; i++)
        {
            while (match > 0 && string_o[i] != string_c[match])
            {
                match = table[match - 1];
            }

            if (string_o[i] == string_c[match])
            {
                match++;
                if (match == c_len)
                {
                    cnt++;
                    match = table[match - 1];
                }
            }
        }

        printf("%d\n", cnt);
    }
};

int main()
{
    int c_len, o_len, n;
    kmp k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", string_c);
        scanf("%s", string_o);
        c_len = strlen(string_c);
        o_len = strlen(string_o);

        k.execute(c_len, o_len);
    }
}
