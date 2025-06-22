#include <exit_horizon.h>


extern int main();    


void startHorizon()
{
    int result = main();
    exitHorizon(result);
}