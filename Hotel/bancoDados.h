/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   cadastro.h
 * Author: Alunos
 *
 * Created on 4 de setembro de 2023, 10:43
 */

#ifndef BANCODADOS_H
#define BANCODADOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

typedef struct{
    int Aco,Cat,For,Hos,Hot,Ope,Pro;
}tabela;    

typedef struct{
    int dia_i,dia_f,mes_i,mes_f,ano_i,ano_f;
}data;

typedef struct{
            int cod,crianca,adulto;
            float vlr;
            char desc[100];
            
        }categoria;
        
typedef struct{
        int cod,cat;
        char desc[100],fac[50];
    }acomodacao;
    
    
typedef struct{
    int cod,quarto,codHos;
    data periodo;
}reserva;

typedef struct{
    int num;
    char rua[50],comp[50],bairro[50],cidade[30],estado[30];
}endereco;

//struct com variáveis sobre o cadastro do hotel
typedef struct{
    int  inscEstadual,horaCheckin,horaCheckout;
    float margem;
    char nome[50],razaoSocial[30],email[50],nomeResp[50],cnpj[20],telefone[12],telefoneResp[12];
    endereco end;
}hotel;

typedef struct{
    int cod,acesso[5];
    char usuario[50],nome[50],senha[50];
}operador;

typedef struct{
    int cod,est,estmin;
    float custo,venda;
    char desc[50];
}produto;

typedef struct{
    int cod,inscEstadual;
    char nome[50],razaoSocial[30],email[50],cnpj[15],telefone[12];
    endereco end;
}fornecedor;

typedef struct{
    int cod;
    char nome[50],email[50],sexo[30],civil[30],nasc[30],cpf[20],telefone[12];
    endereco end;
}hospede;

typedef struct{
        int crianca,adulto,cat;
        char fac[50];
        data data_pes;
}pesquisa;

typedef struct{
    int cod;
    float valor;
}comanda;

typedef struct{
    int cod,reserva,pagou;
    comanda *prod;
}checkin;

typedef struct{
    int cod;
    float valor;
    char tipo[15],pag[10];
    data dataTrans;
}movCaixa;

typedef struct{
    int cod,parc,codChave;
    float valor;
    data vencimento;
}movCartao;

typedef struct{
    int cod,qtd;
    float vUnid;
}compra;

typedef struct{
    int cod,codFor;
    float vFrete,vImp,vTotal;
    compra *prod;
}notaEntrada;

typedef struct{
    int cod,codAco,numDia;
    float valor;
}movAcomodacao;

typedef struct{
    int cod,codPro;
    float valor;
    char pag[10];
}venda;

void inicializa_Arquivos();

operador *dados_Operadores(operador *bdOpe);
void cadastrar_OperadorBD(operador novo);
void atualizar_OperadorBD(operador *bdOpe,int lenOpe);

void dados_Hotel(hotel *bdHotel);
void cadastrar_HotelBD(hotel bdHotel);

hospede *dados_Hospedes(hospede *bdHos);
void cadastrar_HospedeBD(hospede novo);
void atualizar_HospedeBD(hospede *bdHos,int lenHos);

categoria *dados_Categorias(categoria *bdCat);
void cadastrar_CategoriaBD(categoria novo);
void atualizar_CategoriaBD(categoria *bdCat,int lenCat);

acomodacao *dados_Acomodacoes(acomodacao *bdAco);
void cadastrar_AcomodacaoBD(acomodacao novo);
void atualizar_AcomodacaoBD(acomodacao *bdAco,int lenAco);

produto *dados_Produtos(produto *bdPro);
void cadastrar_ProdutoBD(produto novo);
void atualizar_ProdutoBD(produto *bdPro,int lenPro);

fornecedor *dados_Fornecedores(fornecedor *bdFor);
void cadastrar_FornecedorBD(fornecedor novo);
void atualizar_FornecedorBD(fornecedor *bdFor,int lenFor);

reserva *dados_Reservas(reserva *bdRes);
void cadastrar_ReservaBD(reserva novo);
void atualizar_ReservaBD(reserva *bdRes,int lenRes);

checkin *dados_CheckIn(checkin *bdCIn);
void cadastrar_CheckInBD(checkin novo);
void atualizar_CheckInBD(checkin *bdCIn,int lenCIn);

void dados_Caixa(float *caixa);
void atualizar_CaixaBD(float caixa);

movCaixa *dados_movCaixa(movCaixa *bdMovC);
void cadastrar_movCaixaBD(movCaixa novo);
void atualizar_movCaixaBD(movCaixa *bdMovC,int lenMovC);

movAcomodacao *dados_movAcomodacao(movAcomodacao *bdMovA);
void cadastrar_movAcomodacaoBD(movAcomodacao novo);
void atualizar_movAcomodacaoBD(movAcomodacao *bdMovA,int lenMovA);

movCartao *dados_ContasReceber(movCartao *bdCRec);
void cadastrar_ContasReceberBD(movCartao novo);
void atualizar_ContasReceberBD(movCartao *bdCRec,int lenCRec);

venda *dados_Vendas(venda *bdVen);
void cadastrar_VendasBD(venda novo);
void atualizar_VendasBD(venda *bdVen,int lenVen);

movCartao *dados_ContasPagar(movCartao *bdCPag);
void cadastrar_ContasPagarBD(movCartao novo);
void atualizar_ContasPagarBD(movCartao *bdCPag,int lenCPag);

notaEntrada *dados_NotasEntrada(notaEntrada *bdNotas);
void cadastrar_NotaEntradaBD(notaEntrada novo);
void atualizar_NotasEntradaBD(notaEntrada *bdNotas,int lenNotas);

FILE *cria_ArquivoRelatorio(FILE *arq,char *nomeArq);

void relatorio_Hospedes(FILE *arq, hospede *relatorio);
void relatorio_Acomodacoes(FILE *arq, acomodacao *relatorio);
void relatorio_Reservas(FILE *arq, reserva *relatorio);
void relatorio_movAcomodacoes(FILE *arq, movAcomodacao *relatorio);
void relatorio_Produtos(FILE *arq, produto *relatorio);
void relatorio_Vendas(FILE *arq, venda *relatorio);
void relatorio_ContasReceber(FILE *arq, movCartao *relatorio);
void relatorio_ContasPagar(FILE *arq, movCartao *relatorio);
void relatorio_movCaixa(FILE *arq, movCaixa *relatorio);

#ifdef __cplusplus
}
#endif

#endif /* BANCODADOS_H */

