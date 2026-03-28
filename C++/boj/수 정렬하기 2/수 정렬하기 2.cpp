#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int original[1000001]; //원본 데이터
int tmp[1000001]; //mergesort함수에서 이용되는 배열
int natural[1000001]; //자연적으로 정렬된 배열을 인덱스대로 끊어주기 위한 배열
int tmp2[1000001]; //roate함수에서 이용되는 배열
int n;
int naturali = 1;


void rotate(int i, int j) { //역으로 정렬된 부분배열을 정렬된 배열로 바꿔주는 함수
	for (int i1 = i; i1 <= j; i1++) {
		tmp2[i1] = original[j - (i1 - i)]; //tmp2에 거꾸로 넣어놨다가
	}
	for (int i1 = i; i1 <= j; i1++) {
		original[i1] = tmp2[i1]; //original에 tmp2를 넣음
	}


}


void naturalgenerate() {  //자연적으로 정렬되있는 배열을 인덱스 별로 끊어주기 위한 함수
	int max1 = 0;

	bool sorted = true;



	for (int i = 0; i < n - 1; i++) {
		if (i == 0 && original[i] > original[i + 1]) { // 감소하는 추세임 이것을 처음 부터 정해줌
			sorted = false;
		}
		else if (i == 0 && original[i] < original[i + 1]) { //증가하는 추세임
			sorted = true;
		}
		else if (sorted == true && original[i] > original[i + 1]) { //증가하는 추세였는데 감소했을 때 
			natural[naturali++] = i + 1; //여기서 부터 끊어줌
			sorted = false; //감소하는 추세로 바뀜
		}

		else if (sorted == false && original[i] < original[i + 1]) { //감소하는 추세였는데 증가했을 때 
			rotate(natural[naturali - 1], i); // 제대로 정렬된 배열로 바꿔줌 
			natural[naturali++] = i + 1; //여기서 부터 끊어줌
			sorted = true; //증가하는 추세로 바뀜 
		}



	}
	if (sorted == false) { //마지막까지 감소하는 추세였으면 
		rotate(natural[naturali - 1], n - 1); //마지막 런을 제대로된 배열로 바꿈
	}
}
void merge(int i, int j, int i1, int j1) { //합병 정렬 알고리즘 이다
	int firsti = i;
	int secondi = i1;
	int tmpi = i;

	while (1) {
		if (firsti > j && secondi > j1)
			break;
		if (firsti <= j && secondi <= j1) { //둘다 범위 안에 있으면 
			if (original[firsti] <= original[secondi]) { //더 작은 걸 넣어준다
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
		else if (firsti <= j) { // 아직 남아있는 거를 넣어준다.
			tmp[tmpi] = original[firsti];
			tmpi++;
			firsti++;

		}
		else if (secondi <= j1) { //아직 남아 있는 것을 넣어준다 
			tmp[tmpi] = original[secondi];
			tmpi++;
			secondi++;

		}
	}
	memmove(original + i, tmp + i, sizeof(int) * (j1 - i + 1)); //original에 정렬된 tmp를 넣어준다. 


}

void naturalmergesort(int i, int j) { //자연 합병정렬 
	if (i == j) {
		return;
	}

	else {
		naturalmergesort(i, (i + j) / 2); //재귀는 합병 정렬과 비슷하다 
		naturalmergesort((i + j) / 2 + 1, j);

		if (natural[j] < natural[naturali - 1]) //합병정렬과 다르게 인덱스들은 natural에 넣어준 인자값들을 사용한다. natural에는 각 런의 첫번째 인덱스가 들어있다. 
			merge(natural[i], natural[(i + j) / 2 + 1] - 1, natural[(i + j) / 2 + 1], natural[j + 1] - 1);
		else if (natural[j] == natural[naturali - 1]) // 만약 j가 맨 끝 런이면
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
	//original배열에 새로운 값들을 넣을때마다 자연적으로 정렬된 인덱스들을 끊어준다.
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

	printf("%s 프로그램 실행시간 %.3f(초)\n", menu, res1);


}




int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &original[i]);



	naturalgenerate();
	naturalmergesort(0, naturali - 1);



	//timer(n, "입력 받은 숫자 배열");

	for (int i = 0; i < n; i++)
		printf("%d\n", original[i]);
	//menu("rand");

	//timer(n, "난수 배열");

	//menu("sortted");
	//timer(n, "정렬된 배열");


	//menu("rsortted");
	//timer(n, "거꾸로 정렬된 배열");

	//system("Pause");






}