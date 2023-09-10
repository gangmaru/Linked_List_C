#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//Check file
void fileCheck(FILE* file) {
	if (file == NULL) {
		printf("file is not opened\n");
		exit(1);
	}
	else
		printf("file open\n");
}

//Save primary processing file
void store(FILE* file, FILE* nfile, struct Data aa[]) {
	int i = 0;
	while (fscanf(file, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &aa[i].tag, aa[i].date, aa[i].fee_paid, aa[i].name, &aa[i].age, aa[i].organization, aa[i].job) != EOF) {
		//aa[i].next = NULL;
		fprintf(nfile, "%d %s %s %s %d %s %s\n", aa[i].tag, aa[i].date, aa[i].fee_paid, aa[i].name, aa[i].age, aa[i].organization, aa[i].job);
		i++;
	}
}

//Output a linked list
void displayList(struct NODE* head) {
	struct NODE* ptr;
	ptr = head;
	while (ptr != NULL)
	{

		printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date, ptr->fee_paid,
			ptr->name, ptr->age, ptr->organization, ptr->job);

		ptr = ptr->next;
	}
}

//Linked list connection
void enterData(struct NODE* newTag[], struct Data Tag[]) {
	for (int i = 0; i < 30; i++) {
		newTag[i]->tag = Tag[i].tag;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			newTag[i]->date[j] = Tag[i].date[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 10; j++) {
			newTag[i]->fee_paid[j] = Tag[i].fee_paid[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			newTag[i]->name[j] = Tag[i].name[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		newTag[i]->age = Tag[i].age;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 100; j++) {
			newTag[i]->organization[j] = Tag[i].organization[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			newTag[i]->job[j] = Tag[i].job[j];
		}
	}
	for (int i = 0; i < 29; i++) {
		newTag[i]->next = newTag[i + 1];
	}
	newTag[29]->next = NULL;
}

//Search for "Choi" in the array
void searchChoi(struct Data full_list[]) {
	char search_text[10] = "Choi";
	//search_text[5] = 'Choi';
	for (int current = 0; current < 30; current++) {
		int pp = 0;
		for (int i = 0; i < strlen(full_list[current].name); i++) {
			if (full_list[current].name[i] == search_text[pp]) {
				pp++;
			}
			else
				pp = 0;
			if (pp == strlen(search_text)) {
				printf("%d %s %s %s %d %s %s\n", full_list[current].tag, full_list[current].date,
					full_list[current].fee_paid, full_list[current].name, full_list[current].age,
					full_list[current].organization, full_list[current].job);
			}
		}
	}
}

//Search for "Choi" in Linked List
void newSearchChoi(struct NODE* head) {
	struct NODE* ptr;
	ptr = head;
	char search_text[10] = "Choi";

	while (ptr != NULL)
	{
		int pp = 0;
		for (int i = 0; i < strlen(ptr->name); i++) {
			if (ptr->name[i] == search_text[pp]) {
				pp++;
			}
			else
				pp = 0;
			if (pp == strlen(search_text)) {
				printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date,
					ptr->fee_paid, ptr->name, ptr->age,
					ptr->organization, ptr->job);
			}
		}
		ptr = ptr->next;
	}
}

//Search for "Gachon University" in the array
void searchGachon(struct Data list[], char num) {
	char key[7] = "Gachon";
	char p = 0;
	static char array[30] = { 0, };
	for (int i = 0; i < 30; i++) {
		if (strstr(list[i].organization, key) != NULL) {
			printf("%d %s %s %s %d %s %s\n", list[i].tag, list[i].date, list[i].fee_paid, list[i].name, list[i].age, list[i].organization, list[i].job);
			array[p] = i + 1;
			p++;
		}
	}
}

//Search for "Gachon University" in Linked List
void newSearchGachon(struct NODE* head) {
	struct NODE* ptr;
	ptr = head;
	char search_text[10] = "Gachon";

	while (ptr != NULL)
	{
		int pp = 0;
		for (int i = 0; i < strlen(ptr->organization); i++) {
			if (ptr->organization[i] == search_text[pp]) {
				pp++;
			}
			else
				pp = 0;
			if (pp == strlen(search_text)) {
				printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date,
					ptr->fee_paid, ptr->name, ptr->age,
					ptr->organization, ptr->job);
			}
		}
		ptr = ptr->next;
	}
}

//Remove "Choi" in the Linked list
struct NODE* newremovechoi(struct NODE** head) {
	struct NODE* ptr, * prev_ptr;
	ptr = *head;
	prev_ptr = NULL;
	char key[7] = "Choi";
	while (ptr)
	{
		if (strstr(ptr->name, key) != NULL)
		{
			if (prev_ptr == NULL) {
				*head = ptr->next;
			}
			else {
				prev_ptr->next = ptr->next;
			}
			printf("node deleted \n");
		}
		prev_ptr = ptr;
		ptr = ptr->next;

	}
	return *head;
}

//Sort in the array in age group order-using selection sort
void sortData_age(struct Data* aa, int n) {
	int i, j;
	int min;
	struct Data temp;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (aa[min].age > aa[j].age)
				min = j;
		}
		if (min != i) {
			temp = aa[min];
			aa[min] = aa[i];
			aa[i] = temp;
		}
	}
	viewArray(aa, 30);
}

//Print all data of the array
void viewArray(struct Data aa[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %s %s %s %d %s %s\n", aa[i].tag, aa[i].date, aa[i].fee_paid, aa[i].name, aa[i].age, aa[i].organization, aa[i].job);
	}
}

//Write data sorted by age in a new text file
void writeSort_age(FILE* nnfile, struct Data aa[], int n) {
	for (int i = 0; i < n; i++) {
		fprintf(nnfile, "%d %s %s %s %d %s %s\n", aa[i].tag, aa[i].date, aa[i].fee_paid, aa[i].name, aa[i].age, aa[i].organization, aa[i].job);
	}
}

