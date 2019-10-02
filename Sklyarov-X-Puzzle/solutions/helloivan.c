#include <stdio.h>
#define x (char)
#define xx +
#define xxx ^

int main(int argc, char* argv[]){
	char p[12];
	
	p[0]=x(139 xx 113 xxx 180);
	p[1]=x(21 xx 21 xxx 79);
	p[2]=x(9 xx 6 xxx 99);
	p[3]=x(35 xx 35 xxx 42);
	p[4]=x(80 xx 19 xxx 12);
	p[5]=x(44 xx 1 xxx 1);
	p[6]=x(8 xx 7 xxx 47);
	p[7]=x(125 xx 85 xxx 155);
	p[8]=x(23 xx 73 xxx 22);
	p[9]=x(76 xx 111 xxx 218);
	p[10]=x(92 xx 7 xxx 13);	
	p[11]=x(77 xx 22 xxx 66);
		
	printf("%s\n", p);

	return 0;
}
