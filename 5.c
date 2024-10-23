/*
Question 5
Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.S
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/sysinfo.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long argu_max = sysconf(_SC_ARG_MAX);
    if (argu_max == -1) {
        perror("Error retrieving maximum length of arguments");
    } else {
        printf("a. Maximum length of arguments for exec: %ld bytes\n", argu_max);
    }

    // b. Maximum number of simultaneous processes per user ID
    long child1_max = sysconf(_SC_CHILD_MAX);
    if (child1_max == -1) {
        perror("Error retrieving maximum number of processes per user");
    } else {
        printf("b. Maximum number of simultaneous processes per user ID: %ld\n", child1_max);
    }

    // c. Number of clock ticks (jiffy) per second
    long clk_ticks = sysconf(_SC_CLK_TCK);
    if (clk_ticks == -1) {
        perror("Error retrieving number of clock ticks per second");
    } else {
        printf("c. Number of clock ticks per second: %ld\n", clk_ticks);
    }

    // d. Maximum number of open files
    long fopen_max = sysconf(_SC_OPEN_MAX);
    if (fopen_max == -1) {
        perror("Error retrieving maximum number of open files");
    } else {
        printf("d. Maximum number of open files: %ld\n", fopen_max);
    }

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size == -1) {
        perror("Error retrieving page size");
    } else {
        printf("e. Size of a page: %ld bytes\n", page_size);
    }

    // f. Total number of pages in the physical memory
    struct sysinfo sys_info;
    if (sysinfo(&sys_info) == -1) {
        perror("Error retrieving system information");
    } else {
        long total_pages = sys_info.totalram / sys_info.mem_unit / page_size;
        printf("f. Total number of pages in physical memory: %ld\n", total_pages);
    }

    // g. Number of currently available pages in the physical memory
    long free_pages = sys_info.freeram / sys_info.mem_unit / page_size;
    printf("g. Number of currently available pages in physical memory: %ld\n", free_pages);

    return 0;
}

/*a. Maximum length of arguments for exec: 2097152 bytes
b. Maximum number of simultaneous processes per user ID: 28718
c. Number of clock ticks per second: 100
d. Maximum number of open files: 1048576
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 1857457
g. Number of currently available pages in physical memory: 153642

*/