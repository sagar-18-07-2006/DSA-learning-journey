#include<iostream>
using namespace std ;
int main(){
    cout<<"Enter the height  of Quadiretral"<<endl;
    int h;
    cin>>h;
    cout<<"Enter the width  of Quadiretral"<<endl;
    int w;
    cin>>w; 
    for (int  i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
    return 0;
}