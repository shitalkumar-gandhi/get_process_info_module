# README

This is a simple kernel module which will print all the information of specific process.
The user has to give process id as an argument while inserting this module into the system.

## Compilation (Building the .ko module in kernel 4.11 or above)
```
make
```
This step will generate get_process_info_module.ko file 

## Clean the build
```
make clean
```

## Installation
```
insmod get_process_info_module.ko pid=<process id num> or modprobe get_process_info_module.ko pid=<process id num>
```
## Removing the module from the system
```
rmmod get_process_info_module.ko or modprobe -r get_process_info_module.ko
```

## Log messages
User can see all the module messages into kernel log using dmesg command.
```
dmesg
```

## Test result
```
shital@ubuntu:~/Desktop/driver$ dmesg 
[  118.262400] get_process_info_exit: exit from print_process_info module
[  123.849554] get_process_info_init: intialize print_process_info module 
[  123.849560] Error - process with id 2047 is not exist
[  197.057295] get_process_info_exit: exit from print_process_info module
[  198.220450] get_process_info_init: intialize print_process_info module 
[  198.220452] Error - process with id 2047 is not exist
[  212.402689] get_process_info_exit: exit from print_process_info module
[  229.292350] get_process_info_init: intialize print_process_info module 
[  229.292352] Process pid is : 3144
[  229.292353] Process name : a.out
[  229.292353] Process priority : 0
[  229.292354] Process policy : SCHED_OTHER
[  229.292354] Start time of process in clock ticks : 215740198794
[  229.292355] Process state : TASK_INTERRUPTIBLE
[  229.292355] Number of minor page faults in process : 73
[  229.292356] Number of major page faults in process : 0
[  229.292356] CPU time spent in process in user : 0
[  229.292357] CPU time spent in process in kernel : 4000000
[  229.292357] Process flags : 1077936128
[  229.292358] Process code segment start = 0x55e9b2f55000, end = 0x55e9b2f55880 
               Process data  segment start = 0x55e9b3155db0, end = 0x55e9b3156010
               Process stack segment start = 0x7ffe94803240
```
