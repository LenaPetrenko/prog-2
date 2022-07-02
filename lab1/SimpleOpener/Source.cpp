#include <stdio.h>

int main() {
	FILE * fptr;
	fopen_s(&fptr, "file.lena", "r+");

	if (fptr == 0) {
		return -1;
	}

	char buf[1024] = { 0 };
	fread_s(buf, 1024, sizeof(char), 1024, fptr); // функция обёртка функции Read Windows API
	printf_s("FILE CONTENTS:%s\n\n", buf);

	char buf_to_write[1024] = { "Some Test Data" };
	fseek(fptr, 0, 0); // Перемещает файловый указатель в указанное местоположение
	fwrite(buf_to_write, sizeof(char), 1024, fptr);  // функция обёртка функции Write Windows API
	fflush(fptr); // записывает на диск поток данных которые отображаются в дебаге 
	fclose(fptr); // закрываем файл

	return 0;
}