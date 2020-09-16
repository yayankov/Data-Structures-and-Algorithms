![EncodingPassword](https://user-images.githubusercontent.com/52356711/93354323-8b329000-f845-11ea-9b98-a9c0327b63b8.JPG)

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        int ctr = 1;
        while (str[i] == str[i+1])
        {
            ctr++;
            i++;
        }
        cout << ctr << str[i];
    }

    system("pause");
    return 0;
}
