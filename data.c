#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
  Data d1, d2;
  int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  setDate(&d1, 28, 2, 2024, diasDoMes);
  setDate(&d2, 1, 3, 2024, diasDoMes);

  getDate(d1, 'Y');

  showDate(d1);
  showDate(d2);

  printf("Comparar data: %d\n", dataComp(d1, d2));

  printf("Ano bissexto: %d\n", isLeapYear(d1.ano));

  printf("Diferença em dias: %d\n", getDiff(d1, d2, diasDoMes));

  printf("dias do ano: %d\n", getDayFromYear(d1, diasDoMes));

  return 0;
}

void setDate(Data *data, int dia, int mes, int ano, int dias[12]) {
  int copiaDias[12];

  for (int i = 0; i < 12; i++) {
      copiaDias[i] = dias[i];
  }

  if(isLeapYear(ano)) {
    copiaDias[1] += 1;
  }

  if(!dia || (!mes || mes > 12) || !ano || dia > copiaDias[mes - 1]){
    printf("Dados inválidos\n");
    return;
  }
  
  data->ano = ano;
  data->mes = mes;
  data->dia = dia;
};

int getDate(Data data, char opcao) {
  if ((opcao == 'Y' || opcao == 'y') && data.ano) {
    printf("%d\n", data.ano);
    return data.ano;

  } else if ((opcao == 'M' || opcao == 'm') && data.mes) {
    printf("%d\n", data.mes);
    return data.mes;

  } else if ((opcao == 'D' || opcao == 'd') && data.dia) {
    printf("%d\n", data.dia);
    return data.dia;

  } else {
    printf("Input inválido.\n");
  }
  
  return 0;
};

void showDate(Data data) {
  printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
};

int dataComp(Data data1, Data data2) {
  if(data1.ano > data2.ano) {
    return 1;
  } else if(data1.ano < data2.ano) {
    return -1;
  } else if(data1.mes > data2.mes) {
    return 1;
  } else if(data1.mes < data2.mes) {
    return -1;
  } else if(data1.dia > data2.dia) {    
    return 1;
  } else if(data1.dia < data2.dia) {    
    return -1;
  } else {
    return 0;
  }
};

int getDiff(Data data1, Data data2, int dias[12]) {
  int diff = 0;
  if (data1.ano == data2.ano) {
    diff = abs(getDayFromYear(data1, dias) -  getDayFromYear(data2, dias));
  } else {
    int maiorAno;
    int menorAno;
    Data maiorData;
    Data menorData;

    if (dataComp(data1, data2) == 1) {
      maiorAno = data1.ano;
      menorAno = data2.ano;

      maiorData = data1;
      menorData = data2;
    } else if (dataComp(data1, data2) == -1) {
      maiorAno = data2.ano;
      menorAno = data1.ano;

      maiorData = data2;
      menorData = data1;
    } else {
      return 0;
    }

    diff = (isLeapYear(menorData.ano) ? 366 : 365 - getDayFromYear(menorData, dias)) + getDayFromYear(maiorData, dias);

    for (int i = menorAno + 1; i < maiorAno; i++) {
      diff += isLeapYear(i) ? 366 : 365;
    }
    
  }
  
  return diff;
};

int isLeapYear(int data) {
  if (data % 4 == 0) {
    if (data % 100 == 0) {
      if (data % 400 == 0) {
        return 1;
      }
      return 0;
    }
    return 1;
  }

  return 0;
};

int getDayFromYear(Data data, int dias[12]) {
  int diasAcumulados = 0;

  for (int i = 0; i < data.mes - 1; i++) {
    diasAcumulados += dias[i];

    if (i == 1 && isLeapYear(data.ano)) {
      diasAcumulados++;
    }
  }

    diasAcumulados += data.dia;

  return diasAcumulados;
};