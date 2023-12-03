/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "bancoDados.h"
#include "serviceTransacoes.h"
#include <time.h>



//função para atualizar valor e movimento do caixa 
void atualizar_Caixa(float valor,char *tipo,char *pag,data transf){
    
    movCaixa novo;      // cria nova movimentação
                        
    novo.valor=valor;           //atribui dados
    strcpy(novo.tipo,tipo);
    strcpy(novo.pag,pag);
    
    novo.dataTrans.dia_f=transf.dia_f; //data do checkin
    novo.dataTrans.mes_f=transf.mes_f;
    novo.dataTrans.ano_f=transf.ano_f;
            
    novo.dataTrans.dia_i=NULL;
    novo.dataTrans.mes_i=NULL;
    novo.dataTrans.ano_i=NULL;
                
    cadastrar_movCaixaBD(novo); //cadastra movimentação
                
    float caixa;        
    dados_Caixa(&caixa);        // pega valor do caixa
                
    caixa+=valor; //atualiza valor
                
    atualizar_CaixaBD(caixa);  //salva
    return;
}

//função para realizar pagamento das diarias 
void pagar_Diarias(reserva dadosReserva,int check){
    
    struct tm entrada = {};  // inicializa com zeros
    entrada.tm_mday = dadosReserva.periodo.dia_i;
    entrada.tm_mon  = dadosReserva.periodo.mes_i;
    entrada.tm_year = dadosReserva.periodo.ano_i;
    
    struct tm saida = {};  // inicializa com zeros
    saida.tm_mday = dadosReserva.periodo.dia_f;
    saida.tm_mon  = dadosReserva.periodo.mes_f;
    saida.tm_year = dadosReserva.periodo.ano_f;
                                                      //verifica quantidade de dias
    int qtdDias = (difftime(mktime(&saida),mktime(&entrada))/(24 * 3600));  
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco);
    int lenAco=len_Aco(bdAco);
    
    int i,cat;
    for(i=0;i<lenAco;i++){
        if(dadosReserva.quarto==bdAco[i].cod){  //pega cod da categoria da acomodação
            cat=bdAco[i].cat;
        }
    }
    free(bdAco);
    
    categoria *bdCat=dados_Categorias(bdCat);
    int lenCat=len_Cat(bdCat);
    
    float valor;
    
    for(i=0;i<lenCat;i++){
        if(cat==bdCat[i].cod){
            valor=bdCat[i].vlr;  //pega valor da diaria da acomodação
        }
    }
    
    valor*=qtdDias;     //calcula total
    
    movAcomodacao novoA;
    novoA.codAco=dadosReserva.quarto;       //cria movimento de acomodação
    novoA.numDia=qtdDias;
    novoA.valor=valor;
    
    cadastrar_movAcomodacaoBD(novoA);       //cadastra
    
    int op;
    while(op!=0){
        printf("|Valor Total a Pagar das Diárias: R$%.2f\n\n",valor);
        printf("|Forma de Pagamento:\n|1 - Dinheiro\n|2 - Débito\n|3 - Crédito\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");    
        
        switch(op){
            
            case 1:     //para pagamentos no local
            case 2:     
                data transf;
                
                if(check==1){//pagamento no checkin
                    transf.dia_f=dadosReserva.periodo.dia_i; //data do checkin
                    transf.mes_f=dadosReserva.periodo.mes_i;
                    transf.ano_f=dadosReserva.periodo.ano_i;
                    
                }else{//pagamento no checkout
                    transf.dia_f=dadosReserva.periodo.dia_f; //data do checkout
                    transf.mes_f=dadosReserva.periodo.mes_f;
                    transf.ano_f=dadosReserva.periodo.ano_f;
                }
                
                if(op==1){
                    atualizar_Caixa(valor,"lancamento","dinheiro",transf);  //atualiza valor no caixa
                }else{
                    atualizar_Caixa(valor,"lancamento","debito",transf);
                }

                system("clear");
                printf("|===TRANSAÇÕES SALVAS===|\n\n");
                return;
                        
            break;
            
            case 3:         //para pagamentos no crédito
                movCartao novoC;
                
                novoC.parc=1;               //cria conta a receber
                novoC.valor=valor;
                printf("Digite a data de vencimento da fatura:\n");
                printf("Dia(DD): ");
                scanf("%d",&novoC.vencimento.dia_f);
                printf("Mes(MM): ");
                scanf("%d",&novoC.vencimento.mes_f);
                printf("Ano(AAAA): ");
                scanf("%d",&novoC.vencimento.ano_f);
                
                novoC.vencimento.dia_i=NULL;
                novoC.vencimento.mes_i=NULL;
                novoC.vencimento.ano_i=NULL;
                
                novoC.codChave=dadosReserva.codHos;
               
                cadastrar_ContasReceberBD(novoC);       //cadastra
                
                system("clear");
                printf("|===TRANSAÇÕES SALVAS===|\n\n");
                return;
            break;
                
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }
    
}


