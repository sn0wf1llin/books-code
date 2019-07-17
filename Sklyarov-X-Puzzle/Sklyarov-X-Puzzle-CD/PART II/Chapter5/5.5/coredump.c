#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  char buf[1]; /* Выделяем буфер в стеке размером 1 байт */
  char *egg;
  int fd;
  size_t length;
  struct stat file_info;
  
  /* Открываем файл /etc/passwd на чтение */
  fd=open("/etc/passwd", O_RDONLY);
  /* Определяем размер файла */
  fstat (fd, &file_info);
  length=file_info.st_size;
  /* Выделяем буфер в куче */
  egg=(char *)malloc(length);
  /* Перемещаем файл в выделенный буфер */
  read (fd, egg, length);
  /* Закрываем дескриптор файла */
  close (fd);
  /* Переполняем буфер в стеке */
  strcpy(buf, "aaaaaaaaaaaaaaaaaaaa");

  return 0;
}
