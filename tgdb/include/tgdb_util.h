#ifndef __TGDB_UTIL_H__
#define __TGDB_UTIL_H__


/* tgdb_util_new_tty: 
 * This will return a masterfd, slavefd and slavename of a new pseudo terminal.
 * It should be used to tell gdb what tty to redirect the child ( program being
 * debugged) input/output to.
 *
 * The sname char pointer should be SLAVE_SIZE long.
 * 
 * Return: -1 on error, 0 on success.
 */
int tgdb_util_new_tty(int *masterfd, int *slavefd, char *sname);

/* tgdb_util_set_home_dir: Create a config dir in user's home dir.
 * Also saves the absolute path to the user's home directory
 */
int tgdb_util_set_home_dir(void);

/* tgdb_util_get_config_dir: Returns the absolute path to the user's config dir
 * or returns Null on error.
 */
char *tgdb_util_get_config_dir(void);

/* tgdb_util_get_config_gdbinit_file: Returns the absolute path to the 
 * user's gdbinit file or returns Null on error.
 */
char *tgdb_util_get_config_gdbinit_file(void);

/* tgdb_util_get_config_gdb_debug_file: Returns the absolute path to the 
 * user's debug file or returns Null on error.
 */
char *tgdb_util_get_config_gdb_debug_file(void);

/* invoke_debugger: Forks and execs the path.
 *      path: The path to the path.
 *      argc: The number of parameters to the path.
 *      argv:  an array of pointers to null-terminated strings that represent 
 *             the argument list  available  to  the new  program.
 *             The  first argument, by convention, should point to the file 
 *             name associated with the file being executed. The array of 
 *             pointers must be terminated by a NULL pointer.
 *      in:    Writing to this fd, will write to the STDIN of new program.
 *      out:   Reading from fd, will read from the STDOUT-STDERR of new program.
 *      choice: 0 for annotate 2, 1 for gdbmi
 *
 *      Return: -1 on error, pid of child on success
 */
int invoke_debugger(char *path, int argc, char *argv[], int *in, int *out, int choice);

#endif
