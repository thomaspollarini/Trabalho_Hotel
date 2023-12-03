/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   importacao.h
 * Author: windows
 *
 * Created on 2 de dezembro de 2023, 16:09
 */

#ifndef IMPORTACAO_H
#define IMPORTACAO_H

#ifdef __cplusplus
extern "C" {
#endif

void importa_Arquivos(tabela verf);
int importa_Hotel(FILE *arq);
int importa_Hospede(FILE *arq);
int importa_Acomodacao(FILE *arq);
int importa_Categoria(FILE *arq);
int importa_Produto(FILE *arq);
int importa_Fornecedor(FILE *arq);
int importa_Operador(FILE *arq);


#ifdef __cplusplus
}
#endif

#endif /* IMPORTACAO_H */

