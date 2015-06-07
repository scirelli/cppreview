#include <iostream>

using namespace std;

void testRef( int a ){
    a = a + 1;
    return;
}

void testPtr( int * const a ){
    int *v;
    *a = *a + 1;
    a = v;
    return;
}

int main( int argc, char* argv[] ){
    int c = 1;
    cout << c << "\n";
    testRef(c);
    cout << c << "\n";
    c = 2;
    testPtr(&c);
    cout << c << "\n";
    return 0;
}
