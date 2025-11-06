#include <iostream>
#define MAX_STR_LENGTH 100
using namespace std;

void print_merged(const char (*str)[MAX_STR_LENGTH])
{
    /****************** TODO ******************/

    int i = 0, j = 0;
    const char *s0 = str[0];
    const char *s1 = str[1];

    bool first = true;
    while (true)
    {
        bool any = false;

        while (s0[i] == ' ')
        {
            i++;
        }
        if (s0[i] != '\0')
        {
            if (!first)
            {
                cout << ' ';
            }
            first = false;
            while (s0[i] != ' ' && s0[i] != '\0')
            {
                cout << s0[i++];
            }
            any = true;
        }

        while (s1[j] == ' ')
        {
            j++;
        }
        if (s1[j] != '\0')
        {
            if (!first)
            {
                cout << ' ';
            }
            first = false;
            while (s1[j] != ' ' && s1[j] != '\0')
            {
                cout << s1[j++];
            }
            any = true;
        }

        if (!any)
        {
            break;
        }
    }

    /**************** TODO-END ****************/
}

int main()
{
    char str[2][MAX_STR_LENGTH] = {};

    cin.getline(str[0], MAX_STR_LENGTH);
    cin.getline(str[1], MAX_STR_LENGTH);

    print_merged(str);

    return 0;
}