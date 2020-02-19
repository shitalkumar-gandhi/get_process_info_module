#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

static long int pid;
module_param(pid, long, S_IRUSR);
MODULE_PARM_DESC(pid, "A long integer for process id");

char buffer[256] = {0};
char *get_task_state(long state)
{
  switch (state) {
  case TASK_RUNNING:
    return "TASK_RUNNING";
  case TASK_INTERRUPTIBLE:
    return "TASK_INTERRUPTIBLE";
  case TASK_UNINTERRUPTIBLE:
    return "TASK_UNINTERRUPTIBLE";
  case __TASK_STOPPED:
    return "__TASK_STOPPED";
  case __TASK_TRACED:
    return "__TASK_TRACED";
  default:
  {
    sprintf(buffer, "Unknown state:%ld\n", state);
    return buffer;
  }
  }
}

/*
 * Scheduling policies
 */
#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2

char *get_task_policy(long state)
{
  switch (state) {
  case SCHED_OTHER:
    return "SCHED_OTHER";
  case SCHED_FIFO:
    return "SCHED_FIFO";
  case SCHED_RR:
    return "SCHED_RR";
  default:
  {
    sprintf(buffer, "Unknown policy:%ld\n", state);
    return buffer;
  }
  }
}

static int get_process_info_init(void)
{
  struct task_struct *task = NULL;
  struct pid *pid_struct = NULL;
  pr_info("%s: intialize print_process_info module \n", __func__);

  pid_struct = find_get_pid(pid);
  task = pid_task(pid_struct,PIDTYPE_PID);
  if (task != NULL)
  {
    struct mm_struct *mm = task->mm;

    pr_info("Process pid is : %ld\n", pid);
    pr_info("Process name : %s\n", task->comm);
    pr_info("Process priority : %u\n", task->rt_priority);
    pr_info("Process policy : %s\n", get_task_policy(task->policy));
    pr_info("Start time of process in clock ticks : %llu\n", task->start_time);
    pr_info("Process state : %s\n", get_task_state(task->state));
    pr_info("Number of minor page faults in process : %lu\n", task->min_flt);
    pr_info("Number of major page faults in process : %lu\n", task->maj_flt);
    pr_info("CPU time spent in process in user : %lli\n", task->utime);
    pr_info("CPU time spent in process in kernel : %lli\n", task->stime);
    pr_info("Process flags : %u\n", task->flags);
    pr_info("Process code segment start = 0x%lx, end = 0x%lx\n"
            "Process data  segment start = 0x%lx, end = 0x%lx\n"
            "Process stack segment start = 0x%lx\n", mm->start_code, mm->end_code, mm->start_data, mm->end_data, mm->start_stack);
    pr_info("Threded group id of process = %d\n", task->tgid);
  }
  else
  {
    pr_info("Invalid id : process with pid %ld is not exist\n", pid);
  }
  return 0;
}

static void get_process_info_exit(void)
{
  pr_info("%s: exit from print_process_info module\n", __func__);
  return;
}

module_init(get_process_info_init);
module_exit(get_process_info_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR ("Shitalkumar Gandhi, shital_909@yahoo.com");
MODULE_DESCRIPTION ("Print process information of given pid");
