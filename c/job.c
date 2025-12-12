#include <stdio.h>
#include <sys/types.h>
#include <termios.h>

#include "process.h"

typedef struct job
{
    struct job    *next;  // next active job
    char          *command;  // command line used for messages
    process       *first_process;  // list of processes in this job
    pid_t          pgid;  // process group ID
    char           notified;  // true if user told about stopped job
    struct termios tmodes;  // saved terminal modes
    int            stdin, stdout, stderr;  // standard i/o channels
} job;

job *first_job = NULL;

// Find the active job with the indicated pgid.
job *find_job(pid_t pgid)
{
    job *j;

    for (j = first_job; j; j = j->next) {
        if (j->pgid == pgid) {
            return j;
        }
    }
    return NULL;
}

// Return true if all processes in the job have stopped or completed
int job_is_stopped(job *j)
{
    process *p;

    for (p = j->first_process; p; p = p->next) {
        if (!p->completed) {
            return 0;
        }
    }
    return 1;
}
