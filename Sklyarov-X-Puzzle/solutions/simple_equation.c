#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {	
	if (argc == 1) {
		printf("%s%s%s\n", "Usage: ", argv[0], " x");
		return 1;	
	}
	double x = strtod(argv[1], NULL);
	int X = (int)(x * 10000.0);
	int S = X >> 4;
	double s = (double)(S / 10000.0);
	printf("%lf / 16 = %lf\n", x, s);

	return 0;
}

