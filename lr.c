#include <stdio.h>
#include "lr.h"
float recursiveSum(float numerator, float denominator, int k, int N) {
    printf("����� �������� = %d\n", k);
    if (k == N) {
        return numerator / denominator; // ������� ������ �� ��������
    } else {
        return (numerator / denominator) + recursiveSum(numerator * (2 * k + 1), denominator * (3 * k + 1), k + 1, N);
    }
}
void quickSort(int *arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    // ���������� �������
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

    // ��������
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
    printf("������� ����� = %f", t);
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
        printf("�������� v1 ������\n");
    }
    if (v2 > v1) {
        printf("�������� v2 ������\n");
    }
    printf("������� ����� = %d", t);
    return 0;
}

int lab2(){
float numerator, denominator, sum;
   int k, N;
   printf("���������� ��������� ���� = ");
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
   printf("����� ���� ����� %f", sum);
   return 0;
}

int lab22(){
float sum;
    int N;
    printf("���������� ��������� ���� = ");
    scanf("%d", &N);
    sum = recursiveSum(1.0, 1.0, 1, N);
    printf("����� ���� ����� %f\n", sum);
    return 0;
}

int lab3(){
 char c;
    int count = 0, wordHasA = 0;

    printf("������� �����: ");
    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            count += wordHasA;
            wordHasA = 0;
        } else if (c == 'a' || c == 'A') {
                wordHasA = 1;
            }
    }
    count += wordHasA;
    printf("���������� ����, c��������� ����� �: %d\n", count);
    return 0;
}

int lab32(){
char c;
int count = 0, wordHasA = 0, wordHasB = 0;

printf("������� �����: ");
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
printf("���������� ����, ���������� ����� '�', �� ��� ����� 'b': %d\n", count);
return 0;
}
int lab4(){
char word[1000];
    char c;
    int index = 0;
    int is_first_char = 1;
    char first_char, last_char;

    printf("������� �����: ");
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

printf("������� �����: ");
while ((c = getchar()) != '\n' && index < 998) { // ��������� �� 1 ��� ����������� ���������� \n

if (c == ' ' || c == '\t' || c == '\n') {
if (index > 1) {
word[index] = '\0';
if (first_char == last_char) {
int middle = index / 2;
// �������� ������ �������� ����� �� ���� ������ ������
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

// ��������� ��������� ����� ����� ������ �� �����
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

    // ������������ ������ ����� �������
    printf("������� 10 ����� �����: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // ������� ������� ������������ � ������������� ���������
    for (int i = 1; i < 10; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    // �������� �������� ����� ����������� � ������������
    if (minIndex < maxIndex) {
        for (int i = minIndex + 1; i < maxIndex; i++) {
            arr[i] = 0;
        }
    } else {
        for (int i = maxIndex + 1; i < minIndex; i++) {
            arr[i] = 0;
        }
    }

    // ������� ���������
    printf("���������: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int lab52(){
int arr[10];
    int minIndex = 0, maxIndex = 0, i;

    // ������������ ������ ����� �������
    printf("������� 10 ����� �����: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // ������� ������� ������������ � ������������� ���������
    for (int i = 1; i < 10; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    // �������� �������� ����� ����������� � ������������

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

    // ������� ���������
    printf("���������: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
int lab6(){
int rows, cols;
    printf("������� ���������� ����� � ��������: ");
    scanf("%d %d", &rows, &cols);

    int array[rows][cols];
    printf("������� �������� �������:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    //�������� ������ ������ �� �������������� ����������
    for (int i = 0; i < rows; i++) {
        int isArithmetic = 1; //�������������, ��� ����������
        int diff = array[i][1] - array[i][0]; //�������� ������ ���� ���������
        for (int j = 2; j < cols && isArithmetic; j++) { //������� � �������� �������� �� ���������� diff
            if (array[i][j] - array[i][j-1] != diff) {
                isArithmetic = 0;
            }
        }
        if (isArithmetic) {
            printf("������ %d �������� �������������� �����������.\n", i + 1);
        } else {
            printf("������ %d �� �������� �������������� �����������.\n", i + 1);
        }
    }
    return 0;
}

int lab62(){
     int rows = 3;
    int cols = 3;
    int arr[3][3] = {{9, 7, 5}, {3, 2, 1}, {4, 6, 8}};

    // ���������� ���������� ������� ��� �����������
    quickSort((int *)arr, 0, rows * cols - 1);

    // ����� ���������������� �������
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
    char arr[100]; // ������ ����� N � ������
    sprintf(arr, "%lld", N);
    int length = 0; // ����� ����� N
    while (arr[length] != '\0') {
        length++;
    }
    K %= length; // ����� ����� N �� K �������� �����
    for (int i = 0; i < K; i++) {
        char first = arr[0];
        for (int j = 0; j < length - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[length - 1] = first;
    }
    printf("%s\n", arr); // ����� ����������
    return 0;
}
