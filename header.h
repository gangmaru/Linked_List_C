#pragma once

struct Data {
	int tag;
	char date[50];
	char fee_paid[10];
	char name[50];
	int age;
	char organization[100];
	char job[30];
	struct Data* next;
};

struct NODE {
	int tag;
	char date[50];
	char fee_paid[10];
	char name[50];
	int age;
	char organization[100];
	char job[30];
	struct NODE* next;
};

//Linked list to store sorted data by tag#
struct second_NODE {
	int tag;
	char date[50];
	char fee_paid[10];
	char name[50];
	int age;
	char organization[100];
	char job[30];
	struct second_NODE* next;
};

void fileCheck(FILE* file);
void store(FILE* file, FILE* nfile, struct Data aa[]);

void displayList(struct NODE* head);
void enterData(struct NODE* newTag[], struct Data Tag[]);
void searchChoi(struct Data full_list[]);
void newSearchChoi(struct NODE* head);

void searchGachon(struct Data list[], char num);
void newSearchGachon(struct NODE* head);
struct NODE* newremovechoi(struct NODE** head);

void sortData_age(struct Data* aa, int n);
void viewArray(struct Data aa[], int n);
void writeSort_age(FILE* nnfile, struct Data aa[], int n);
void enter_tag_Data(struct second_NODE* newTag[], struct Data Tag[]);

void sort_tag(FILE* fp, struct Data Tag[]);
void file_sort_tag(FILE* ffp, struct Data Tag[]);
void swap(struct Data* arr, int a, int b);
void sort(struct Data* arr, int m, int n);
struct NODE* add_swap(struct NODE* ptr1, struct NODE* ptr2);
void add_sort(struct NODE** head, int count);
void add_print(struct NODE* n);
void add_insert(struct NODE** start_ref, int tag, char date[50], char fee_paid[10], char name[50], int age, char organization[100], char job[30]);
void append_paik(struct NODE* list, int tag, char date[50], char fee_paid[10], char name[50], int age, char organization[100], char job[30]);