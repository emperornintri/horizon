#include <exit_horizon.h>

extern int main ();

void startHorizon ()
{
    int status = main ();
    exitHorizon (status);
}