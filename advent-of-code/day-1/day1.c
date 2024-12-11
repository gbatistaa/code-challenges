#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input;

int calculateTotalDistance(int *rightList, int *leftList, int listSize) {
  int totalDistance;
  for (int i = 0; i < listSize; i++) {
    totalDistance += abs(leftList[i] - rightList[i]);
  }
  return totalDistance;
}

// Função para mesclar dois subarrays
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Arrays temporários
  int L[n1], R[n2];

  // Copiando os dados para os arrays temporários
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Índices iniciais dos subarrays e do array principal
  int i = 0, j = 0, k = left;

  // Mesclando os subarrays
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copiando os elementos restantes de L[], se houver
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copiando os elementos restantes de R[], se houver
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int countLinesFromFile(FILE *file) {
  char currStr[20];
  int lineCount = 0;
  while (fgets(currStr, (int)sizeof(currStr) / sizeof(currStr[0]), file)) {
    lineCount++;
  }
  return lineCount;
}

int extractNumbersFromInput(FILE *file, int *leftArray, int *rightArray) {
  char line[20];
  char leftNumber[10];
  char rightNumber[10];
  int i = 0;
  int fileLineCount = countLinesFromFile(file);

  rewind(file);

  while (fgets(line, sizeof(line), file)) {

    int lineSize = strlen(line);
    bool isSecondNumber = false;
    int j = 0;
    for (int k = 0; k < lineSize; k++) {
      if (isdigit(line[k])) {
        if (!isSecondNumber) {
          leftNumber[j] = line[k];
        } else {
          rightNumber[j] = line[k];
        }
        j++;
      } else if (line[k] == ' ') {
        isSecondNumber = true;
        j = 0;
      }
    }
    leftArray[i] = atoi(leftNumber);
    rightArray[i] = atoi(rightNumber);
    i++;
  }

  return EXIT_SUCCESS;
}

int main() {
  input = fopen("input.txt", "r");
  int linesQuantity = countLinesFromFile(input);

  int leftArray[linesQuantity];
  int rightArray[linesQuantity];

  extractNumbersFromInput(input, leftArray, rightArray);

  mergeSort(leftArray, 0, sizeof(leftArray) / sizeof(leftArray[0]));
  mergeSort(rightArray, 0, sizeof(rightArray) / sizeof(rightArray[0]));
  for (int i = 0; i < linesQuantity; i++) {
    printf("%d | %d\n", leftArray[i], rightArray[i]);
  }

  int totalDistance =
      calculateTotalDistance(rightArray, leftArray, linesQuantity);

  printf("%d\n", totalDistance);

  fclose(input);
  return EXIT_SUCCESS;
}
