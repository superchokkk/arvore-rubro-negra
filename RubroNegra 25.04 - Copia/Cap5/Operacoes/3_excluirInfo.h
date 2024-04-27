#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H


pNohArvore excluirTipoBinaria(pNohArvore raiz, pNohArvore aux){
    if(raiz->esquerda != NULL){
        aux = excluirTipoBinaria(raiz->esquerda, aux);
        return aux;
    }
    return raiz;
}
/*----------------------------*/
pNohArvore tentativa2 (pNohArvore raiz, FuncaoComparacao pfc, void * info){
    if(pfc(raiz->info, info)>0){
        raiz->direita = tentativa2(raiz->direita, pfc, info);
        return raiz;
    }
    if(pfc(raiz->info, info)<0){
        raiz->esquerda = tentativa2(raiz->esquerda, pfc, info);
        return raiz;
    }
    if(pfc(raiz->info, info)==0){
        if(raiz->direita == NULL && raiz->esquerda == NULL){
            if(raiz->pai->esquerda = raiz)
                raiz->pai->esquerda = NULL;
            else{
                raiz->pai->direita  = NULL;
            }

            return raiz;
        }

        if(raiz->direita == NULL && raiz->esquerda != NULL){
            if(raiz->pai->esquerda = raiz)
                raiz->pai->esquerda = raiz->esquerda;
            else
                raiz->pai->direita = raiz->esquerda;
            return raiz;
        }
        if(raiz->direita != NULL && raiz->esquerda == NULL){
            if(raiz->pai->esquerda = raiz)
                raiz->pai->esquerda = raiz->direita;
            else
                raiz->pai->direita = raiz->direita;
            return raiz;
        }

        pNohArvore aux;
        aux = excluirTipoBinaria(raiz, aux);
        raiz->info = aux->info;
        return raiz;
    }

}
/*----------------------------*/
pNohArvore girarEsquerda (pNohArvore irmao){
    pNohArvore aux;
    aux                 = irmao->pai;

    irmao->pai->direita = irmao->esquerda;
    irmao->pai->pai     = irmao;
    irmao->esquerda     = irmao->pai;

    irmao->pai          = aux->pai;

    return irmao;

}
/*----------------------------*/
pNohArvore girarDireita (pNohArvore irmao){
    pNohArvore aux;
    aux                 = irmao->pai;

    irmao->pai->esquerda = irmao->direita;
    irmao->pai->pai      = irmao;
    irmao->direita       = irmao->pai;

    irmao->pai          = aux->pai;

}
/* --------------------------*/
pNohArvore acharIrmao(pNohArvore raiz)
{
    if(raiz->pai->esquerda == raiz)
    {
        return raiz->pai->direita;
    }
    if(raiz->pai->direita == raiz)
    {
        return raiz->pai->esquerda;
    }
}

pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    //Verificar se x esta a direita ou esquerda do pai
    if(raiz==NULL)
        return NULL;
    if(pfc(raiz->info, info)==0 && raiz->pai == NULL && raiz->direita == NULL && raiz->esquerda == NULL)
    {
        free(raiz);
        return;
    }
    if(pfc(raiz->info, info)>0)
    {
        excluirInfoRecursivo(raiz->direita, info, pfc);
        return ;
    }
    if(pfc(raiz->info, info)<0)
    {
        excluirInfoRecursivo(raiz->esquerda, info, pfc);
        return ;
    }


    if(pfc(raiz->info, info)==0 && raiz->pai!=NULL){
        //caso for folha vermelha
        if(raiz->cor == RED && raiz->direita == NULL && raiz->esquerda == NULL){
            free(raiz);
            return NULL;
        }
        if(raiz->cor == RED && raiz->esquerda != NULL && raiz->direita != NULL){
            pNohArvore aux = NULL;
            aux = excluirTipoBinaria(raiz->direita, aux);
            aux->esquerda = raiz->esquerda;
            raiz = aux;
            return raiz;
        }


        //caso for preta
        //caso 1: irmao vermelho
        pNohArvore irmao;
        irmao = acharIrmao(raiz);

        if(irmao->cor == RED){
            raiz->pai->cor = RED;
            irmao->cor     = BLACK;

            if(raiz = raiz->pai->esquerda){
                raiz = girarEsquerda(irmao);
                tentativa2(raiz, pfc, info);
                return;
            }
            if(raiz = raiz->pai->direita){
                girarDireita(irmao);
            }

        }
    }

}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return;
}

#endif
