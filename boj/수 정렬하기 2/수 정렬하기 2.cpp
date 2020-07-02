#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int original[1000001]; //���� ������
int tmp[1000001]; //mergesort�Լ����� �̿�Ǵ� �迭
int natural[1000001]; //�ڿ������� ���ĵ� �迭�� �ε������ �����ֱ� ���� �迭
int tmp2[1000001]; //roate�Լ����� �̿�Ǵ� �迭
int n;
int naturali = 1;


void rotate(int i, int j) { //������ ���ĵ� �κй迭�� ���ĵ� �迭�� �ٲ��ִ� �Լ�
	for (int i1 = i; i1 <= j; i1++) {
		tmp2[i1] = original[j - (i1 - i)]; //tmp2�� �Ųٷ� �־���ٰ�
	}
	for (int i1 = i; i1 <= j; i1++) {
		original[i1] = tmp2[i1]; //original�� tmp2�� ����
	}


}


void naturalgenerate() {  //�ڿ������� ���ĵ��ִ� �迭�� �ε��� ���� �����ֱ� ���� �Լ�
	int max1 = 0;

	bool sorted = true;



	for (int i = 0; i < n - 1; i++) {
		if (i == 0 && original[i] > original[i + 1]) { // �����ϴ� �߼��� �̰��� ó�� ���� ������
			sorted = false;
		}
		else if (i == 0 && original[i] < original[i + 1]) { //�����ϴ� �߼���
			sorted = true;
		}
		else if (sorted == true && original[i] > original[i + 1]) { //�����ϴ� �߼����µ� �������� �� 
			natural[naturali++] = i + 1; //���⼭ ���� ������
			sorted = false; //�����ϴ� �߼��� �ٲ�
		}

		else if (sorted == false && original[i] < original[i + 1]) { //�����ϴ� �߼����µ� �������� �� 
			rotate(natural[naturali - 1], i); // ����� ���ĵ� �迭�� �ٲ��� 
			natural[naturali++] = i + 1; //���⼭ ���� ������
			sorted = true; //�����ϴ� �߼��� �ٲ� 
		}



	}
	if (sorted == false) { //���������� �����ϴ� �߼������� 
		rotate(natural[naturali - 1], n - 1); //������ ���� ����ε� �迭�� �ٲ�
	}
}
void merge(int i, int j, int i1, int j1) { //�պ� ���� �˰��� �̴�
	int firsti = i;
	int secondi = i1;
	int tmpi = i;

	while (1) {
		if (firsti > j && secondi > j1)
			break;
		if (firsti <= j && secondi <= j1) { //�Ѵ� ���� �ȿ� ������ 
			if (original[firsti] <= original[secondi]) { //�� ���� �� �־��ش�
				tmp[tmpi] = original[firsti];
				tmpi++;
				firsti++;

			}
			else {
				tmp[tmpi] = original[secondi];
				tmpi++;
				secondi++;
			}
		}
		else if (firsti <= j) { // ���� �����ִ� �Ÿ� �־��ش�.
			tmp[tmpi] = original[firsti];
			tmpi++;
			firsti++;

		}
		else if (secondi <= j1) { //���� ���� �ִ� ���� �־��ش� 
			tmp[tmpi] = original[secondi];
			tmpi++;
			secondi++;

		}
	}
	memmove(original + i, tmp + i, sizeof(int) * (j1 - i + 1)); //original�� ���ĵ� tmp�� �־��ش�. 


}

void naturalmergesort(int i, int j) { //�ڿ� �պ����� 
	if (i == j) {
		return;
	}

	else {
		naturalmergesort(i, (i + j) / 2); //��ʹ� �պ� ���İ� ����ϴ� 
		naturalmergesort((i + j) / 2 + 1, j);

		if (natural[j] < natural[naturali - 1]) //�պ����İ� �ٸ��� �ε������� natural�� �־��� ���ڰ����� ����Ѵ�. natural���� �� ���� ù��° �ε����� ����ִ�. 
			merge(natural[i], natural[(i + j) / 2 + 1] - 1, natural[(i + j) / 2 + 1], natural[j + 1] - 1);
		else if (natural[j] == natural[naturali - 1]) // ���� j�� �� �� ���̸�
			merge(natural[i], natural[(i + j) / 2 + 1] - 1, natural[(i + j) / 2 + 1], n - 1);
	}


}

void menu(char tmp[]) {
	srand(time(NULL));
	memset(natural, 0, sizeof(natural));
	naturali = 1;
	if (strcmp(tmp, "rand") == 0) {
		for (int i = 0; i < n; i++) {
			original[i] = rand();

		}

	}
	else if (strcmp(tmp, "sortted") == 0) {
		for (int i = 0; i < n; i++)
			original[i] = i + 1;
	}

	else if (strcmp(tmp, "rsortted") == 0) {
		for (int i = 0; i < n; i++) {
			original[i] = n - i;
		}
	}
	//original�迭�� ���ο� ������ ���������� �ڿ������� ���ĵ� �ε������� �����ش�.
}

void timer(int n, char menu[]) {
	double start_time;
	double end_time;
	float res1, res2;

	start_time = clock();
	naturalgenerate();
	naturalmergesort(0, naturali - 1);
	end_time = clock();

	res1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//for (int i = 0; i < n; i++)
	//	printf("%d\n", original[i]);

	printf("%s ���α׷� ����ð� %.3f(��)\n", menu, res1);


}




int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &original[i]);



	naturalgenerate();
	naturalmergesort(0, naturali - 1);



	//timer(n, "�Է� ���� ���� �迭");

	for (int i = 0; i < n; i++)
		printf("%d\n", original[i]);
	//menu("rand");

	//timer(n, "���� �迭");

	//menu("sortted");
	//timer(n, "���ĵ� �迭");


	//menu("rsortted");
	//timer(n, "�Ųٷ� ���ĵ� �迭");

	//system("Pause");






}