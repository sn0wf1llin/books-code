#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  char buf[1]; /* �뤥�塞 ���� � �⥪� ࠧ��஬ 1 ���� */
  char *egg;
  int fd;
  size_t length;
  struct stat file_info;
  
  /* ���뢠�� 䠩� /etc/passwd �� �⥭�� */
  fd=open("/etc/passwd", O_RDONLY);
  /* ��।��塞 ࠧ��� 䠩�� */
  fstat (fd, &file_info);
  length=file_info.st_size;
  /* �뤥�塞 ���� � ��� */
  egg=(char *)malloc(length);
  /* ��६�頥� 䠩� � �뤥����� ���� */
  read (fd, egg, length);
  /* ����뢠�� ���ਯ�� 䠩�� */
  close (fd);
  /* ��९���塞 ���� � �⥪� */
  strcpy(buf, "aaaaaaaaaaaaaaaaaaaa");

  return 0;
}
