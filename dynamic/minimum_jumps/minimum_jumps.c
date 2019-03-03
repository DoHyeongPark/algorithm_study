#include <stdio.h>

#define MAX 10000000

int Array[MAX];
int Jump[MAX];
int Path[MAX];

int main() {
	freopen("input.txt","r",stdin);

	int T, N, i, j;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
	
		for (i = 0; i < N; i++) {
			scanf("%d", &Array[i]);

			//init
			Jump[i] = MAX;
		}
	
		// Jump[i] = min(Jump[i], Jump[j] + 1)			
		Jump[0] = Path[0] = 0;

		for (i = 1; i < N; i++) {
			for (j = 0; j < i; j++) {
				if (Array[j] + j >= i) {
					if (Jump[i] > Jump[j] + 1) {
						Jump[i] = Jump[j] + 1;
						Path[i] = j;
          }
        }
      }
    }

    if (Jump[N-1] == MAX)
       printf("-1\n");
    else
      printf("%d\n", Jump[N-1]);
  }


	return 0;
}
