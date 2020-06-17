#include "Exception.h"
#include <stdio.h>
#include <malloc.h>				//memory allocation library
#include <stdarg.h>

Exception *createException(char *msg, int errorCode) {
//	Exception ex[];					//static memory allocation
	Exception *e;

	e = malloc(sizeof(Exception)); 	//dynamic memory allocation
	e->msg = msg;
	e->errorCode = errorCode;
	e->data = NULL;
	return e;

}

void freeException(Exception *e) {
	if(e->data && e->freeDataOnFreeingException) {
		free(e->data);
	}
	if(e->msg) {
		free(e->msg);
	}
	free(e);
}

void dumpException(Exception *e) {
	printf("%s (error = 0x%x)\n", e->msg, e->errorCode);
}

/*
void throwException(int errorCode, void *data, int freeDataOnFreeingException, char *message, int count, ...) {

	Exception *e = createException(message, errorCode);
	e->data = data;
	e->freeDataOnFreeingException = freeDataOnFreeingException;

	va_list ap;
	va_start(ap, count);

	for(int i = 1; i <= count; i++)
	{
//		int value = va_arg(ap, double);
//		printf("%d: %f\n", i, value);
		int value = va_arg(ap, int);
		printf("%d : %d\n", i, value);
	}
	va_end(ap);

	Throw(e);
}
*/

void throwException(int errorCode, void *data, int freeDataOnFreeingException, char *message, ...) {
	Exception *e;
	size_t len;
	char *buffer;

	va_list va;
	va_start(va, message);
	len = vsnprintf(NULL, 0, message, va);
	buffer = malloc(len + 1);
	vsprintf(buffer, message, va);
	va_end(va);

	e = createException(buffer, errorCode);
	e->data = data;
	e->freeDataOnFreeingException = freeDataOnFreeingException;


	Throw(e);
}