//Linked list connection
void enter_tag_Data(struct second_NODE* newTag[], struct Data Tag[]) {
	for (int i = 0; i < 30; i++) {
		newTag[i]->tag = Tag[i].tag;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			newTag[i]->date[j] = Tag[i].date[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 10; j++) {
			newTag[i]->fee_paid[j] = Tag[i].fee_paid[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			newTag[i]->name[j] = Tag[i].name[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		newTag[i]->age = Tag[i].age;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 100; j++) {
			newTag[i]->organization[j] = Tag[i].organization[j];
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			newTag[i]->job[j] = Tag[i].job[j];
		}
	}
	for (int i = 0; i < 29; i++) {
		newTag[i]->next = newTag[i + 1];
	}
	newTag[29]->next = NULL;
}

//Sort in the array in tag# order
void sort_tag(FILE* fp, struct Data Tag[]) {
	int k = 0;
	while (k < 30) {
		fscanf(fp, "%d %s %s %s %d %s %s", &Tag[k].tag, Tag[k].date, Tag[k].fee_paid, Tag[k].name, &Tag[k].age, Tag[k].organization, Tag[k].job);
		k++;
	}


	if (fp == NULL) {
		printf("No file \n");
	}

	struct Data* s = (struct Data*)malloc(sizeof(struct Data));
	int i = 0;

	sort(Tag, 0, 29);
	for (i = 0; i < 30; i++) {
		printf("%d %s %s %s %d %s %s\n", Tag[i].tag, Tag[i].date, Tag[i].fee_paid, Tag[i].name, Tag[i].age, Tag[i].organization, Tag[i].job);
	}
	free(s);
}

//Print data sorted by tag# order to a new text file
void file_sort_tag(FILE* ffp, struct Data Tag[]) {
	int k = 0;
	while (k < 30) {
		fscanf(ffp, "%d %s %s %s %d %s %s", &Tag[k].tag, Tag[k].date, Tag[k].fee_paid, Tag[k].name, &Tag[k].age, Tag[k].organization, Tag[k].job);
		k++;
	}


	if (ffp == NULL) {
		printf("No file \n");
	}

	struct Data* s = (struct Data*)malloc(sizeof(struct Data));
	int i = 0;

	sort(Tag, 0, 29);
	for (i = 0; i < 30; i++) {
		fprintf(ffp, "%d %s %s %s %d %s %s\n", Tag[i].tag, Tag[i].date, Tag[i].fee_paid, Tag[i].name, Tag[i].age, Tag[i].organization, Tag[i].job);
	}
	free(s);
}

//Swap function(sort in tag# order)
void swap(struct Data* arr, int a, int b) {
	struct Data temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

//Sort function(sort in tag# order)
void sort(struct Data* arr, int m, int n) {
	if (m < n) {
		int key = m;
		int i = m + 1;
		int j = n;

		while (i <= j) {
			while (i <= n && arr[i].tag <= arr[key].tag) {
				i++;
			}
			while (j > m && arr[j].tag >= arr[key].tag) {
				j--;
			}
			if (i > j) {
				swap(arr, j, key);
			}
			else {
				swap(arr, i, j);
			}
			sort(arr, m, j - 1);
			sort(arr, j + 1, n);
		}
	}
}

//A function that helps you reposition the add_sort function. linked list
struct NODE* add_swap(struct NODE* ptr1, struct NODE* ptr2) {
	struct NODE* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

//Function to sort in ascending order
void add_sort(struct NODE** head, int count) {
	struct NODE** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			struct NODE* p1 = *h;
			struct NODE* p2 = p1->next;

			if (p1->tag > p2->tag) {
				*h = add_swap(p1, p2);
				swapped = 1;
			}
			h = &(*h)->next;
		}

		if (swapped == 0) {
			break;
		}
	}
}

//A function that outputs ascending sorted data using the add_sort function in the main function
void add_print(struct NODE* start) {
	struct NODE* ptr;
	ptr = start;
	while (ptr != NULL) {
		printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
		ptr = ptr->next;
	}
	printf("\n");
}

//A function that creates a new node by dynamically assigning it to perform a link list
void add_insert(struct NODE** start, int tag, char date[50], char fee_paid[10], char name[50], int age, char organization[100], char job[30]) {
	struct NODE* ptr1 = (struct NODE*)malloc(sizeof(struct NODE));
	ptr1->tag = tag;
	strcpy(ptr1->date, date);
	strcpy(ptr1->fee_paid, fee_paid);
	strcpy(ptr1->name, name);
	ptr1->age = age;
	strcpy(ptr1->organization, organization);
	strcpy(ptr1->job, job);
	ptr1->next = *start;
	*start = ptr1;
}

//Append paik data to print out 31 data
void append_paik(struct NODE* start, int tag, char date[50], char fee_paid[10], char name[50], int age, char organization[100], char job[30]) {
	if (start->next == NULL) {
		struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
		newNode->tag = tag;
		strcpy(newNode->date, date);
		strcpy(newNode->fee_paid, fee_paid);
		strcpy(newNode->name, name);
		newNode->age = age;
		strcpy(newNode->organization, organization);
		strcpy(newNode->job, job);
		newNode->next = NULL;

		start->next = newNode;
	}
	else {
		struct NODE* cur = start;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
		newNode->tag = tag;
		strcpy(newNode->date, date);
		strcpy(newNode->fee_paid, fee_paid);
		strcpy(newNode->name, name);
		newNode->age = age;
		strcpy(newNode->organization, organization);
		strcpy(newNode->job, job);
		newNode->next = NULL;

		cur->next = newNode;
	}
}