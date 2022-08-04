#include <stdio.h>

void main() {
	int max = 100, sum = 0;
	int dwarf[9];

	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarf[i]);
		sum += dwarf[i];
	}
	
	int remain = sum - 100;
	int dif, fake1=0, fake2=0;
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			dif = dwarf[i] + dwarf[j];

			if (dif == remain) {
				fake1 = i, fake2 = j;
				break;
			}
		}
	}

	int k = 0;
	int dwarf2[7];
	for (int i = 0; i < 9; i++) {
		if (i != fake1 && i != fake2) {
			dwarf2[k] = dwarf[i];
			k++;
		}
	}

	int temp;
	for (int i = 0; i < 7; i++) {
		for (int j = i+1; j < 7; j++) {
			if (dwarf2[i] > dwarf2[j]) {
				temp = dwarf2[i];
				dwarf2[i] = dwarf2[j];
				dwarf2[j] = temp;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		printf("%d\n", dwarf2[i]);
	}
	



}