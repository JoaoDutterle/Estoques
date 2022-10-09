#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_MAX_PROD 1000
#define CHAR_MAX 30


char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX];
int estoque[QTD_MAX_PROD];
char nome[CHAR_MAX];
int i = 0;

void mostra_menu();
int obter_opcao();
void nome_produto();
int cadastrar_produto();
void adicionar_estoque(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int estoque[QTD_MAX_PROD], int qtd);
void remover_estoque(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int estoque[QTD_MAX_PROD], int qtd);
void msg_erro();
void consultar_estoque(int qtd, char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX]);
int existeP();

int main(void) {
int opcao, qtd = 0;
  
  while(1){
    
    mostra_menu();
    opcao = obter_opcao();

    switch(opcao){
      case 1:
       qtd = cadastrar_produto(produtos_cadastrados, qtd);
      break;
      case 2:
        consultar_estoque(qtd, produtos_cadastrados);
      break;
      case 3:
        adicionar_estoque(produtos_cadastrados, estoque, qtd);
      break;
      case 4:
        remover_estoque(produtos_cadastrados, estoque, qtd);
      break;
      case 5:
        return 0;
      break;
      default:
        msg_erro();
      break;
    }  
  }

 
  return 0;
}

void mostra_menu(){
  printf("\nOpcoes:\n");
  printf("1 - Cadastrar produto\n");
  printf("2 - Consultar estoque\n");
  printf("3 - Adicionar estoque\n");
  printf("4 - Remover do estoque\n");
  printf("5 - Sair\n");
}

int obter_opcao(){
  int resposta;
  printf("Obter opcao: ");
  scanf("%d", &resposta);
  return resposta;
}

void nome_produto(char *nome){
  printf("\n...... CADASTRO DE PRODUTO ......");
  printf("\nDigite o nome do novo produto: ");
  scanf("%s", nome);
}

int cadastrar_produto(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int qtd){
  int out = 0, i = 0;
  char nome[CHAR_MAX];
  int existe, consultar, qtd_produtos = 0;
  
  while(!out){
    if(qtd == 1000){
      printf("\nLimite máximo atingido.");
      return qtd;
    }

    nome_produto(nome);
    existe = existeP(produtos_cadastrados, qtd, nome);
   //printf("%d", existe);
    if(existe != -1){
        printf("\nO produto já estava cadastrado.\n");
        continue; 
    }
    strcpy(produtos_cadastrados[i], nome);
    i++;
    qtd++;
    estoque[qtd] = 0;
    printf("Produto adicionado!\n\n");
    printf("Deseja adicionar algo a mais? 1 para sair e 0 para continuar.\n");
    scanf("%d", &out);
  }
  system("clear || cls");
  return qtd;
}

void adicionar_estoque(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int estoque[QTD_MAX_PROD], int qtd){
  char nome[CHAR_MAX];
  int unidades;
  int existe;
  int out = 0;
  while(!out){
  printf("Digite o nome do produto que voce quer adicionar: ");
  scanf("%s", nome);
  
  existe = existeP(produtos_cadastrados, qtd, nome);
  if(existe != -1){
    printf("Quantas unidades deseja adicionar? ");
    scanf("%d", &unidades);
    estoque[existe] += unidades;
    printf("Unidades adicionadas!\n\n");
    printf("Deseja adicionar algo a mais? 1 para sair e 0 para continuar.\n");
    scanf("%d", &out);
    }
  }
  system("clear || cls");
}

void msg_erro(){ 
  printf("Valor invalido. Tente novamente.\n");
}

void consultar_estoque(int qtd, char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX]){
  system("clear || cls");
  printf("\n.......... ESTOQUE ..........\n");
  for(i = 0; i < qtd; i++){
  printf("%s ----- %d\n", produtos_cadastrados[i], estoque[i]);
  }
  for(i = 0; i < 29; i++){
    printf(".");
    }
}

int existeP(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int qtd, char nome[CHAR_MAX]){

  for(int j = 0; j < qtd; j++){
    if(!strcmp(produtos_cadastrados[j], nome)){
      return j;
    }
  }
  return -1;
}

void remover_estoque(char produtos_cadastrados[QTD_MAX_PROD][CHAR_MAX], int estoque[QTD_MAX_PROD], int qtd){
  char nome[CHAR_MAX];
  int unidades, out = 0;
  int existe;
  while(!out){
  printf("\n...... REMOVER PRODUTO ......");
  printf("\nDigite o nome do produto que voce quer remover: ");
  scanf("%s", nome);
  
  existe = existeP(produtos_cadastrados, qtd, nome);
  if(existe != -1){
    printf("Quantas unidades deseja remover? ");
    scanf("%d", &unidades);
    estoque[existe] -= unidades;
    printf("Produto removido!");
    printf("\nDeseja remover algo a mais? 1 para sair e 0 para continuar.\n");
    scanf("%d", &out);
    }
  }
  system("clear || cls");
}