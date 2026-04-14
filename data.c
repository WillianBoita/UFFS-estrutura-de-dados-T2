#include <stdio.h>
#include "data.h"

int main() {
  Data d1, d2;

  setDate(&d1, 30, 11, 2000);
  setDate(&d2, 30, 11, 1987);

  getDate(d1, 'Y');

  showDate(d1);

  printf("%d\n", dataComp(d1, d2));

  printf("%d\n", isLeapYear(d1));

  return 0;
}

void setDate(Data *data, int dia, int mes, int ano) {
  if(!dia || !mes || !ano){
    printf("Dados inválidos\n");
    return;
  }
  
  data->ano = ano;
  data->mes = mes;
  data->dia = dia;
};

int getDate(Data data, char opcao) {
  if (opcao == 'Y' || opcao == 'y' && data.ano) {
    printf("%d\n", data.ano);
    return data.ano;

  } else if (opcao == 'M' || opcao == 'm' && data.mes) {
    printf("%d\n", data.mes);
    return data.mes;

  } else if (opcao == 'D' || opcao == 'd' && data.dia) {
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

};

int isLeapYear(Data data) {
  if (data.ano % 4 == 0) {
    if (data.ano % 100 == 0) {
      if (data.ano % 400 == 0) {
        return 1;
      }
      return 0;
    }
    return 1;
  }
};

int getDayFromYear(Data data) {

};