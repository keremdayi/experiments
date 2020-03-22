#include <stdio.h> // c library for input output
#include <iostream>
#include "List.h"

using namespace std;
using namespace krm;

class Test {
private:
    int _n;
public:
Test(){
    _n=-1;
}
Test(int n) {
    _n = n;
}

void describe(){
    cout<<"Hello: "<<_n<<endl;
}

};

int main(){
    List<int> myList(10, 0); // creates a list with 10 elements all of which are 0
    myList[2] = 5;
    myList[3] = 1; 
    myList.append(11);

    for(int i = 0; i < myList.size(); i++)
    {
        cout<<myList[i]<<endl;
    }
    return 0;
}