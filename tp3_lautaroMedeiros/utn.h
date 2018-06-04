#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#endif // UTN_H_INCLUDED

int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);
int esDNI(char *str);
int pedirDNI(char *str, char *mensaje, char *error, int intentos);
int getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
int getValidCuit(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[],int minLength, int maxLenght,int attemps);
void clearStdin(void);
void pause(void);
void clearScreen(void);
