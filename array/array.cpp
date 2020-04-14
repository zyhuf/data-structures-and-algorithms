#include <iostream>
#include "array.h"
using namespace std;

int main(int argc, char *argv[])
{
    Array<int> arr(10);
    arr[1] = 1;
    arr[2] = 10;
    arr[5] = 20;

    arr.print();

    Array<int> tmpArr;
    tmpArr = arr;
    tmpArr.print();
}