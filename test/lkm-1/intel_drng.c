#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/types.h>

#include "intel_drng.h"

static int drng_init(void)
{
	printk(KERN_INFO "Loading Intel DRNG Accessor Module\n");
#ifdef __x86_64__
    printk(KERN_INFO "64-bit Random Number: %llu\n", random_64());
#endif
    printk(KERN_INFO "32-bit Random Number: %u\n", random_32());
    printk(KERN_INFO "16-bit Random Number: %u\n", random_16());

    return 0;
}

static void drng_exit(void)
{
	printk(KERN_INFO "Unloading Intel DRNG Accessor Module... Goodbye!\n");
#ifdef __x86_64__
    printk(KERN_INFO "64-bit Random Number: %llu\n", random_64());
#endif
    printk(KERN_INFO "32-bit Random Number: %u\n", random_32());
    printk(KERN_INFO "16-bit Random Number: %u\n", random_16());
}

module_init(drng_init);
module_exit(drng_exit);

MODULE_AUTHOR("Abhinava Sadasivarao");
MODULE_DESCRIPTION("A simple kernel module that generates random numbers using Intel DRNG.");
MODULE_LICENSE("MIT");
MODULE_VERSION("1.0");
