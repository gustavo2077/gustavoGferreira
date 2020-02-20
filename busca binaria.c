#include <stdio.h>
#include <stdlib.h>

int PesquisaBinaria (int v[], int n, int x)
{
    int ini, meio, fim;
    ini = 0;
    fim = n-1;

    while(ini <= fim){
        meio = (ini + fim)/2;
        if (v[meio] == x)
        return meio;
        else if(v[meio] < x)
        ini = meio + 1;
        else
        fim = meio -1;
    }
      

}

void testar(int obtido, int esperado){
   if (obtido == esperado)
	   printf("Parabéns !!!");
   else
	   printf("Ainda não !!!");
   printf(" obtido: %d  esperado: %d\n", obtido, esperado);
}

void caso_de_teste01(){
   int v[6] = {1,2,3,4,5,6};
  int a = PesquisaBinaria(v, 6, 6);
  testar(a, 5);
}

void caso_de_teste02(){
   int v[10] = {2,3,4,5,6,7,8,9,10,12};
    int a =PesquisaBinaria(v, 10, 10);
    testar(a, 8);
}

void caso_de_teste03(){
   int v[10] = {12,15,65,66,67,68,82,90,97,98};
  int a = PesquisaBinaria(v, 10, 82);
  testar(a, 6);
}

void caso_de_teste04(){
   int v[7] = {21,25,49,50,57,60,70};
   int a = PesquisaBinaria(v, 7, 57);
   testar(a, 4);
}

void caso_de_teste05(){
   int v[6] = {1,2,3,4,14,18};
    int a =PesquisaBinaria(v, 6, 4);
    testar(a, 3);
}

void caso_de_teste06(){
   int v[10] = {1,2,2,3,4,5,7,9,11,12};
    int a =PesquisaBinaria(v, 10, 3);
    testar(a, 3);
}

void caso_de_teste07(){
   int v[10] = {2,18,27,33,34,35,36,37,38,39};
   int a = PesquisaBinaria(v, 10, 18);
   testar(a, 1);
}

void caso_de_teste08(){
   int v[10] = {1,2,3,4,5,6,7,8,9,14};
   int a = PesquisaBinaria(v, 10, 14);
   testar(a, 9);
}

void caso_de_teste09(){
   int v[10] = {32,33,34,37,39,40,44,45,46,50};
  int a = PesquisaBinaria(v, 10, 32);
  testar(a, 0);
}

void caso_de_teste10(){
   int v[10] = {1,2,3,4,5,35,40,45,46,62};
   int a =PesquisaBinaria(v, 10, 35);
   testar(a, 5);
}

int main(){
   
   caso_de_teste01(); 
   caso_de_teste02(); 
   caso_de_teste03(); 
   caso_de_teste04(); 
   caso_de_teste05(); 
   caso_de_teste06(); 
   caso_de_teste07(); 
   caso_de_teste08(); 
   caso_de_teste09(); 
   caso_de_teste10(); 
   
   //system("pause");
   return 0;
}
