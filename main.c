#include <stdio.h>

int main()
{
	int solution[10];
	int nsol;
	int digits;
	int ndig ;
	int isvalid;
	int d, v;

    isvalid = 0;
	for (int m = 2; m < 1000000; m++) {
		nsol = 0;
		isvalid = 1;
		digits = 0;
		ndig = 0;
		for (int i = 1;isvalid && ndig < 9; i++) {
			int v = m*i;
			solution[nsol++] = v;
			while (isvalid && v) {
				ndig++;
				int d = v % 10;
                int dmask = (1 << d);
				isvalid = (d != 0 && (dmask & digits) == 0);
				v /= 10;
				digits |= dmask;
			}
		}
		if (isvalid) {
			printf("%d\n", m);
			printf("Pandigital: ");
			for(int i = 0; i < nsol; i++)
				printf("%d", solution[i]);

			printf("\n");

		}

	}




    return 0;
}
