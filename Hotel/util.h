/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   util.h
 * Author: Alunos
 *
 * Created on 6 de setembro de 2023, 11:48
 */

#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

    
void cria_ADM(operador *novo);
void login(operador *adm);

int verifica_Acesso(operador adm,int modulo);
void menu_Acesso(operador adm, operador *novo);
void menu_Tabelas(int tipo);

data coleta_data();
int filtro_Reserva(pesquisa *busca);
int filtro_Hospedes(int *codI,int *codF,char *sexo);
int filtro_Acomodacoes(int *codI,int *codF,int *codCat,data *busca);
int filtro_ReservaRelatorio(int *codHos,int *codAco,data *busca);
int filtro_movAcomodacoes(int *codAco,int *numDia,float *valor);
int filtro_Produtos(int *codI,int *codF);
int filtro_Vendas(char *pag);
int filtro_ContasReceber(int *codI,int *codF,data *busca);
int filtro_ContasPagar(int *codI,int *codF,data *busca);
int filtro_movCaixa(data *busca);

void assoscia_Comandas(checkin *bdCIn,comanda *bdCom);
void associa_Compras(notaEntrada *bdNotas,compra *bdCom);

FILE *opcao_Arquivo(FILE *arq);
void tipo_Arquivo();
void converte_Arquivos();

int len_Ope(operador *bdOpe);
int len_Hos(hospede *bdHos);
int len_Cat(categoria *bdCat);
int len_Aco(acomodacao *bdAco);
int len_Pro(produto *bdPro);
int len_For(fornecedor *bdFor);
int len_Res(reserva *bdRes);
int len_CIn(checkin *bdCIn);
int len_Com(comanda *prod);
int len_MovC(movCaixa *bdMovC);
int len_MovA(movAcomodacao *bdMovA);
int len_Conta(movCartao *bdCRec);
int len_Ven(venda *bdVen);
int len_Notas(notaEntrada *bdNotas);
int len_Comp(compra *prod);

#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

