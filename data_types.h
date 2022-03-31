#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include <Arduino.h>

/*declaring variables for unsigned data types*/
/*1 byte = 8 bits*/
typedef unsigned short int uint16;     /* short int has size 2 bytes = 16 bits*/
typedef unsigned int uint32;           /*int has size 4 bytes = 32 bits*/
typedef unsigned long long int uint64; /*long long int has 8 bytes = 64 bits*/

/*declaring variables for signed data types*/
typedef signed short int sint16;     /* short int has size 2 bytes = 16 bits*/
typedef signed int sint32;           /*int has size 4 bytes = 32 bits*/
typedef signed long long int sint64; /*long long int has 8 bytes = 64 bits*/

/*character var. for char data type*/
typedef unsigned char uint8;
typedef signed char sint8; /*char has size 1 byte = 8 bits*/

/*floating point variables*/
typedef float float32;  /*float has size 4 bytes = 32 bits*/
typedef double float64; /*double has size 8 bytes = 64 bits*/

#endif
