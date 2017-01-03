#ifndef __ELF_STRUCT_H__
#define __ELF_STRUCT_H__

#include <elf.h>
#include <stdio.h>

#define ERROR_MALLOC_HEADER -1
#define ERROR_READ_HEADER -2
#define ERROR_MALOC_A_SHDR -3
#define ERROR_FILL_A_SHDR -4

typedef struct ELF_STRUCT {

	FILE* elf_file;
	Elf32_Ehdr *elf_header;

} ELF_STRUCT;

#endif