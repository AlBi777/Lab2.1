#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>


struct camera
{
	int main_camera;
	int front_camera;
};

struct battery
{
	int capacity;
	char *type;
	char types[3][10] = { "Li-Ion","NIMH", "NiCd"};
};

struct memory
{
	int ram;
	int rom;
};

struct screen {
	int diagonal;
	char* type;
	char types[3][10] = {"IPS","AMOLED","OLED"};
};

struct system
{
	char *name;
	int version;
};

struct smartphone{
	struct camera camera_get;
	struct battery battery_get;
	struct memory memory_get;
	struct screen screen_get;
	struct system system_get;
};

void init(struct smartphone* s) {
	s->camera_get.main_camera = 0; 
	s->camera_get.front_camera = 0;

	s->battery_get.capacity = 0;
	s->battery_get.type = (char*)calloc(30, sizeof(char));

	s->memory_get.ram = 0;
	s->memory_get.rom = 0;

	s->screen_get.diagonal = 0;
	s->screen_get.type = (char*)calloc(30, sizeof(char));

	s->system_get.name = (char*)calloc(30, sizeof(char));
	s->system_get.version = 0;

	printf("Инициализация закончена!\n");
}

void input(struct smartphone* s) {
	printf("\nВведите данные!\n");

	printf("Камера(Мп)\nВведите разрешение главной камеры: ");
	scanf("%d",&s->camera_get.main_camera);
	printf("Введите разрешение фронтальной камеры: ");
	scanf("%d", &s->camera_get.front_camera);

	printf("Батарея(мАч)\nВведите емкость батареи: ");
	scanf("%d",&s->battery_get.capacity);
	printf("Введите тип батареи:");
	scanf("%s", s->battery_get.type);

	printf("Память(Гб)\nВведите объем памяти(rom): ");
	scanf("%d", &s->memory_get.rom);
	printf("Введите объем оперативной памяти: ");
	scanf("%d", &s->memory_get.ram);

	printf("Экран\nВведите диагональ экрана: ");
	scanf("%d", &s->screen_get.diagonal);
	printf("Введите тип экрана: ");
	scanf("%s", s->screen_get.type);

	printf("Операционая система\nВведите название операционной системы: ");
	scanf("%s", s->system_get.name);
	printf("Введите версию опер. системы: ");
	scanf("%d", &s->system_get.version);

	printf("\nДанные введены!");

}

void print(struct smartphone* s) {
	printf("\nДанные вашего телефона: \n");
	if(s->camera_get.main_camera || s->camera_get.front_camera )printf("Разрешение гл. камеры - %d Мп, фронтальной - %d Мп.\n", s->camera_get.main_camera, s->camera_get.front_camera);
	if (s->battery_get.capacity)printf("Емкость батареи - %d мАч, тип - %s.\n",s->battery_get.capacity,s->battery_get.type);
	if (s->memory_get.ram && s->memory_get.rom)printf("RAM - %d Гб,ROM - %d Гб.\n", s->memory_get.ram, s->memory_get.rom);
	if (s->screen_get.diagonal)printf("Диоганаль экрана - %d дюйм, тип - %s.\n", s->screen_get.diagonal,s->screen_get.type);
	if (s->system_get.version)printf("Опер. система - %s, версия - %d.\n",s->system_get.name, s->system_get.version);

}

void battery_status(struct smartphone* s) {
	int month;
	printf("\nПроверка емкости батареи.\n Сколько месяцев прошло с покупки: ");
	scanf("%d",&month);
	printf("Примерная емкость батареи - %d",(s->battery_get.capacity - (s->battery_get.capacity/100*month)) );
}

void check(struct smartphone* s) {
	printf("\nПроверка."); int choice;
	if (strcmp(s->battery_get.type, s->battery_get.types[0]) == 0 || strcmp(s->battery_get.type, s->battery_get.types[1]) == 0 || strcmp(s->battery_get.type, s->battery_get.types[2]) == 0) {
	}
	else {
		printf("Тип батареи не соответствует Li-Ion, NiCd, NIMH.\n Оставить(0) или изменить(1) тип: ");
		scanf("%d",&choice);
		if(choice){
			printf("Введите тип батареи:");
			scanf("%s", s->battery_get.type);
		}
	}
	if (strcmp(s->screen_get.type,s->screen_get.types[0]) == 0 || strcmp(s->screen_get.type, s->screen_get.types[1]) == 0 || strcmp(s->screen_get.type, s->screen_get.types[2]) == 0){}
	else {
		printf("Тип экрана не соответствует IPS, AMOLED, OLED.\n Оставить(0) или изменить(1) тип: ");
		scanf("%d", &choice);
		if (choice) {
			printf("Введите тип экрана:");
			scanf("%s", s->screen_get.type);
		}
	}
	printf("Проверка завершена!\n");
}


int main() {
	setlocale(LC_ALL, "ru");
	struct smartphone config;
	init(&config);
	input(&config);
	check(&config);
	print(&config);
	battery_status(&config);

}