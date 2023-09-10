#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void main() {
	FILE* infile, * plusfile, * newfile, * sortDatafile, * ffp;
	struct Data Tag[30];
	struct NODE* start = NULL;

	infile = fopen("registraion_data.txt", "r");
	plusfile = fopen("newData.txt", "w");
	newfile = fopen("newData.txt", "r");
	sortDatafile = fopen("sortData_Age.txt", "w");
	ffp = fopen("sortData_Tag.txt", "w");

	fileCheck(infile);
	fileCheck(newfile);
	store(infile, plusfile, Tag);
	fclose(infile);
	fclose(newfile);
	fclose(plusfile);

	//Dynamic memory allocation-original file
	struct NODE* head;
	struct NODE* newTag[30];
	for (int i = 0; i < 30; i++)
	{
		newTag[i] = (struct NODE*)malloc(sizeof(struct NODE));
	}
	head = newTag[0];

	//Move data in the array
	enterData(newTag, Tag);

	//Dynamic memory allocation-sorted tag order
	struct second_NODE* second_head;
	struct second_NODE* second_Tag[30];
	for (int i = 0; i < 30; i++) {
		second_Tag[i] = (struct second_NODE*)malloc(sizeof(struct second_NODE));
	}
	second_head = second_Tag[0];

	//Move data in the array
	enter_tag_Data(second_Tag, Tag);

	//interface
	int button, sort, search;
	char YesorNo;
	do {
		puts("===============MENU===============");
		puts("1. 추가");
		puts("2. 검색");
		puts("3. 삭제");
		puts("4. 정렬");
		puts("5. 출력");
		puts("6. 종료");
		puts("==================================");
		printf("원하는 기능을 선택하세요 : ");
		scanf("%d", &button);

		switch (button) {
		case 1: //Add Data in array and linked list
			//linked list sort
			printf("--------------------------------------\n\n");
			for (int i = 0; i < 30; i++) {
				add_insert(&start, Tag[i].tag, Tag[i].date, Tag[i].fee_paid, Tag[i].name, Tag[i].age, Tag[i].organization, Tag[i].job);
			}
			append_paik(start, 31, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "Student");
			add_print(start);
			head = start;
			break;
		case 2: //Data Retrieval
			puts("1. Choi 검색, 2. Gachon University 검색");
			scanf("%d", &search);
			if (search == 1) {
				printf("----------search for \"Choi\"----------\n");
				searchChoi(Tag);
				printf("\n");
				printf("----------Used Linked List search \"Choi\"----------\n");
				newSearchChoi(head);
				break;
			}
			else if (search == 2) {
				printf("----------search for \"Gachon University\"----------\n");
				searchGachon(Tag, 500);
				printf("\n");
				printf("\n----------Used Linked List search \"Gachon University\"----------\n");
				newSearchGachon(head);
				break;
			}
			else {
				puts("잘못된 번호를 입력했습니다. 다시 입력해주세요.");
				break;
			}
		case 3: //Deleting data in linked list
			struct NODE* ptr;
			ptr = head;
			char key[7] = "Choi";
			newremovechoi(&head);
			newremovechoi(&head);
			printf("\n");
			displayList(head);
			break;
		case 4: //Sort data
			puts("1. tag순대로 정렬, 2. 나이순대로 정렬");
			scanf("%d", &sort);
			if (sort == 1) {
				//Sort the data in tag# order
				puts("tag 순 정렬이 완료되었습니다.");
				sort_tag(newfile, Tag);
				file_sort_tag(ffp, Tag);
				fclose(ffp);
				break;
			}
			else if (sort == 2) {
				//Sort the data in age group order
				puts("나이 순 정렬이 완료되었습니다.");
				sortData_age(Tag, 30);
				writeSort_age(sortDatafile, Tag, 30);
				fclose(sortDatafile);
				break;
			}
			else {
				puts("잘못된 번호를 입력했습니다. 다시 입력해주세요.");
				break;
			}
		case 5: //Data Inquiry
			displayList(head);
			break;
		case 6: //Shutting down a Program
			puts("프로그램을 종료합니다.");
			exit(-1);
			break;
		default:
			puts("잘못된 번호를 입력했습니다. 다시 입력하세요.");
			break;
		}
		printf("계속 하시겠습니까?(Y/N) : ");
		rewind(stdin);
		scanf("%c", &YesorNo);
	} while (YesorNo == 'Y' || YesorNo == 'y');


	//Dynamic memory allocation release
	for (int i = 0; i < 30; i++)
	{
		free(newTag[i]);
	}
	for (int i = 0; i < 30; i++) {
		free(second_Tag[i]);
	}
}