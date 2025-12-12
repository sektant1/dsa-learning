
#include <sys/types.h>

// A process is a single process, duh
typedef struct process
{
    struct process *next;       // next process in the pipeline
    char          **argv;       // for exec
    pid_t           pid;        // process ID
    char            completed;  // true if process has completed
    char            stopped;    // true if process has stopped
    int             status;     // reported status value
} process;
