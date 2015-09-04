#include "commonheader.h"
/*
void myfun (int sig, siginfo_t * siginfo, void * q)
{
	if (SIGINT == sig)
	{
		sleep (2);
		printf ("it is too late, wake up,from %d\n", siginfo->si_pid);
	}
}
*/
void myfun2 (int sig)
{
	if (SIGINT == sig)
	{
		sleep (2);
		printf ("it is too late, wake up,from\n");
	}
}

int main (void)
{
	int i;
/*
	struct sigaction nact, oact;

	nact.sa_sigaction = myfun;

	nact.sa_flags = SA_SIGINFO;

    sigemptyset (&nact.sa_mask);


	sigaction (SIGINT, &nact, &oact);
*/
	signal (SIGINT, myfun2);
	for (i=0; i<10; ++i)
	{
		raise (SIGINT); 
	}

}
