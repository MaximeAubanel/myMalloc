# Malloc

## Introduction

Using only brk/sbrk and your amazing mind, rewrite the 3 following C library functions: malloc, free and realloc.

## Technical Constraints

Unauthorized functions:
- mmap
- munmap
- *alloc
- free
- dlopen
- dlsym
- malloc  

Function's prototype must be the same as the originals:

- `void *malloc(size_t  size);`
- `void *realloc(void *ptr , size_t  size);`
- `void  free(void *ptr)`

## Authors

* [Maxime Aubanel](https://github.com/MaximeAubanel)
* [Bastien Boyer]

## Acknowledgments

This project have been made during my studies at EPITECH Montpellier.
