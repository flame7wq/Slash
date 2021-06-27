#include <iostream>
#include <string>
using namespace std;

void Usage()
{
    cout << "slash - add or change \\ in arg[2] (default -c)" << endl;
    cout << "      -a add \\" << endl;
    cout << "      -c change \\ to /\n" << endl;
}

void add_slash(string str)
{
    string a;
    string tmp = str;
    for (auto n : tmp)
    {
        if (n != '\\')
            a += n;
        else
        {
            a += "\\\\";
        }
    }
    cout << a << endl;
}
void change_slash(string str)
{
    string a = "/mnt/";
    string tmp = str;
    for (auto n : tmp)
    {
        if (n != '\\')
            a += n;
        else
        {
            a += "/";
        }
    }
    cout << a << endl;
}

void deal_disk_symbol(char* s)
{
    string a;
    bool find = false;
    int i = 0;
    for (i = 1; i < strlen(s); i++)
    {
        if (s[i] == ':' && s[i - 1] >= 'A')
        {
            s[i - 1] ^= 32;
            find = true;
        }
        if (find)
            s[i] = s[i + 1];
    }
    s[i] = 0;
}

int main(int argc, char* argv[])
{
    //Usage();
    //char str[] = "C:\\User\\Admin";

    //add_slash(str);
    //deal_disk_symbol(str);
    //change_slash(str);
    if (argc == 2)
    {
        add_slash(argv[1]);
    }
    else if (argc == 3)
    {
        if (!strcmp(argv[1], "-a"))
            add_slash(argv[2]);
        else if (!strcmp(argv[1], "-c"))
        {
            deal_disk_symbol(argv[2]);
            change_slash(argv[2]);
        }
        else
            Usage();
    }
    else
        Usage();

    return 0;
}
