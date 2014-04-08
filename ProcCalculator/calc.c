#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/proc_fs.h>

#define WRITE_SIZE 100

#define ARG1 "arg1"
#define ARG2 "arg2"
#define OPERATION "operation"
#define RESULT "result"

#define PARENT_DIR "calc"

struct proc_dir_entry *calc_dir;
struct proc_dir_entry *arg1;
struct proc_dir_entry *arg2;
struct proc_dir_entry *operation;
struct proc_dir_entry *result;


static char arg1_input[WRITE_SIZE];
static char arg2_input[WRITE_SIZE];
static char operation_input[WRITE_SIZE];



int init_module()
{
	// parent dir
	calc_dir = proc_mkdir(PARENT_DIR, NULL);
	


	return 0;
}

void cleanup_module()
{
	remove_proc_entry(ARG1, NULL);
	remove_proc_entry(ARG2, NULL);
	remove_proc_entry(OPERATION, NULL);
	remove_proc_entry(RESULT, NULL);
	printk(KERN_INFO "/proc/%s removed\n", PARENT_DIR);
}

