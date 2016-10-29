/*!	\file	fork_lab.c
 * 	\brief	Laboratory work №1 variant 15, forc and exec process,
 *
 * 	\details	Forking child process with its executing. (TODO)
 *
 *
 *  Created on: Oct 29, 2016
 *      Author: kate
 */

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*! Global variable for exit status of child process */
sig_atomic_t g_ChildExitStatus;

/*! \brief Cleaning up the child process
 *
 *  \details Clean up the child process via signal catching.
 *           Store process's exit status.
 *  \param signalNumber
 *  \return void
 *  \par    Side effect:
 *          changes the g_ChildExitStatus variable
 */

void CleanUpChildProcess(int signalNumber)
{
  /* Clean up the child process.  */
  int status;
  wait(&status);

  /* Store its exit status in a global variable.  */
  g_ChildExitStatus = status;
}
int lab1_swapn (char* program, char** argList)
{
  pid_t childPid;

  /* Duplicate this process.  */
  childPid = fork();
  if (0 != childPid)
  {
    /* This is the parent process.  */
    return childPid;
  }
  else
  {
    /* Now execute PROGRAM, searching for it in the path. */
    execvp(program, argList);

    /* The execvp function returns only if an error occurs.  */
    fprintf(stderr, "an error occurred in execvp\n");
    abort();
  }
}

int main(){
	/* Handle SIGCHLD by calling CleanUpChildProcess. */
	struct sigaction sigchldAction;
	memset (&sigchldAction, 0, sizeof (sigchldAction));
	sigchldAction.sa_handler = &CleanUpChildProcess;
 	sigaction(SIGCHLD, &sigchldAction, NULL);

	int childStatus;
	/* The argument list.  */
	char* argList[] =
	{
			//? TODO разобраться
	};

	lab1_swapn("lab.c", argList);

	/* Wait for child process  */
	wait(&childStatus);
	if(WIFEXITED(childStatus))
	{
		printf("The child process exited normally with code %d.\n", WEXITSTATUS(childStatus));
	}
	else
	{
		printf("The child process exited abnormally.\n");
	}
	return 0;
}
