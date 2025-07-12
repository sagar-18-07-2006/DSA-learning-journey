#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int hash[256]={0};
    for (int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c ;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}