#include <stdio.h>
#include "lr.h"
float recursiveSum(float numerator, float denominator, int k, int N) {
    printf("номер элемента = %d\n", k);
    if (k == N) {
        return numerator / denominator; // Условие выхода из рекурсии
    } else {
        return (numerator / denominator) + recursiveSum(numerator * (2 * k + 1), denominator * (3 * k + 1), k + 1, N);
    }
}
void quickSort(int *arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    // Разделение массива
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Рекурсия
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int lab1(){
float V, v1, v2, t;
    printf("V =");
    scanf("%f", &V);
    printf("v1 =");
    scanf("%f", &v1);
    printf("v2 =");
    scanf("%f", &v2);
    t = V / (v1 - v2);
    printf("искомое время = %f", t);
    return 0;
}

int lab12(){
float V, v1, v2;
    printf("V =");
    scanf("%f", &V);
    printf("v1 =");
    scanf("%f", &v1);
    printf("v2 =");
    scanf("%f", &v2);
    int t = (int) V / (v1 - v2);
    if (v1 > v2) {
        printf("скорость v1 больше\n");
    }
    if (v2 > v1) {
        printf("скорость v2 больше\n");
    }
    printf("искомое время = %d", t);
    return 0;
}

int lab2(){
float numerator, denominator, sum;
   int k, N;
   printf("количество элементов ряда = ");
   scanf("%d", &N);
   sum = 0;
   numerator = 1;
   denominator = 1;
   k = 1;
   while (k <= N)
   {
      numerator *= (2 * k - 1);
      denominator *= (3 * k - 2);
      sum += numerator / denominator;
      k++;
   }
   printf("сумма ряда равна %f", sum);
   return 0;
}

int lab22(){
float sum;
    int N;
    printf("количество элементов ряда = ");
    scanf("%d", &N);
    sum = recursiveSum(1.0, 1.0, 1, N);
    printf("сумма ряда равна %f\n", sum);
    return 0;
}

int lab3(){
 char c;
    int count = 0, wordHasA = 0;

    printf("Введите текст: ");
    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            count += wordHasA;
            wordHasA = 0;
        } else if (c == 'a' || c == 'A') {
                wordHasA = 1;
            }
    }
    count += wordHasA;
    printf("количество слов, cодержащих букву а: %d\n", count);
    return 0;
}

int lab32(){
char c;
int count = 0, wordHasA = 0, wordHasB = 0;

printf("Введите текст: ");
while ((c = getchar()) != '\n') {
if (c == ' ' || c == '\t') {
    if (wordHasA && !wordHasB) {
        count++;
    }
    wordHasA = 0;
    wordHasB = 0;
} else if (c == 'a' || c == 'A') {
    wordHasA = 1;
} else if (c == 'b' || c == 'B') {
    wordHasB = 1;
}
}
if (wordHasA && !wordHasB) {
    count++;
}
printf("Количество слов, содержащих букву 'а', но без буквы 'b': %d\n", count);
return 0;
}
int lab4(){
char word[1000];
    char c;
    int index = 0;
    int is_first_char = 1;
    char first_char, last_char;

    printf("Введите текст: ");
    while ((c = getchar()) != '\n' && index < 999)  {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (index > 1 && first_char != last_char) {
                word[index] = '\0';
                printf("%s ", word);
            }
            index = 0;
            is_first_char = 1;
        } else {
            if (is_first_char) {
                first_char = c;
                is_first_char = 0;
            }
            last_char = c;
            word[index++] = c;
        }
    }

    if (index > 1 && first_char != last_char) {
        word[index] = '\0';
        printf("%s", word);
    }
    return 0;
}

