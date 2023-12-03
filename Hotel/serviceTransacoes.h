/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   serviceTransacoes.h
 * Author: windows
 *
 * Created on 5 de novembro de 2023, 18:45
 */

#ifndef SERVICETRANSACOES_H
#define SERVICETRANSACOES_H

#ifdef __cplusplus
extern "C" {
#endif

void atualizar_Caixa(float valor,char *tipo,char *pag,data transf);

void pagar_Diarias(reserva dadosReserva,int check);
void pagar_Produtos(comanda *produtos,data pagamento, int codHos);
void pagar_Fornecedor(notaEntrada *nova,int cont,produto *bdPro,int lenPro);

void receber_Nota();


#ifdef __cplusplus
}
#endif

#endif /* SERVICETRANSACOES_H */

