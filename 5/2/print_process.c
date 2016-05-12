/*************************************************************************
	> File Name: print_process.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月11日 星期三 20时00分54秒
 ************************************************************************/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/list.h>
#define METHOD 1

MODULE_LICENSE("GPL");

static int list_init(void)
{
    struct task_struct *task, *p;
    struct list_head *pos;
    int count;
    char *method;
    count = 0;
    p = NULL;
    task = NULL;
    pos = NULL;
    method = NULL;
    task = &init_task;
    printk(KERN_ALERT "PID\tCOMM\n");
    switch (METHOD)
    {
        case 1:
            {
                method = "list_for_each";
                break;
            }
        case 2:
            {
                method = "for_each_process";
                break;
            }
        case 3:
            {
                method = "list_for_each_entry";
                break;
            }
    }
    printk("The method is %s\n", method);

#if METHOD == 1
    list_for_each(pos, &task->tasks)
    {
        p = list_entry(pos, struct task_struct, tasks);
        count++;
        printk(KERN_ALERT "%d\t%s\n", p->pid, p->comm);
    }

#elif METHOD == 2
    for_each_process(task)
    {
        count++;
        printk(KERN_ALERT "%d\t%s\n", task->pid, task->comm);
    }

#elif METHOD == 3
    list_for_each_entry(p, &task->tasks, tasks)
    {
        count++;
        printk(KERN_ALERT "%d\t%s\n", p->pid, p->comm);
    }

#endif
    printk("系统当前共有%d个进程!", count);
    return 0;
}

static void list_exit(void)
{
    printk(KERN_ALERT "Good bye !!/n");
}

module_init(list_init);
module_exit(list_exit);

MODULE_AUTHOR("ai");
MODULE_DESCRIPTION("print_process");
