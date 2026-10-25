#include <stdio.h>
#include <assert.h>
#include "../BCSRec/functions.h"

int main(void) {

    assert(setLength(10) == 10);
    assert(setWidth(5) == 5);
    assert(getArea(10, 5) == 50);
    assert(getPerimeter(10, 5) == 30);

    printf("All unit tests passed!\n");

    return 0;
}