/*
 * utils.h
 *
 *  Created on: Sep 28, 2015
 *      Author: Harsha Gangammanavar
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <stdbool.h>
#include <sys/stat.h>

#define 	NAMESIZE			64
#define		BLOCKSIZE			256
#define 	WORDLENGTH			8*sizeof(unsigned long)
#define 	DELTA 0.000001

#define 	INF					DBL_MAX

#define		MAXBITS				sizeof(int) * 8
#define		GE					'G'
#define		LE					'L'
#define		EQ					'E'

typedef 	char				*cString;
typedef		double				*dVector;
typedef		int					*iVector;

#define 	mem_malloc(n) 		log_alloc("malloc : " #n,malloc((n)), (n))
#define 	mem_calloc(n,size) 	log_alloc("calloc : " #n " : " #size, calloc((n),(size)), ((n) * size))
#define		arr_alloc(n,type)	(type *) mem_calloc((n),sizeof(type))
#define 	mem_realloc(ptr, n) log_realloc("realloc : " #ptr " : " #n,(ptr), realloc((ptr),(n)), (n))
#define 	mem_free(ptr) 		free(ptr)
#define 	minimum(X, Y) 		((X) <= (Y) ? (X) : (Y))
#define 	maximum(X, Y) 		((X) >= (Y) ? (X) : (Y))
#define		DBL_ABS(x)			((x) > 0.0 ? (x) : -(x))



/* following sub-routines can be found in utility.c */
void errMsg(cString type, cString place, cString item, int quit);
void *log_alloc(char *cString, void *return_ptr, int size);
void *log_realloc(char *cString, void *free_ptr, void *alloc_ptr, int size);
double str2float(char *cString);
int str2int(char *cString);
int getNumBits(int num);
double oneNorm(dVector a, int len);
double twoNorm(dVector a, dVector b, int len);
bool equalVector(dVector a, dVector b, int len, double tolerance);
dVector duplicVector(double *a, int len);
iVector duplicIntvec(iVector a, int len);
void copyVector(dVector a, dVector b, int len, bool isOneNorm);
void copyIntvec (iVector a, iVector b, int len);
void addVectors(dVector a, dVector b, iVector indices, int len);
void trPrint(cString routine, int type);
void printVector(dVector vec, int len, FILE *fptr);
void printIntvec(iVector vec, int len, FILE *fptr);
void printLine();
iVector findElems(iVector allElem, int totalElem, int *numUniq);
int isElementIntvec(iVector vec, int lenVec, int elem);
iVector iVectorIntersect(iVector a, iVector b, int lenA, int lenB);
unsigned long *encodeIntvec(iVector stream, int len, int wordLength, int maxValue);
iVector decodeIntvec(unsigned long *codeWord, int len, int wordLength, int maxValue);

#endif /* UTILS_H_ */
