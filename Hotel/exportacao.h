/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exportacao.h
 * Author: windows
 *
 * Created on 3 de dezembro de 2023, 12:14
 */

#ifndef EXPORTACAO_H
#define EXPORTACAO_H

#ifdef __cplusplus
extern "C" {
#endif

void exporta_Arquivos(tabela verf);
int exporta_Hotel(FILE *arq);
int exporta_Hospede(FILE *arq);
int exporta_Acomodacao(FILE *arq);
int exporta_Categoria(FILE *arq);
int exporta_Produto(FILE *arq);
int exporta_Fornecedor(FILE *arq);
int exporta_Operador(FILE *arq);

#ifdef __cplusplus
}
#endif

#endif /* EXPORTACAO_H */

