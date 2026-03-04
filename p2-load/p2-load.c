/*
 * CS 261 PA2: Mini-ELF loader
 *
 * Name: 
 */

#include "p2-load.h"

/**********************************************************************
 *                         REQUIRED FUNCTIONS
 *********************************************************************/

bool read_phdr (FILE *file, uint16_t offset, elf_phdr_t *phdr)
{
    return true;
}

bool load_segment (FILE *file, byte_t *memory, elf_phdr_t *phdr)
{
    return true;
}

/**********************************************************************
 *                         OPTIONAL FUNCTIONS
 *********************************************************************/

void dump_phdrs (uint16_t numphdrs, elf_phdr_t *phdrs)
{
}

void dump_memory (byte_t *memory, uint16_t start, uint16_t end)
{
}

