#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


static char child_stack[1048576];

static int child_fn(void *arg) {
    // 1. Set up networking if a Network Namespace is used.
    
    // 2. Set up an overlay filesystem or bind mounts if a Mount Namespace is used.
    
    // 3. Use chroot or pivot_root to change the root filesystem.
    
    // 4. Set hostname if a UTS Namespace is used.
    
    // 5. Execute the specified command using execvp or a similar function.
    char *cmd[] = { (char *)arg, NULL };
    execvp(cmd[0], cmd);
    
    // Error handling if execvp fails.
    perror("execvp");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <cmd>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create flags for other namespaces like CLONE_NEWNET, CLONE_NEWNS, CLONE_NEWUSER, etc.
    int flags = SIGCHLD | CLONE_NEWPID; /* Other Namespace Flags */
    
    // Create cgroups and set limits on resources like CPU, memory, etc.
    
    pid_t child_pid = clone(child_fn, child_stack + sizeof(child_stack), flags, argv[1]);
    if (child_pid < 0) {
        perror("clone");
        exit(EXIT_FAILURE);
    }

    // Setup networking, assign IP, etc., if Network Namespace is used.
    
    // Wait for the child to exit.
    waitpid(child_pid, NULL, 0);
    return 0;
}
