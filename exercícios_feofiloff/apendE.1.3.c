 #include <stdio.h>>

 struct dma {
   int dia;
   int mes;
   int ano; 
} x;
typedef struct dma data;


data fimEvento(data inicio, int duracao) {
   data fim;
   fim.dia = inicio.dia + duracao%30;
   fim.mes = inicio.mes + duracao/30;
   fim.ano = inicio.ano + duracao/365;
   return fim;
}



int main () {
   data a, b;
   scanf ("%d %d %d", &a.dia, &a.mes, &a.ano);
   int dura;
   scanf ("%d", &dura);
   b = fimEvento (a, dura);
   printf ("%d %d %d\n", b.dia, b.mes, b.ano);
   return 0;
}

