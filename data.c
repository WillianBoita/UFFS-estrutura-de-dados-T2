#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
  Data d1, d2;
  int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  setDate(&d1, 28, 2, 2000, diasDoMes);
  setDate(&d2, 31, 12, 1988, diasDoMes);

  //getDate(d1, 'Y');

  //showDate(d1);

  //printf("Comparar data: %d\n", dataComp(d1, d2));

  //printf("Ano bissexto: %d\n", isLeapYear(d1.ano));

  //printf("Diferença em dias: %d\n", getDiff(d1, d2));

  printf("dias do ano: %d\n", getDayFromYear(d2, diasDoMes));

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

int getDiff(Data data1, Data data2) {
  int diff = 0;
  if (data1.ano == data2.ano && data1.mes == data2.mes) {
    diff = abs(data1.dia - data2.dia);
  } else {
    
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
  printf("fevereiro: %d\n", dias[1]);

  for (int i = 0; i < data.mes; i++) {
    printf("%d mes: %d\n", i, dias[i]);
    if (i == data.mes - 1) {
      diasAcumulados += data.dia;
      printf("dia mes inicial: %d\n", data.dia);
      continue;
    }

    diasAcumulados += dias[i];
  }
  

  return diasAcumulados;
};