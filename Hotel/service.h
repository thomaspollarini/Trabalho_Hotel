/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   service.h
 * Author: windows
 *
 * Created on 8 de setembro de 2023, 10:39
 */

#ifndef SERVICE_H
#define SERVICE_H

void cadastrar_Operador(operador adm);
void editar_Operador(operador adm);
void excluir_Operador(operador *adm);
void ver_Operadores();

void cadastrar_Hotel();
void editar_Hotel();
void ver_Hotel();

void cadastrar_Hospede();
void editar_Hospede();
void excluir_Hospede();
void ver_Hospedes();

void cadastrar_Categoria();
void editar_Categoria();
void excluir_Categoria();
void ver_Categorias();

void cadastrar_Acomodacao();
void editar_Acomodacao();
void excluir_Acomodacao();
void ver_Acomodacoes();

void cadastrar_Produto();
void editar_Produto();
void excluir_Produto();
void ver_Produtos();

void cadastrar_Fornecedor();
void editar_Fornecedor();
void excluir_Fornecedor();
void ver_Fornecedores();

void cadastrar_Reservas();
void ver_Reservas();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* SERVICE_H */

