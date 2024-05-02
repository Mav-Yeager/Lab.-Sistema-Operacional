#define MODULE
#define LINUX
#define __KERNEL__  

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int mav_sarah_init(void)
{
   printk(KERN_ALERT "Ola, mundo :D 1.\n");
   return 0;
}


static void mav_sarah_exit(void)
{
  printk(KERN_ALERT "bye bye mundo! o/ 1.\n");
}  

module_init (mav_sarah_init);
module_exit (mav_sarah_exit);

MODULE_LICENSE("GPL");
