#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int num = 0;
	char c;
	int start = 0;
	int end = 0;

	fp = fopen(argv[2], "r");

	printf("-----------------------------\n");
	printf("�˴�ͳ�Ƶ�ģʽΪ��%s\n", argv[1]);
	printf("�˴�ͳ�Ƶ��ı�Ϊ��%s\n", argv[2]);

	if (fp == NULL) {
		printf("�޷���%s\n", argv[2]);
		exit(1);
	} else {
		if (argv[1][1] == 'c') {
			while (c != EOF) {
				c = fgetc(fp);
				num++;
			}
			printf("�ַ���Ϊ��%d\n", num);
		} else if (argv[1][1] == 'w') {
			while (c != EOF) {
				c = fgetc(fp);
				if (c != ' ' && c != ',' && c != '\n') {
					start = 1;
//					printf("start=%d", start);
				} else if (c == ' ' || c == ',' || c == '\n') {
					if (start == 1) {
						end = 1;
//						printf("end=%d", end);
					}
				}
				if (start == 1 && end == 1) {
					num++;
					start = 0;
					end = 0;
				}
			}
			end = 1;
			if (start == 1 && end == 1) {
				num++;
			}
			printf("������Ϊ��%d\n", num);
		} else {
			printf("�����������\n");
		}
	}

	printf("-----------------------------\n");
}