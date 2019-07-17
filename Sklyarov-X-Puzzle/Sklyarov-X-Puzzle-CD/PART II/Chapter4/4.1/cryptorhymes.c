#include <stdio.h>

int main()
{
int H, A, C, K, E, R;
int E2, N, E3, R2, G, Y;
int sum=0;

for (H=1; H<=3; H++){
  for (A=0; A<=9; A++){
  if (A!=H){
    for (C=0; C<=9; C++){
    if (C!=H && C!=A){
      for (K=0; K<=9; K++){
      if (K!=H && K!=A && K!=C){
        for (E=0; E<=9; E++){
        if (E!=H && E!=A && E!=C && E!=K){
          for (R=1; R<=9; R++){
          if (R!=H && R!=A && R!=C && R!=K && R!=E){

	        sum = 3*(H*100000+A*10000+C*1000+K*100+E*10+R);
	        E2 = ((sum/100000) % 10);
	        N = ((sum/10000) % 10);
	        E3 = ((sum/1000) % 10);
	        R2 = ((sum/100) % 10);
	        G = ((sum/10) % 10);
	        Y = sum % 10;

	        if(E==E2 && E2==E3 && R==R2 && N!=H && N!=A
	           && N!=C && N!=K && N!=R && R2!=H && R2!=A 
	           && R2!=C && R2!=K && R2!=E && G!=H && G!=A 
	           && G!=C && G!=K && Y!=H && Y!=A && Y!=C 
	           && Y!=K && Y!=E && Y!=R)
			{
	          printf("HACKER=%d\n", sum/3);
	          printf("ENERGY=%d\n", sum);
	          return 0;
			}
		  }
		  }
		}
		}
	  }
	  }
	}
	}
  }
  }
}
}
