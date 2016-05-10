/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月10日 星期二 10时55分55秒
 ************************************************************************/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

//模块许可声明
MODULE_LICENSE("GPL");

//模块加载函数
static int __init hello_init(void)
{
    printk(KERN_ALERT "hello kernel!\n");
    return 0;
}

//模块卸载函数
static void __exit hello_exit(void)
{
    printk(KERN_ALERT "Goodbye!\n");
}

//模块注册
module_init(hello_init);
module_exit(hello_exit);
//可选
MODULE_AUTHOR("ai");
MODULE_DESCRIPTION("hello");

