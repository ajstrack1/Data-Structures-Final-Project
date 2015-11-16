/*
 * Implement Red-Black Tree and its operations.
 *
 * Goals:
 * Accept input from user
 * Construct and display the tree
 * Prompt for item to be deleted. Display tree after deletion
 *
 *
 */

#include<iostream>
#include<ctime>
#include "red_black_template.h"
using namespace std;

const int N = 15;

int main(){
    rbtree<int> test;
    int answer;
    srand( (unsigned)time(NULL) );
    srand( rand() );
    srand( rand() );
    while(true) {
        cin >> answer;
        if (answer == -999)
            break;
        test.insert(answer);
    }

    int a;
    test.display();
    while( cin >> a ){
        test.erase( a );
        test.display();
    }
    return 0;
}
