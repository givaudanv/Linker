#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "global_struct.h"
#include "fusion.h"
#include "util.h"

int Fusion(ELF_STRUCT * elf1, ELF_STRUCT * elf2) {
	ELF_STRUCT * elf_fusion = NULL;
	Elf32_Shdr * shelf1 = elf1->a_shdr;
	Elf32_Shdr * shelf2 = elf2->a_shdr;
	char * cont_section1;
	char * cont_section2;
	char * cont_final;
	int i = 0;
	int j = 0;

	while (i < elf1->elf_header->e_shnum) {
		if (shelf1->sh_type == 1) {
			while (j < elf2->elf_header->e_shnum) {
				if (shelf2->sh_type == 1 && strcmp(get_name(elf1,i), get_name(elf2,j)) == 0) {
					cont_section1 = malloc(sizeof(char)*shelf1->sh_size);
					cont_section2 = malloc(sizeof(char)*shelf2->sh_size);
					cont_final = malloc(sizeof(char)*(shelf1->sh_size+shelf2->sh_size));
					
					read_section(shelf1, elf1, cont_section1);
					read_section(shelf2, elf2, cont_section2);
					contfinal="";
					strcat(contfinal,cont_section1);
					strcat(contfinal,cont_section2);
				}
				j++;
			}
		}
		i++;
	}
		

	return 1;
}
