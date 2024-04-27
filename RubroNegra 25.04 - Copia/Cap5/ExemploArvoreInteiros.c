    #include <stdio.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

int main()
{
    pDArvore arvore = criarArvore(2);
    int respostaMenu;
    do{
        printf("1 - add\n");
        printf("2 - excluir\n");
        printf("3 - buscar\n");
        printf("4 - desenhar arvore\n");
        printf("0 - sair\n");
        scanf("%d",&respostaMenu);
        switch(respostaMenu){
        case 1:
            printf("numero: ");
            scanf("%d",&respostaMenu);
            incluirInfo(arvore, alocaInt(respostaMenu), comparaInt);
            break;
        case 2:
            printf("numero: ");
            scanf("%d",&respostaMenu);
            respostaMenu = excluirInfo(arvore, alocaInt(respostaMenu), comparaInt);
        case 3:
            break;
        case 4:
            desenhaArvore(arvore, imprimeInt);
            break;
        case 5:
            //arvore->raiz = girarEsquerda(arvore->raiz);
            break;
        }

    }
    while(respostaMenu!=0);
}


