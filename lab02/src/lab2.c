#include <stdio.h>

//
// Struct definitions
//

struct Apple
{
    double weight;
    char*  variety;
    char*  color;
};

//
// Function declarations
//

int some_numbers(int);

//
// Function definition
//

int main()
{
    struct Apple delicious = { 0.3, "Red Delicious", "red" };
    printf("My %s apple is the color %s and weighs %g lbs.\n",
            delicious.variety, delicious.color, delicious.weight);
}

int some_numbers(int num)
{
    // TODO;
    return -1;
}