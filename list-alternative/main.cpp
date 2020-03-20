#include <iostream>
#include "List.h"
using namespace std;

int main(){

    List<int> myList;


    myList.append(4);
    myList.append(3);
    myList.append(5);
    myList.append(1);
    myList.append(6);

    myList[1] = 0;

    cout<<myList.size()<<endl;


    for(int i = 0; i < myList.size(); i++) cout<<myList[i]<<" ";


}