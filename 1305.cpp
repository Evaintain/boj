#include <iostream>
#include <vector>

using namespace std;

/*
1305번 문제 접근 방식
->
5 aaaaa -> a가 보일수 있음
6 aabaaa -> aaba 4임.
매치가 안되는 부분이 길이가 아닐까 싶음.
*/

/*
태그
. 문자열
. kmp
*/

char input[1000007];

class kmp
{
private:
    int n;

public:
    void init(int cnt)
    {
        this->n = cnt;
    }

    vector<int> make_table()
    {
        vector<int> table(n, 0);

        int start = 1;
        int match = 0;

        while (start + match < n)
        {
            if (input[start + match] == input[match])
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

    void execute(int n)
    {
        init(n);
        vector<int> table = make_table();

        printf("%d", n - table[n - 1]);
    }
};

int main()
{
    int n;
    kmp k;

    scanf("%d", &n);
    scanf("%s", input);

    k.execute(n);
}
