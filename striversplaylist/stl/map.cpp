#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string,int> student_marks;
    student_marks["sagar"] =90;
    student_marks["prince"] = 92;
    student_marks["yash"]=91;
    student_marks.insert({{"hardik",50},{"aditya s",40}});
    map<string,int> :: iterator iter;
    for(iter =student_marks.begin();iter!=student_marks.end();iter++){
        cout<<iter->first<<" "<<iter->  second<<endl;
    }
}