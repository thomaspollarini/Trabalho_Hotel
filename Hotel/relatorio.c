/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include "bancoDados.h"
#include "util.h"
#include "serviceCadastros.h"
#include "serviceTransacoes.h"
#include "relatorio.h"



//função para gerar relatorio dos hospedes
void lista_Hospedes(){
    
    int codI,codF,i;
    char sexo[30];
    
    int status=filtro_Hospedes(&codI,&codF,sexo);  //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    hospede *bdHos= dados_Hospedes(bdHos);
    int lenHos=len_Hos(bdHos);
    
    
    hospede *relatorio;
    relatorio= calloc(1,sizeof(hospede));
    int cont=0;
            
    for(i=0;i<lenHos;i++){
        if(codI==-1 || (bdHos[i].cod>= codI && bdHos[i].cod <= codF)){  //filtra codigos
            if(strcmp(sexo,"")==0 || strcmp(sexo,bdHos[i].sexo)==0){  //filtra sexo
                cont++;
                relatorio=realloc(relatorio,cont*sizeof(hospede));      //se passar coleta dados
                relatorio[cont-1]=bdHos[i];
                
                
                printf("|Código: %d\n|Nome: %s\n|Endereço: %s, %d - %s, %s, %s-%s\n|CPF: %s\n"
                "|Telefone: %s\n|E-mail: %s\n|Gênero: %s\n|Estado Civil: %s\n|Data de nascimento: %s\n"
                "\n__________________________________\n\n"
                ,bdHos[i].cod,bdHos[i].nome,bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp,bdHos[i].end.bairro,bdHos[i].end.cidade,bdHos[i].end.estado
                ,bdHos[i].cpf,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc);
            }
        }
    }
    
    free(bdHos);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(hospede));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Hospedes(arq,relatorio);  //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de acomodações
void lista_Acomodacoes(){
    
    int codI,codF,codCat,i;
    data busca;
    
    int status=filtro_Acomodacoes(&codI,&codF,&codCat,&busca); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    int dataI,dataF,buscaI,buscaF;
    
    if(busca.dia_i!=-1){
        buscaI=busca.ano_i*10000+busca.mes_i*100+busca.dia_i; //cria data em forma de inteiro
        buscaF=busca.ano_f*10000+busca.mes_f*100+busca.dia_f;
    }
    
    acomodacao *bdAco= dados_Acomodacoes(bdAco);
    int lenAco=len_Aco(bdAco);
    
    reserva *bdRes= dados_Reservas(bdRes);
    int lenRes=len_Res(bdRes);
        
    
    acomodacao *relatorio;
    relatorio= calloc(1,sizeof(acomodacao));
    int cont=0,verf=0;
            
    for(i=0;i<lenAco;i++){
        verf=0;
        if(codI==-1 || (bdAco[i].cod>= codI && bdAco[i].cod <= codF)){ //filtro de codigos
            if(codCat==-1 || codCat==bdAco[i].cat){ //filtro de categoria
                if(busca.dia_i!=-1){
                    for(int j=0;j<lenRes;j++){              //filtro de data
                        if(bdRes[j].quarto==bdAco[i].cod){
                            dataI= bdRes[j].periodo.ano_i*10000+bdRes[j].periodo.mes_i*100+bdRes[j].periodo.dia_i;   //transforma data em inteiro para comparar maior
                            dataF= bdRes[j].periodo.ano_f*10000+bdRes[j].periodo.mes_f*100+bdRes[j].periodo.dia_f;
                
                            if((buscaI>=dataI && buscaI<dataF) || (buscaF>dataI && buscaF<=dataF)){
                                verf=1;
                                break;
                            }
                        }
                    }
                }
                
                if(verf==0){
                    cont++;     //se passar coleta dados
                    relatorio=realloc(relatorio,cont*sizeof(acomodacao));
                    relatorio[cont-1]=bdAco[i];


                    printf("|Código: %d\n|Descrição: %s\n|Facilidades: %s\n|Categoria: %d"
                    "\n__________________________________\n\n"
                    ,bdAco[i].cod,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
                }
            }
        }
    }
    
    free(bdAco);
    free(bdRes);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(acomodacao));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq);  //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Acomodacoes(arq,relatorio);   //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de Reservas
