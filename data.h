typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

void setDate(Data *data, int dia, int mes, int ano);

int getDate(Data data, char opcao);

void showDate(Data data);

int dataComp(Data data1, Data data2);

int getDiff(Data data1, Data data2);

int isLeapYear(Data data);

int getDayFromYear(Data data);