int lab42(){
char word[1000];
char c;
int index = 0;
int is_first_char = 1;
char first_char, last_char;

printf("Введите текст: ");
while ((c = getchar()) != '\n' && index < 998) { // Уменьшаем на 1 для безопасного добавления \n

if (c == ' ' || c == '\t' || c == '\n') {
if (index > 1) {
word[index] = '\0';
if (first_char == last_char) {
int middle = index / 2;
// Сдвигаем вторую половину слова на один символ вправо
for (int i = index; i >= middle; i--) {
word[i + 1] = word[i];
}
word[middle] = '\n';
}
printf("%s ", word);
}
index = 0;
is_first_char = 1;
} else {
if (is_first_char) {
first_char = c;
is_first_char = 0;
}
last_char = c;
word[index++] = c;
}
}

// Проверяем последнее слово после выхода из цикла
if (index > 1) {
word[index] = '\0';
if (first_char == last_char) {
int middle = index / 2;
for (int i = index; i >= middle; i--) {
word[i + 1] = word[i];
}
word[middle] = '\n';
}
printf("%s", word);
}

return 0;
}

int lab5(){
int arr[10];
    int minIndex = 0, maxIndex = 0;

    // Пользователь вводит числа массива
    printf("Введите 10 целых чисел: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Находим индексы минимального и максимального элементов
    for (int i = 1; i < 10; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    // Обнуляем элементы между минимальным и максимальным
    if (minIndex < maxIndex) {
        for (int i = minIndex + 1; i < maxIndex; i++) {
            arr[i] = 0;
        }
    } else {
        for (int i = maxIndex + 1; i < minIndex; i++) {
            arr[i] = 0;
        }
    }

    // Выводим результат
    printf("Результат: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int lab52(){
int arr[10];
    int minIndex = 0, maxIndex = 0, i;

    // Пользователь вводит числа массива
    printf("Введите 10 целых чисел: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Находим индексы минимального и максимального элементов
    for (int i = 1; i < 10; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    // Обнуляем элементы между минимальным и максимальным

    if (minIndex < maxIndex) {
        int isRegressive = 1;
        for (int i = minIndex + 2; i < maxIndex - 1; i++) {
            if (arr[i] > arr[i - 1]) {
                isRegressive = 0;
                break;
            }
        }
        if (isRegressive) {
            for(int i = 0; i < 10; i++){

            }
        } else {
            for (int i = minIndex + 1; i < maxIndex; i++) {
                arr[i] = 0;
            }
        }
    } else {
        for (int i = maxIndex + 1; i < minIndex; i++) {
            arr[i] = 0;
        }
    }

    // Выводим результат
    printf("Результат: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
int lab6(){
int rows, cols;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &rows, &cols);

    int array[rows][cols];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    //проверка каждой строки на арифметическую прогрессию
    for (int i = 0; i < rows; i++) {
        int isArithmetic = 1; //предположение, что прогрессия
        int diff = array[i][1] - array[i][0]; //разность первых двух элементов
        for (int j = 2; j < cols && isArithmetic; j++) { //начиная с третьего проверка на совпадение diff
            if (array[i][j] - array[i][j-1] != diff) {
                isArithmetic = 0;
            }
        }
        if (isArithmetic) {
            printf("Строка %d является арифметической прогрессией.\n", i + 1);
        } else {
            printf("Строка %d не является арифметической прогрессией.\n", i + 1);
        }
    }
    return 0;
}

int lab62(){
     int rows = 3;
    int cols = 3;
    int arr[3][3] = {{9, 7, 5}, {3, 2, 1}, {4, 6, 8}};

    // Сортировка двумерного массива как одномерного
    quickSort((int *)arr, 0, rows * cols - 1);

    // Вывод отсортированного массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int lab7(){
long long N, K;
    scanf("%lld %lld", &N, &K);
    char arr[100]; // Запись числа N в строку
    sprintf(arr, "%lld", N);
    int length = 0; // Длина числа N
    while (arr[length] != '\0') {
        length++;
    }
    K %= length; // Сдвиг числа N на K разрядов влево
    for (int i = 0; i < K; i++) {
        char first = arr[0];
        for (int j = 0; j < length - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[length - 1] = first;
    }
    printf("%s\n", arr); // Вывод результата
    return 0;
}
