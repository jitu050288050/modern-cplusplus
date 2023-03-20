/*


L Value :
    if you can take address --->>> L value
    Conceptual motivation -->> L Values may not be moved from.
    could be used more than once in the source code.
    named objects.


R Value :
    Anything that is not L-value is R-value
    cannot bye used by pointers or reference.
    must be used only once.
    Conceptual motivation -->> L Values for move objects.
    un-named objects.


*/

#include <iostream>

int squre(int num)
{
    return num * num;
}

int main_L_value_R_value()
{
    //here we have 2 expressions x and 10. x is l value so it can be copied and can use it several places. 
    // however 10 is r-value expression.
    int x = 10; 

    int* p = &x;

    /* In below expression *p is l value expression and squre(5) is an r value expression.
    */

    *p = squre(5);

    return 1;

}

