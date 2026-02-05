#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

static int __init marvellous__init(void)
{
	printk(KERN_INFO "Marvellous Module gets inserted: Jay Ganesh...\n");
	return 0;
}

static void __exit marvellous__exit(void)
{
	printk(KERN_INFO "Marvellous Module gets removed\n");
}

module_init(marvellous__init);

module_exit(marvellous__exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marvellous Infosystems"); // optional
MODULE_DESCRIPTION("Demo Kernel Module"); // optional

