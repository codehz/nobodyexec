#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("argc <= 1\n");
    return EXIT_FAILURE;
  }
  const char *name = "nobody";
  struct passwd *p;
  if ((p = getpwnam(name)) == NULL)
  {
    perror(name);
    return EXIT_FAILURE;
  }
  if (0 != setgroups(0, 0))
  {
    perror("setgroups");
    return EXIT_FAILURE;
  }
  if (0 != setgid(p->pw_gid))
  {
    perror("setgid");
    return EXIT_FAILURE;
  }
  if (0 != setuid(p->pw_uid))
  {
    perror("setuid");
    return EXIT_FAILURE;
  }
  if (0 != execvp(argv[1], argv + 1))
  {
    perror("execv");
    return EXIT_FAILURE;
  }
}