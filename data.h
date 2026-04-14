typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

void setDate(Data *data, int dia, int mes, int ano, int dias[12]);

int getDate(Data data, char opcao);

void showDate(Data data);

int dataComp(Data data1, Data data2);

int getDiff(Data data1, Data data2);

int isLeapYear(int data);

int getDayFromYear(Data data, int dias[12]);