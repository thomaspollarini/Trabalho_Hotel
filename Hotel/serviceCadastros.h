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

#ifndef SERVICECADASTROS_H
#define SERVICECADASTROS_H

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

void cadastrar_Reserva();
void excluir_Reserva();
void remove_DadosReserva(reserva *bdRes,int lenRes, int i);
void ver_Reservas();

void cadastrar_CheckIn();
void fazer_CheckOut();
void ver_CheckIn();

void ver_Caixa();
void ver_movCaixa();
void ver_ContasReceber();
void ver_ContasPagar();

void cadastrar_Venda();
void cadastrar_Compra();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* SERVICECADASTROS_H */

