#include <stdio.h>
#include <stdarg.h>

#include "cmacro.h"

#define sum(...) EXCONCAT(sum,ISEMPTY(__VA_ARGS__))(__VA_ARGS__)
#define sum1(...) sum_args(0)
#define sum0(...) sum_args(NARGS(__VA_ARGS__), __VA_ARGS__)

#define print(T) printf(#T ": %d\n", (T));

int sum_args(int nargs, ...)
{
	va_list args;
	int total;

	if (nargs == 0)
		return 0;

	va_start(args, nargs);
	
	total = 0;
	for (int i = 0; i < nargs; i++)
		total += va_arg(args, int);

	va_end(args);

	return total;
}

int main(void)
{
	print(sum());

	print(sum(0));
	print(sum(1, 2));
	print(sum(1, 2, 3));

	return 0;
}
