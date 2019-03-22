#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#pragma warning(disable:4996)

typedef struct DOT {
	int x;
	int y;
} Dot;
Dot dot[MAX];

int n;
int i = 0;
double sum = 0;
int tou[MAX];
int tourm[MAX];
double min = 10000;
void tour(int k, double sum);
void swap(Dot dot[], int a, int b);
double distance(Dot dot[], int a, int b);

void tour(int k, double sum) {

	if (k == n) {
		sum = sum + distance(dot, n - 1, 0);
		if (min > sum) {
			min = sum;
			for (int i = 0; i < n; i++)
				tourm[i] = tou[i];
		}
		return;
	}
	for (int i = k; i < n; i++) {
		if (k > 0) {
			if (sum > min)
				i++;
		}
		swap(dot, k, i);
		tour(k + 1, sum + distance(dot, k - 1, k));
		swap(dot, k, i);
	}
}

void swap(Dot dot[], int a, int b) {
	
	Dot temp = dot[a];
	dot[a] = dot[b];
	dot[b] = temp;
}

double distance(Dot dot[], int a, int b) {

	return sqrt((dot[a].x-dot[b].x)*(dot[a].x - dot[b].x) + (dot[a].y - dot[b].y)*(dot[a].y - dot[b].y));
}

int main() {

	FILE *fp;
	fopen_s(&fp, "input.txt", "r");
	fscanf(fp, "%d\n", &n);
	Dot dot[MAX];

	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d", &dot[i].x, &dot[i].y);
	}
	fclose(fp);
	for (int i = 0; i < n; i++) {
		tou[i] = i;
	}
	tour(1, 0);
	printf("answer:\n%lf", sum);
	printf("[");
	for (int i = 0; i < n; i++)
		printf("%d ", tourm[i]);
	printf("]");

	return 0;
}