#include<iostream>
using namespace std;

int cnt =0 ;
void print(){
   
    cout<<cnt<<" ";
    cnt++;
    if(cnt==5){

        return;
    }
    print();

}
int main (){
    print();
}