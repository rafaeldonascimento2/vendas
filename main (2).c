// Rafael do Nascimento  838776

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

typedef struct node {
  int codigo; //campo 1
  float custo, venda, impostos, margem; //campos 2, 3, 4 e 5 respectivamente
} produto;

void limpa_dados(produto *p) {
  for (int i = 0; i < MAX; i++) {
    p[i].codigo = 0;
    p[i].custo = p[i].venda = p[i].margem = 0;
    p[i].impostos = i % 2 == 0 ? .18 : .15;}
}

float gera_custo() { //gera custos de até 3000.00
  int d1 = rand() % 3001;
  int d2 = rand() % 701;
  return (float)d1 / d2;}

float gera_margem() { //gera margem de até 25%
  int val = rand() % 26;
  return (float)val / 100.0;}

void gera_dados(produto *p) {
  for (int i = 0; i < MAX; i++) {
    p[i].codigo = i + 1000;
    p[i].margem = gera_margem();
    p[i].impostos = i % 2 == 0 ? .18 : .15;
    p[i].custo = gera_custo();
    p[i].venda =
     p[i].custo + p[i].impostos * p[i].custo + p[i].margem * p[i].custo; }
}

void imprime(produto *p) {
  printf("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  for (int i = 0; i < MAX; i++)
    printf("%d \t\t%4.2f \t\t%4.2f \t\t%.2f \t\t%.2f\n", p[i].codigo,
           p[i].custo, p[i].venda, p[i].impostos, p[i].margem);
  printf("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");
}

void ordena(produto *p, int n) {
  int i, h_v = 1;
  struct node auxi;
  if (n == 3) {
 while (h_v) {
   h_v = 0;
  for (i = 0; i < MAX - 1; i++) {
   if (p[i].venda > p[i + 1].venda) {
    auxi = p[i];
    p[i] = p[i + 1];
    p[i + 1] = auxi;
   h_v = 1; }
}

}
}
  if (n == 2) {
while (h_v) {
h_v = 0;
for (i = 0; i < MAX - 1; i++) {
if (p[i].custo < p[i + 1].custo) {
auxi = p[i];
  p[i] = p[i + 1];
 p[i + 1] = auxi;
    h_v = 1;
  }
 }

 }
}
  if (n == 1) {
while (h_v) {
h_v = 0;
for (i = 0; i < MAX - 1; i++) {
if (p[i].codigo > p[i + 1].codigo) {
auxi = p[i];
p[i] = p[i + 1];
p[i + 1] = auxi;
h_v = 1;
}
 }

}
 }
}

int busca(int codigo, produto *p, int inf, int tamanho) {
  int m, v_maximo;
  v_maximo = tamanho - 1;
  m = (inf + v_maximo) / 2;

  while (inf <= v_maximo) {
    if (p[m].codigo == codigo) {
   printf("\n*Produto foi Encontrado!!*\n");
  printf("\nProduto %d foi encontrado:\nCusto: %.2f\nVenda: %.2f\nTaxas + Imp: "
             "%.2f%%\n",
    p[m].codigo, p[m].custo, p[m].venda,
    (p[m].impostos + p[m].margem) * 100);
      return m;
    } else if (codigo > p[m].codigo)
      inf = m + 1;
    else
    v_maximo = m - 1;
    m = (inf + v_maximo) / 2; }

  if (inf > v_maximo)
   printf("\n*nao foi encontrado o produto*");
  m = -1;
  return m;}

int main() {
  srand(time(NULL));
  produto produtos[MAX];
  limpa_dados(produtos);
  gera_dados(produtos);
  imprime(produtos);
  ordena(produtos, 3);
  imprime(produtos);
  ordena(produtos, 2);
  ordena(produtos, 1);
  int b = busca(1623, produtos, 0, MAX); 
}