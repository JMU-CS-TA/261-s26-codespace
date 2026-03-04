#include <stdio.h>

/* Warning: This is buggy code!! */
float sum_elements(float a[], size_t length) {
    size_t i;
    float result = 0;

    for (i = 0; i <= length-1; i++)
        result += a[i];

    return result;
}

int main()
{
	float a[4];
	printf("%f\n", sum_elements(a, 0));
	return 0;
}