void pagar_Produtos(comanda *produtos,data pagamento, int codHos){
    
    int i,lenCom=len_Com(produtos);
    float valor=0;
    
    venda *bdVen=calloc(lenCom+1,sizeof(venda)); //cria vetor com tamanho de produtos comprados
    
    for(i=0;i<lenCom;i++){                  //atribui produtos
        bdVen[i].codPro=produtos[i].cod;
        bdVen[i].valor=produtos[i].valor;
        
        valor+=produtos[i].valor;
    }
    
    int op;
    while(op!=0){
        printf("|Valor Total a Pagar pelos Produtos: R$%.2f\n\n",valor);
        printf("|Forma de Pagamento:\n|1 - Dinheiro\n|2 - Débito\n|3 - Crédito\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:             //pagamentos no local
            case 2:
                data transf;
                
                transf.dia_f=pagamento.dia_f; //data do checkout
                transf.mes_f=pagamento.mes_f;
                transf.ano_f=pagamento.ano_f;
                
                
                if(op==1){
                    for(i=0;i<lenCom;i++){
                        strcpy(bdVen[i].pag,"dinheiro");
                        cadastrar_VendasBD(bdVen[i]); //cadastra venda
                    }
                    
                    atualizar_Caixa(valor,"lancamento","dinheiro",transf); //atualiza caixa
                }else{
                    for(i=0;i<lenCom;i++){
                        strcpy(bdVen[i].pag,"debito");
                        cadastrar_VendasBD(bdVen[i]);
                    }
                    
                    atualizar_Caixa(valor,"lancamento","debito",transf);
                }

                printf("|===TRANSAÇÕES SALVAS===|\n\n");
                return;
                        
            break;
                
            case 3:     //pagamento no crédito
                movCartao novoC;
                
                novoC.parc=1;
                novoC.valor=valor;
                printf("Digite a data de vencimento da fatura:\n");
                printf("Dia(DD): ");
                scanf("%d",&novoC.vencimento.dia_f);
                printf("Mes(MM): ");
                scanf("%d",&novoC.vencimento.mes_f);
                printf("Ano(AAAA): ");
                scanf("%d",&novoC.vencimento.ano_f);
                system("clear");
                
                novoC.vencimento.dia_i=NULL;
                novoC.vencimento.mes_i=NULL;
                novoC.vencimento.ano_i=NULL;
                
                novoC.codChave=codHos;
               
                for(i=0;i<lenCom;i++){
                    strcpy(bdVen[i].pag,"credito");
                    cadastrar_VendasBD(bdVen[i]);   //cadastra venda
                }
                
                cadastrar_ContasReceberBD(novoC);   //cria conta a receber

                printf("|===TRANSAÇÕES SALVAS===|\n\n");
                return;
            break;
                
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }
}

void pagar_Fornecedor(notaEntrada *nova,int cont,produto *bdPro,int lenPro){
    
    int qtdTotal=0,op,i,j;
    float fProd,iProd;
    data dtcompra;
    hotel bdHotel;
    dados_Hotel(&bdHotel);  
    
    nova->vTotal=0;
    for(i=0;i<cont;i++){            //soma valor e qtd total 
        qtdTotal+=nova->prod[i].qtd;
        nova->vTotal+=nova->prod[i].qtd*nova->prod[i].vUnid;
    }
            
    nova->vTotal+=nova->vFrete; //soma frete e imposto no valor total
    nova->vTotal+=nova->vImp;
            
    fProd=nova->vFrete/qtdTotal;        //calcula frete e imposto por produto
    iProd=nova->vImp/qtdTotal;
            
    for(i=0;i<cont;i++){
        for(j=0;j<lenPro;j++){                 //atualiza estoque, preço de venda e de custo
            if(nova->prod[i].cod==bdPro[j].cod){
                bdPro[j].est+=nova->prod[i].qtd;
                bdPro[j].custo=nova->prod[i].vUnid;
                bdPro[j].venda=nova->prod[i].vUnid+fProd+iProd;
                bdPro[j].venda+=bdPro[j].venda*(bdHotel.margem/100.0);
            }
        }
    }
    
    printf("Digite a data da compra:\n");
    printf("Dia(DD): ");
    scanf("%d",&dtcompra.dia_f);
    printf("Mes(MM): ");
    scanf("%d",&dtcompra.mes_f);
    printf("Ano(AAAA): ");
    scanf("%d",&dtcompra.ano_f);
    system("clear");
         
    op=0;
    while(op<1 || op>2){
        printf("|Valor Total: R$%.2f\n|===Pagamento===|\n|1 - A vista\n|2 - A prazo\n"
                "|Digite uma opção:",nova->vTotal);
        scanf("%d",&op);
        system("clear");
                 
        if(op<1 || op>2){
            printf("!==CARACTER INVÁLIDO==!\n\n");
        }
    }
       
    if(op==1){ //a vista
       atualizar_Caixa(nova->vTotal*(-1),"Retirada","caixa",dtcompra);  //atualiza caixa
    }else{ //a prazo
        movCartao novoC;
        float entrada,vParc;
        
        vParc=nova->vTotal;
        
        printf("Digite valor a ser pago de Entrada: "); 
        scanf("%f",&entrada);
        
        if(entrada>0){  //retira entrada
            vParc-=entrada;
            atualizar_Caixa(entrada*-1,"Retirada","caixa",dtcompra);
        }
        
        novoC.parc=0;
        while(novoC.parc<=0){
            printf("Valor Restante: %.2f\nDigite o número de parcelas: ",vParc);
            scanf("%d",&novoC.parc);    //numero de parcelas
        }

        novoC.valor=(vParc/novoC.parc)*-1; //divide o valor das parcelas, e deixa negativo
        printf("Digite a data de vencimento da fatura:\n");
        printf("Dia(DD): ");
        scanf("%d",&novoC.vencimento.dia_f);
        printf("Mes(MM): ");
        scanf("%d",&novoC.vencimento.mes_f);
        printf("Ano(AAAA): ");
        scanf("%d",&novoC.vencimento.ano_f);
        system("clear");
              
        novoC.vencimento.dia_i=NULL;
        novoC.vencimento.mes_i=NULL;
        novoC.vencimento.ano_i=NULL;
        
        novoC.codChave=nova->codFor;
        
        cadastrar_ContasPagarBD(novoC);     //cadastra nas contas a pagar

        printf("|===TRANSAÇÕES SALVAS===|\n\n");
        return;
    }
    
}

//função para dar baixa em nota de contas a receber
void receber_Nota(){
    
    movCartao *bdCRec=dados_ContasReceber(bdCRec);
    int lenCRec=len_Conta(bdCRec);
    
    if(lenCRec==0){
        printf("!===NENHUMA NOTINHA CADASTRADA===!\n\n");
        return;
    }
    
    int i,j,op=1,cod;
    
    do{
        printf("Digite o código da nota: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdCRec[i].cod!=cod && i<lenCRec){
            i++;
        }
        
        if(i==lenCRec){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===BAIXA CANCELADA===!\n\n");
                free(bdCRec);
                return;
            }
            
        }
    }while(i==lenCRec);
    
    op=1;
    while(op!=0){  //dados
        printf("|====DADOS DA NOTA====|\n|Código: %d\n|Código Hóspede: %d\n|Nº Parcelas: %d\n|Valor: %.2f\n"
                "|Data de Vencimento: %d/%d/%d\n|1 - Dar baixa na nota\n|0 - Cancelar\nDigite uma opção: "
               ,bdCRec[i].cod,bdCRec[i].codChave,bdCRec[i].parc,bdCRec[i].valor,bdCRec[i].vencimento.dia_f
               ,bdCRec[i].vencimento.mes_f,bdCRec[i].vencimento.ano_f);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
            
            atualizar_Caixa(bdCRec[i].valor,"lancamento","credito",bdCRec[i].vencimento); //atualiza caixA
        
            lenCRec--;

            if(lenCRec==0){ //se último, remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//ContasReceber.txt");
                }else{
                    result = remove(".//Bd//ContasReceber.bin");
                }
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdCRec);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdCRec);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }

            for(j=i;j<lenCRec;j++){  //move dados a esquerda
                bdCRec[j].cod=bdCRec[j+1].cod;
                bdCRec[j].codChave=bdCRec[j+1].codChave;
                bdCRec[j].parc=bdCRec[j+1].parc;
                bdCRec[j].valor=bdCRec[j+1].valor;
                bdCRec[j].vencimento.dia_f=bdCRec[j+1].vencimento.dia_f;
                bdCRec[j].vencimento.mes_f=bdCRec[j+1].vencimento.mes_f;
                bdCRec[j].vencimento.ano_f=bdCRec[j+1].vencimento.ano_f;
            }

            atualizar_ContasReceberBD(bdCRec,lenCRec); //salva no arquivo
            free(bdCRec);

            return;
        }
        
        system("clear");
        free(bdCRec);
        printf("|====BAIXA CANCELADA====|\n\n");
        return;
    }
    
}