void lista_Reservas(){
    int codHos,codAco,i;
    data busca;
    
    int status=filtro_ReservaRelatorio(&codHos,&codAco,&busca);//chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    int dataI,dataF,buscaI,buscaF;
    
    if(busca.dia_i!=-1){
        buscaI=busca.ano_i*10000+busca.mes_i*100+busca.dia_i;  //refatora data
        buscaF=busca.ano_f*10000+busca.mes_f*100+busca.dia_f;
    }

    reserva *bdRes= dados_Reservas(bdRes);
    int lenRes=len_Res(bdRes);
        
    
    reserva *relatorio;
    relatorio= calloc(1,sizeof(reserva));
    int cont=0;
            
    for(i=0;i<lenRes;i++){
        if(codHos==-1 || bdRes[i].codHos == codHos ){ //filtro de hospede
            if(codAco==-1 || codAco==bdRes[i].quarto){  //filtro de acomodação
                
                dataI= bdRes[i].periodo.ano_i*10000+bdRes[i].periodo.mes_i*100+bdRes[i].periodo.dia_i;   //transforma data em inteiro para comparar maior
                dataF= bdRes[i].periodo.ano_f*10000+bdRes[i].periodo.mes_f*100+bdRes[i].periodo.dia_f;
                
                if(busca.dia_i==-1 || ((dataI>=buscaI && dataI<buscaF) || (dataF>buscaI && dataF<=buscaF))){ //filtro de data
                    
                    cont++;
                    relatorio=realloc(relatorio,cont*sizeof(reserva));  //se passar coleta datas
                    relatorio[cont-1]=bdRes[i];

                    printf("|Código: %d\n|Quarto: %d\n|Código Hóspede: %d\n|Data CheckIn: %d/%d/%d\n|Data CheckOut:  %d/%d/%d\n"
                    "\n__________________________________\n\n",bdRes[i].cod,bdRes[i].quarto,bdRes[i].codHos,bdRes[i].periodo.dia_i
                    ,bdRes[i].periodo.mes_i,bdRes[i].periodo.ano_i,bdRes[i].periodo.dia_f,bdRes[i].periodo.mes_f,bdRes[i].periodo.ano_f);
    
                }
            }
        }
    }
    
    free(bdRes);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(reserva));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Reservas(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de movimento de acomodações
void lista_movAcomodacoes(){
    int codAco,numDia,i;
    float valor;
    
    int status=filtro_movAcomodacoes(&codAco,&numDia,&valor);//chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    movAcomodacao *bdMovA= dados_movAcomodacao(bdMovA);
    int lenMovA=len_MovA(bdMovA);
    
    
    movAcomodacao *relatorio;
    relatorio= calloc(1,sizeof(movAcomodacao));
    int cont=0;
            
    for(i=0;i<lenMovA;i++){
        if(codAco==-1 || bdMovA[i].codAco==codAco){ //filtro de acomodação
            if(numDia==-1 || bdMovA[i].numDia==numDia){     //filtro de dias
                if(valor==-1 || bdMovA[i].valor==valor){        //filtro de valor
                    cont++;
                    relatorio=realloc(relatorio,cont*sizeof(movAcomodacao));
                    relatorio[cont-1]=bdMovA[i];        //se passar coleta dados
                
                
                    printf("|Código: %d\n||Código Acomodação: %d\n|Número de Diárias: %d\n|Rendimento: %.2f"
                    "\n__________________________________\n\n"
                    ,bdMovA[i].cod,bdMovA[i].codAco,bdMovA[i].numDia,bdMovA[i].valor);
                    }
            }
        }
    }
    
    free(bdMovA);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(movAcomodacao));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_movAcomodacoes(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de Produtos
void lista_Produtos(){
    
    int codI,codF,i;
    
    int status=filtro_Produtos(&codI,&codF); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    produto *bdPro= dados_Produtos(bdPro);
    int lenPro=len_Pro(bdPro);
    
    
    produto *relatorio;
    relatorio= calloc(1,sizeof(produto));
    int cont=0;
            
    for(i=0;i<lenPro;i++){
        if(codI==-1 || (bdPro[i].cod>= codI && bdPro[i].cod <= codF)) { //filtro de códigos

            cont++;
            relatorio = realloc(relatorio, cont * sizeof (produto));
            relatorio[cont - 1] = bdPro[i];


            printf("|Código: %d\n|Descrição: %s\n|Estoque mínimo: %d\n|Estoque atual: %d\n"
                    "|Preço de Custo: %.2f\n|Preço de Venda: %.2f\n__________________________________\n\n"
                    , bdPro[i].cod, bdPro[i].desc, bdPro[i].estmin, bdPro[i].est, bdPro[i].custo, bdPro[i].venda);
            
        }
    }
    
    free(bdPro);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(produto));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Produtos(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de Produtos em estoque minimo
void lista_EstoqueMin(){
    
    int codI,codF,i;
    
    int status=filtro_Produtos(&codI,&codF); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    produto *bdPro= dados_Produtos(bdPro);
    int lenPro=len_Pro(bdPro);
    
    
    produto *relatorio;
    relatorio= calloc(1,sizeof(produto));
    int cont=0;
            
    for(i=0;i<lenPro;i++){
        if((codI==-1 || (bdPro[i].cod>= codI && bdPro[i].cod <= codF)) && bdPro[i].est<=bdPro[i].estmin) { //filtro de codigos e estoque minimo
            
            cont++;
            relatorio = realloc(relatorio, cont * sizeof (produto));
            relatorio[cont - 1] = bdPro[i];


            printf("|Código: %d\n|Descrição: %s\n|Estoque mínimo: %d\n|Estoque atual: %d\n"
                    "|Preço de Custo: %.2f\n|Preço de Venda: %.2f\n__________________________________\n\n"
                    , bdPro[i].cod, bdPro[i].desc, bdPro[i].estmin, bdPro[i].est, bdPro[i].custo, bdPro[i].venda);
            
        }
    }
    
    free(bdPro);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(produto));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Produtos(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de vendas
void lista_Vendas(){
    
    int i;
    char pag[10];
    
    int status=filtro_Vendas(pag); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    venda *bdVen= dados_Vendas(bdVen);
    int lenVen=len_Ven(bdVen);
    
    venda *relatorio;
    relatorio= calloc(1,sizeof(venda));
    int cont=0;
            
    for(i=0;i<lenVen;i++){
        if(strcmp(pag,"")==0 || strcmp(pag,bdVen[i].pag)==0) { //filtro de tipo de pagamento
            
            cont++;
            relatorio = realloc(relatorio, cont * sizeof (venda)); //se passou coleta dados
            relatorio[cont - 1] = bdVen[i];


            printf("|Código: %d\n|Código Produto: %d\n|Forma de Pagamento: %s\n|Valor: %.2f"
                    "\n__________________________________\n\n"
                    , bdVen[i].cod, bdVen[i].codPro, bdVen[i].pag, bdVen[i].valor);
        }
    }
    
    free(bdVen);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(venda));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_Vendas(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de contas a receber
void lista_ContasReceber(){
    
    int codI,codF,i;
    data busca;
    
    int status=filtro_ContasReceber(&codI,&codF,&busca); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    movCartao *bdCRec= dados_ContasReceber(bdCRec);
    int lenCRec=len_Conta(bdCRec);
    
    movCartao *relatorio;
    relatorio= calloc(1,sizeof(movCartao));
    int cont=0;
            
    for(i=0;i<lenCRec;i++){
        if(codI==-1 || (bdCRec[i].codChave>= codI && bdCRec[i].codChave <= codF)) { //filtro de clientes
            if(busca.dia_f==-1 || (busca.dia_f==bdCRec[i].vencimento.dia_f &&   //filtro de data
                                   busca.mes_f==bdCRec[i].vencimento.mes_f &&
                                   busca.ano_f==bdCRec[i].vencimento.ano_f)){
                
                cont++;
                relatorio = realloc(relatorio, cont * sizeof (movCartao)); //se passou coleta dados
                relatorio[cont - 1] = bdCRec[i];

                printf("|Código: %d\n|Código Hóspede: %d\n|Parcela: %d\n|Valor: %.2f\n|Data: %d/%d/%d"
                       "\n__________________________________\n\n"
                        ,bdCRec[i].cod,bdCRec[i].codChave, bdCRec[i].parc, bdCRec[i].valor,bdCRec[i].vencimento.dia_f
                        ,bdCRec[i].vencimento.mes_f, bdCRec[i].vencimento.ano_f);
            }
        }
    }
    
    free(bdCRec);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(movCartao));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq);//cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_ContasReceber(arq,relatorio);//escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de contas a pagar
void lista_ContasPagar(){
    
    int codI,codF,i;
    data busca;
    
    int status=filtro_ContasPagar(&codI,&codF,&busca); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    int dataV,buscaI,buscaF;
    
    if(busca.dia_i!=-1){
        buscaI=busca.ano_i*10000+busca.mes_i*100+busca.dia_i;
        buscaF=busca.ano_f*10000+busca.mes_f*100+busca.dia_f;
    }
    
    movCartao *bdCPag= dados_ContasPagar(bdCPag);
    int lenCPag=len_Conta(bdCPag);
    
    movCartao *relatorio;
    relatorio= calloc(1,sizeof(movCartao));
    int cont=0;
            
    for(i=0;i<lenCPag;i++){
        if(codI==-1 || (bdCPag[i].codChave>= codI && bdCPag[i].codChave <= codF)) { //filtro de fornecedores
            
            dataV=bdCPag[i].vencimento.ano_f*10000+bdCPag[i].vencimento.mes_f*100+bdCPag[i].vencimento.dia_f;
            
            if(busca.dia_i==-1 || (dataV>=buscaI && dataV<=buscaF)){ //filtro de datas
                
                cont++;
                relatorio = realloc(relatorio, cont * sizeof (movCartao));
                relatorio[cont - 1] = bdCPag[i];

                printf("|Código: %d\n|Código Fornecedor: %d\n|Parcela: %d\n|Valor: %.2f\n|Data: %d/%d/%d"
                       "\n__________________________________\n\n"
                        ,bdCPag[i].cod,bdCPag[i].codChave, bdCPag[i].parc, bdCPag[i].valor,bdCPag[i].vencimento.dia_f
                        ,bdCPag[i].vencimento.mes_f, bdCPag[i].vencimento.ano_f);
            }
        }
    }
    
    free(bdCPag);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(movCartao));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_ContasPagar(arq,relatorio);//escreve no arquivo
        free(relatorio);
        return;
    }
}

//função para gerar relatorio de movimento de caixa
void lista_movCaixa(){
    
    data busca;
    
    int status=filtro_movCaixa(&busca); //chama filtro
    
    if(status==1){//se retorno == 1 cancela reserva
        return;
    }
    
    int dataV,buscaI,buscaF;
    
    if(busca.dia_i!=-1){
        buscaI=busca.ano_i*10000+busca.mes_i*100+busca.dia_i;
        buscaF=busca.ano_f*10000+busca.mes_f*100+busca.dia_f;
    }
    
    movCaixa *bdMovC= dados_movCaixa(bdMovC);
    int lenMovC=len_MovC(bdMovC);
    
    movCaixa *relatorio;
    relatorio= calloc(1,sizeof(movCaixa));
    int cont=0,i;
            
    for(i=0;i<lenMovC;i++) {

        dataV = bdMovC[i].dataTrans.ano_f * 10000 + bdMovC[i].dataTrans.mes_f * 100 + bdMovC[i].dataTrans.dia_f;

        if (busca.dia_i == -1 || (dataV >= buscaI && dataV <= buscaF)) { //filtro de datas

            cont++;
            relatorio = realloc(relatorio, cont * sizeof (movCaixa));
            relatorio[cont - 1] = bdMovC[i];

            printf("|Código: %d\n|Valor: %.2f\n|Tipo: %s\n|Forma de Pagamento: %s\n|Data: %d/%d/%d"
                   "\n__________________________________\n\n",bdMovC[i].cod,bdMovC[i].valor,bdMovC[i].tipo,bdMovC[i].pag,
                   bdMovC[i].dataTrans.dia_f,bdMovC[i].dataTrans.mes_f,bdMovC[i].dataTrans.ano_f);
        }
        
    }
    
    free(bdMovC);
    
    if(cont==0){
        printf("!===NENHUM ITEM ENCONTRADO===!\n\n");
        free(relatorio);
        return;
    }
    
    relatorio=realloc(relatorio,(cont+1)*sizeof(movCaixa));
    relatorio[cont].cod=-1;
    
    FILE *arq;
    
    arq=opcao_Arquivo(arq); //cria arquivo
    
    if(arq == NULL){
        free(relatorio);
        return;
    }else{
        relatorio_movCaixa(arq,relatorio); //escreve no arquivo
        free(relatorio);
        return;
    }
}
