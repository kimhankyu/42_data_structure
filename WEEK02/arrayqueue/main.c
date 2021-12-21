#include <stdio.h>
#include <string.h>
#include <errno.h>

int func(int *p)
{
	// if (!p)
	// 	return (0);
	*p = 10;
	return (1);
}

int main(void)
{
	int a;
	int *p = &a;
	int ret;
	ret = func(NULL);
	if (ret == 0)
	{
		printf("%s\n", strerror(errno));
	}
	// printf("%s\n", strerror(errno));

	printf("%d\n", a);
	return (0);
}