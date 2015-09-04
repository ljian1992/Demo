#include "commonheader.h"
#include <signal.h>
void myAction (int signal)
{
     if ( SIGKILL == signal )
	 {
		 printf ("i got it\n");
	 }
}

int main (void)
{

	signal (SIGKILL, myAction);

	pause ();
	

	return 0;
}
