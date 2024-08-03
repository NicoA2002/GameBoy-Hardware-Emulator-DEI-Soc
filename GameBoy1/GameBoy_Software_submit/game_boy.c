/* * Device driver for the Game Boy joypad
 *
 * A Platform device implemented using the misc subsystem
 * Original By: Justin Hu
 * Modified By: Nicolas Alarcon
 *
 * References:
 * Linux source: Documentation/driver-model/platform.txt
 *               drivers/misc/arm-charlcd.c
 * http://www.linuxforu.com/tag/linux-device-drivers/
 * http://free-electrons.com/docs/
 *
 * "make" to build
 * insmod game_boy.ko
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "game_boy.h"

#define DRIVER_NAME "game_boy"

/* Joypad Register */
#define JOYPAD_REG(x)(x)

/*
 * Information about our device
 */
struct game_boy_dev {
    struct resource res; /* Resource: our registers */
    void __iomem* virtbase; /* Where registers can be accessed in memory */
    uint8_t joypad_status;  // current joypad status

} dev;

static void write_joypad_register(uint8_t * reg)
{
    iowrite8(*reg, JOYPAD_REG(dev.virtbase));
    dev.joypad_status = *reg;
}

/*
 * Handle ioctl() calls from userspace:
 * Read or write the segments on single digits.
 * Note extensive error checking of arguments
 */
static long game_boy_ioctl(struct file* f, unsigned int cmd, unsigned long arg)
{
    uint8_t joypad_reg;

    switch (cmd) {
    case GAME_BOY_WRITE_JOYPAD:
        if (copy_from_user(&joypad_reg, (uint8_t*)arg,
            sizeof(uint8_t)))
            return -EACCES;
        write_joypad_register(&joypad_reg);
        break;
    default:
        return -EINVAL;
    }

    return 0;
}

/* The operations our device knows how to do */
static const struct file_operations game_boy_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = game_boy_ioctl,
};

/* Information about our device for the "misc" framework -- like a char dev */
static struct miscdevice game_boy_misc_device = {
    .minor      = MISC_DYNAMIC_MINOR,
    .name       = DRIVER_NAME,
    .fops       = &game_boy_fops,
};


/*
 * Initialization code: get resources (registers) and display
 * a welcome message
 */
static int __init game_boy_probe(struct platform_device* pdev)
{
    uint8_t joypad_init = 0x00; // initialize joypad
    int ret;

    /* Register ourselves as a misc device: creates /dev/game_boy */
    ret = misc_register(&game_boy_misc_device);

    /* Get the address of our registers from the device tree */
    ret = of_address_to_resource(pdev->dev.of_node, 0, &dev.res);
    if (ret) {
        ret = -ENOENT;
        goto out_deregister;
    }

    /* Make sure we can use these registers */
    if (request_mem_region(dev.res.start, resource_size(&dev.res),
                    DRIVER_NAME) == NULL) {
        ret = -EBUSY;
        goto out_deregister;
    }

    /* Arrange access to our registers */
    dev.virtbase = of_iomap(pdev->dev.of_node, 0);
    if (dev.virtbase == NULL) {
        ret = -ENOMEM;
        goto out_release_mem_region;
    }

    /* Set an initial state */
    write_joypad_register(&joypad_init);

    return 0;

out_release_mem_region:
    release_mem_region(dev.res.start, resource_size(&dev.res));
out_deregister:
    misc_deregister(&game_boy_misc_device);
    return ret;
}

/* Clean-up code: release resources */
static int game_boy_remove(struct platform_device* pdev)
{
    iounmap(dev.virtbase);
    release_mem_region(dev.res.start, resource_size(&dev.res));
    misc_deregister(&game_boy_misc_device);
    return 0;
}

/* Which "compatible" string(s) to search for in the Device Tree */
#ifdef CONFIG_OF
static const struct of_device_id game_boy_of_match[] = {
    	{ .compatible = "csee4840,joypad-1.0" },
        {},
};
MODULE_DEVICE_TABLE(of, game_boy_of_match);
#endif

/* Information for registering ourselves as a "platform" driver */
static struct platform_driver game_boy_driver = {
    .driver = {
        .name   = DRIVER_NAME,
        .owner  = THIS_MODULE,
        .of_match_table = of_match_ptr(game_boy_of_match),
    },
    .remove = __exit_p(game_boy_remove),
};

/* Called when the module is loaded: set things up */
static int __init game_boy_init(void)
{
    pr_info(DRIVER_NAME ": init\n");
    return platform_driver_probe(&game_boy_driver, game_boy_probe);
}

/* Calball when the module is unloaded: release resources */
static void __exit game_boy_exit(void)
{
    platform_driver_unregister(&game_boy_driver);
    pr_info(DRIVER_NAME ": exit\n");
}

// ****************************************************************************

module_init(game_boy_init);
module_exit(game_boy_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nicolas Alarcon, Columbia University");
MODULE_DESCRIPTION("Game Boy Joypad Driver");