//função para dar baixa em nota de contas a pagar
void pagar_Nota(){
    
    movCartao *bdCPag=dados_ContasPagar(bdCPag);
    int lenCPag=len_Conta(bdCPag);
    
    if(lenCPag==0){
        printf("!===NENHUMA NOTINHA CADASTRADA===!\n\n");
        return;
    }
    
    int i,j,op=1,cod;
    
    do{
        printf("Digite o código da nota: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdCPag[i].cod!=cod && i<lenCPag){
            i++;
        }
        
        if(i==lenCPag){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===BAIXA CANCELADA===!\n\n");
                free(bdCPag);
                return;
            }
            
        }
    }while(i==lenCPag);
    
    op=1;
    while(op!=0){  //dados
        printf("|====DADOS DA NOTA====|\n|Código: %d\n|Código do Fornecedor: %d\n|Nº Parcelas: %d\n|Valor: %.2f\n"
                "|Data de Vencimento: %d/%d/%d\n|1 - Dar baixa na nota\n|0 - Cancelar\nDigite uma opção: "
               ,bdCPag[i].cod,bdCPag[i].codChave,bdCPag[i].parc,bdCPag[i].valor,bdCPag[i].vencimento.dia_f
               ,bdCPag[i].vencimento.mes_f,bdCPag[i].vencimento.ano_f);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
            
            atualizar_Caixa(bdCPag[i].valor,"retirada","credito",bdCPag[i].vencimento); //ATUALIZA CAIXA
            
            bdCPag[i].parc--; //retira uma parcela
            
            if(bdCPag[i].parc==0){ //se acabaram as parcelas, remove nota
               
                lenCPag--;

                if(lenCPag==0){ //se último, remove arquivo
                    int result;
                    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo

                    if(arq!=NULL){
                        fclose(arq);
                        result = remove(".//Bd//ContasPagar.txt");
                    }else{
                        result = remove(".//Bd//ContasPagar.bin");
                    }
                    if(result!=0){
                        printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                        free(bdCPag);
                        return;
                    }else{
                        printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                        free(bdCPag);
                        inicializa_Arquivos(); //recria
                        return;
                    }
                }

                for(j=i;j<lenCPag;j++){  //move dados a esquerda
                    bdCPag[j].cod=bdCPag[j+1].cod;
                    bdCPag[j].codChave=bdCPag[j+1].codChave;
                    bdCPag[j].parc=bdCPag[j+1].parc;
                    bdCPag[j].valor=bdCPag[j+1].valor;
                    bdCPag[j].vencimento.dia_f=bdCPag[j+1].vencimento.dia_f;
                    bdCPag[j].vencimento.mes_f=bdCPag[j+1].vencimento.mes_f;
                    bdCPag[j].vencimento.ano_f=bdCPag[j+1].vencimento.ano_f;
                }

                atualizar_ContasPagarBD(bdCPag,lenCPag); //salva no arquivo
                free(bdCPag);

                return;
                
            }else{
                bdCPag[i].vencimento.mes_f++; //muda data para proximo mes  
                if(bdCPag[i].vencimento.mes_f==13){
                    bdCPag[i].vencimento.mes_f=1;
                    bdCPag[i].vencimento.ano_f++;
                }
                
                atualizar_ContasPagarBD(bdCPag,lenCPag); //salva no arquivo
                free(bdCPag);
                
                return;
            }
            
        }
        
        system("clear");
        free(bdCPag);
        printf("|====BAIXA CANCELADA====|\n\n");
        return;
    }
    
}