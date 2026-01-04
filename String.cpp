#include "String.h"

int main()
{
    String mystring;
    //cout << mystring.reverseStr("abcdefghi", 3) << endl;

    //string A = "the sky is blue";
    //A = mystring.reverseWords(A);
    //cout << A << endl;


    // Ìæ»»Êý×Ö
    /*string s;
    while (cin >> s) {
        int oldIndex = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]>='0' && s[i]<='9')
            {
                count++;
            }
        }

        s.resize(oldIndex + 1 + count * 5);
        int newIndex = s.size() - 1;
        while (oldIndex>=0)
        {
            if (s[oldIndex] >= '0' && s[oldIndex] <= '9')
            {
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            }
            else
            {
                 s[newIndex--] = s[oldIndex];
            }
            oldIndex--;
        }
        cout << s << endl;
    }*/


    // ÓÒÐý×Ö·û´®
    int k;
    string s;
    cin >> k;
    cin >> s;
    if (k < s.size())
    {
        // right
        //reverse(s.begin(), s.end());
        //reverse(s.begin(), s.begin() + k);
        //reverse(s.begin() + k, s.end());

        // left
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
    }

    cout << s << endl;

}
