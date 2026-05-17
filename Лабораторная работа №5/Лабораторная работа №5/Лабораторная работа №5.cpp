#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define MAX_SIZE 100  // Максимальный размер массива

int main() {
    int arr[MAX_SIZE];
    int j;

    system("c:\\windows\\system32\\chcp 1251");            //Выставление кодировки
    system("cls");

    printf_s("Введите количество элементов массива (не более %d): ", MAX_SIZE);
    scanf_s("%d", &j);

    // Проверка на корректный размер массива
    if (j <= 0 || j > MAX_SIZE) {
        printf_s("Некорректный размер массива. Допустимый диапазон: 1..%d\n", MAX_SIZE);
        system("pause");
        return 1;
    }

    // Ввод элементов массива
    printf_s("Введите %d целых чисел:\n", j);
    for (int i = 0; i < j; i++) {
        scanf_s("%d", &arr[i]);
    }

    // 1) Поиск максимального элемента
    int max_element = arr[0];
    for (int i = 1; i < j; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    printf_s("1) Максимальный элемент массива: %d\n", max_element);

    // 2) Сумма элементов до последнего положительного элемента
    int last_positive_index = -1;

    // Находим индекс последнего положительного элемента
    for (int i = 0; i < j; i++) {
        if (arr[i] > 0) {
            last_positive_index = i;
        }
    }

    int sum_before_last_positive = 0;
    if (last_positive_index != -1) {
        for (int i = 0; i < last_positive_index; i++) {
            sum_before_last_positive += arr[i];
        }
        printf_s("2) Сумма элементов до последнего положительного: %d\n", sum_before_last_positive);
    }
    else {
        printf_s("2) В массиве нет положительных элементов.\n");
    }

    // 3) Сжатие массива
    int a, b;
    printf_s("Введите интервал [a, b] для удаления элементов (a <= b): ");
    scanf_s("%d %d", &a, &b);

    if (a > b) {
        printf_s("Ошибка: a должно быть меньше или равно b\n");
        system("pause");
        return 1;
    }

    // Удаление элементов, модуль которых в интервале [a, b]
    int write_index = 0; // Индекс для записи сохраняемых элементов

    for (int i = 0; i < j; i++) {
        int abs_value = abs(arr[i]); // Модуль элемента

        // Если модуль НЕ в интервале [a, b], сохраняем элемент
        if (abs_value < a || abs_value > b) {
            arr[write_index] = arr[i];
            write_index++;
        }
    }

    // Заполняем освободившиеся места нулями
    for (int i = write_index; i < j; i++) {
        arr[i] = 0;
    }

    // Вывод сжатого массива
    printf_s("3) Сжатый массив:\n");
    for (int i = 0; i < j; i++) {
        printf_s("%d ", arr[i]);
    }
    printf_s("\n");

    system("pause");
    return 0;
}