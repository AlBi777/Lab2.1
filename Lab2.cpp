#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <iostream>
#include <stdio.h>
struct univer_staff
{
	char name[50];
	int salary;
	char character[200];
};

struct students {
	char name[50];
	int course;
	char character[200];
};

struct group {
	char name[50];
	struct students student[100];
	int number_of_s = 0;
};

struct direction {
	char name[100];
	struct group group[100];
	int number_of_g = 0;
};

struct univer {
	struct univer_staff rector; int rec = 0;
	struct univer_staff teacher[1000];
	int number_of_t = 0;
	struct univer_staff personal[1000];
	int number_of_p = 0;
	struct direction direction[100];
	int number_of_d = 0;

}university;

void add(){
	int choice;
	printf("Вы хотите добавить(создать):\n1)Ректор(%d)\n2)Преподователь(%d)\n3)Персонал(%d)\n4)Направление обучения(Специальность)(%d)\n5)Группа\n6)Студент\n",university.rec,university.number_of_t,university.number_of_p,university.number_of_d);
	printf("Ваш выбор:"); 
	scanf("%d", &choice);while (getchar() != '\n');
	if (choice == 1) {
		printf("ФИО:"); gets_s(university.rector.name,50);
		printf("Зарплата:"); scanf("%d", &university.rector.salary); while (getchar() != '\n');
		printf("Характеристика:"); gets_s(university.rector.character);
		university.rec = 1;
	}
}
void delet() {

}
void correct() {

}
void print(){
	int choice;
	printf("Какую информацию хотите вывести:\n1)Ректор(%d)\n2)Преподователь(%d)\n3)Персонал(%d)\n4)Направление обучения(Специальность)(%d)\n5)Группа\n6)Студент\n", university.rec, university.number_of_t, university.number_of_p, university.number_of_d);
	printf("Ваш выбор:");
	scanf("%d", &choice); while (getchar() != '\n');
	if (choice == 1 and university.rec ==1) {
		printf("ФИО:%s\nЗарплата:%d\nХарактеристика:%s\n",university.rector.name, university.rector.salary, university.rector.character);


	}
	
}




int main()
{
	while (1) {
		setlocale(LC_ALL, "RUS");
		int choice;
		printf("Выберите действие:\n1)Добавить/создать\n2)Удалить\n3)Корректировать\n4)Печать\n5)Выйти\n");
		printf("Ваш выбор:");
		scanf("%d", &choice); while (getchar() != '\n');
		if (choice == 1)add();
		if (choice == 4)print();
		if (choice == 5)exit(0);
	}

}
