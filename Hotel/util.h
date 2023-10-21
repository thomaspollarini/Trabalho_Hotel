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

data coleta_data();
int filtro_Reserva(pesquisa *busca);

void tipo_Arquivo();
void converte_Arquivos();

int len_Ope(operador *bdOpe);
int len_Hos(hospede *bdHos);
int len_Cat(categoria *bdCat);
int len_Aco(acomodacao *bdAco);
int len_Pro(produto *bdPro);
int len_For(fornecedor *bdFor);
int len_Res(reserva *bdRes);

#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

