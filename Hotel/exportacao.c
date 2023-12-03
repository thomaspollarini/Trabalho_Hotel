/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bancoDados.h"
#include "exportacao.h"

//função para criar arquivo
void exporta_Arquivos(tabela verf){
    
    char caminho[100];
    
    printf("Digite o caminho para o arquivo: "); //pede caminho
    scanf("%s",caminho);
    system("clear");
    
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        return NULL;
    }
    
    int result;
    
    result = fprintf(arq,"<dados>\n");
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
        fclose(arq);
        return;
    }
    
    if(verf.Hot==1){
        result = exporta_Hotel(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.Hos==1){
        result = exporta_Hospede(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.Aco==1){
        result = exporta_Acomodacao(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.Cat==1){
        result = exporta_Categoria(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.Pro==1){
        result = exporta_Produto(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.For==1){
        result = exporta_Fornecedor(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    if(verf.Ope==1){
        result = exporta_Operador(arq);
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
            fclose(arq);
            return;
        }
    }
    
    result = fprintf(arq,"</dados>");
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n\n");
        fclose(arq);
        return;
    }
    
    fclose(arq);
    printf("|===EXPORTAÇÃO REALIZADA COM SUCESSO===|\n\n");
    return;
}

//escreve tabela do hotel
int exporta_Hotel(FILE *arq){
    
    hotel bdHotel;
    dados_Hotel(&bdHotel);
    
    int result = fprintf(arq,"\t<tabela=hotel>\n"   //cria tabela com registro do hotel
                             "\t\t<registro>\n"
                             "\t\t\t<nome>%s</nome>\n"
                             "\t\t\t<telefone>%s</telefone>\n"
                             "\t\t\t<email>%s</email>\n"
                             "\t\t\t<nome_responsavel>%s</nome_responsavel>\n"
                             "\t\t\t<telefone_responsavel>%s</telefone_responsavel>\n"
                             "\t\t\t<endereco>%s,%d,%s,%s,%s,%s</endereco>\n"
                             "\t\t\t<hora_checkin>%d</hora_checkin>\n"
                             "\t\t\t<hora_checkout>%d</hora_checkout>\n"
                             "\t\t\t<margem>%.2f</margem>\n"
                             "\t\t\t<inscricao_estadual>%d</inscricao_estadual>\n"
                             "\t\t\t<razao_social>%s</razao_social>\n"
                             "\t\t\t<cnpj>%s</cnpj>\n"
                             "\t\t</registro>\n"
                             "\t</tabela>\n"
    ,bdHotel.nome,bdHotel.telefone,bdHotel.email,bdHotel.nomeResp,bdHotel.telefoneResp
    ,bdHotel.end.rua,bdHotel.end.num,bdHotel.end.comp,bdHotel.end.bairro,bdHotel.end.cidade,bdHotel.end.estado
    ,bdHotel.horaCheckin,bdHotel.horaCheckout,bdHotel.margem,bdHotel.inscEstadual,bdHotel.razaoSocial,bdHotel.cnpj);
    
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        return result;
    }
    
    return result;
}

//escreve tabela dos hospedes
int exporta_Hospede(FILE *arq){
    
    hospede *bdHos=dados_Hospedes(bdHos);  //abre banco de dados
    int lenHos=len_Hos(bdHos);
    
    int result = fprintf(arq,"\t<tabela=hospede>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdHos);
        return result;
    }
    
    for(int i=0; i<lenHos; i++){   //para cada hospede cadastrado cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<nome>%s</nome>\n"
                           "\t\t\t<endereco>%s,%d,%s,%s,%s,%s</endereco>\n"
                           "\t\t\t<cpf>%s</cpf>\n"
                           "\t\t\t<telefone>%s</telefone>\n"
                           "\t\t\t<email>%s</email>\n"
                           "\t\t\t<sexo>%s</sexo>\n"
                           "\t\t\t<est_civil>%s</est_civil>\n"
                           "\t\t\t<data_nascimento>%s</data_nascimento>\n"
                           "\t\t</registro>\n"
        ,bdHos[i].cod,bdHos[i].nome,bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp
        ,bdHos[i].end.bairro,bdHos[i].end.cidade,bdHos[i].end.estado,bdHos[i].cpf
        ,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdHos);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdHos);
        return result;
    }
    
    free(bdHos);
    return result;
}

//escreve tabela das acomodações
int exporta_Acomodacao(FILE *arq){
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco);  //abre banco de dados
    int lenAco=len_Aco(bdAco);
    
    int result = fprintf(arq,"\t<tabela=acomodacao>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdAco);
        return result;
    }
    
    for(int i=0; i<lenAco; i++){   //para cada acomodação cadastrada cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<descricao>%s</descricao>\n"
                           "\t\t\t<facilidade>%s</facilidade>\n"
                           "\t\t\t<categoria>%d</categoria>\n"
                           "\t\t</registro>\n"
        ,bdAco[i].cod,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdAco);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdAco);
        return result;
    }
    
    free(bdAco);
    return result;
}

//escreve tabela das categorias
int exporta_Categoria(FILE *arq){
    
    categoria *bdCat=dados_Categorias(bdCat);  //abre banco de dados
    int lenCat=len_Cat(bdCat);
    
    int result = fprintf(arq,"\t<tabela=categoria>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdCat);
        return result;
    }
    
    for(int i=0; i<lenCat; i++){   //para cada categoria cadastrada cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<descricao>%s</descricao>\n"
                           "\t\t\t<valor>%.2f</valor>\n"
                           "\t\t\t<adulto>%d</adulto>\n"
                           "\t\t\t<crianca>%d</crianca>\n"
                           "\t\t</registro>\n"
        ,bdCat[i].cod,bdCat[i].desc,bdCat[i].vlr,bdCat[i].adulto,bdCat[i].crianca);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdCat);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdCat);
        return result;
    }
    
    free(bdCat);
    return result;
}

//escreve tabela dos produtos
int exporta_Produto(FILE *arq){
    
    produto *bdPro=dados_Produtos(bdPro);  //abre banco de dados
    int lenPro=len_Pro(bdPro);
    
    int result = fprintf(arq,"\t<tabela=produto>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdPro);
        return result;
    }
    
    for(int i=0; i<lenPro; i++){   //para cada produto cadastrado cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<descricao>%s</descricao>\n"
                           "\t\t\t<venda>%.2f</venda>\n"
                           "\t\t\t<custo>%.2f</custo>\n"
                           "\t\t\t<estoque_minimo>%d</estoque_minimo>\n"
                           "\t\t\t<estoque>%d</estoque>\n"
                           "\t\t</registro>\n"
        ,bdPro[i].cod,bdPro[i].desc,bdPro[i].venda,bdPro[i].custo,bdPro[i].estmin,bdPro[i].est);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdPro);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdPro);
        return result;
    }
    
    free(bdPro);
    return result;
}

//escreve tabela dos fornecedores
int exporta_Fornecedor(FILE *arq){
    
    fornecedor *bdFor=dados_Fornecedores(bdFor);  //abre banco de dados
    int lenFor=len_For(bdFor);
    
    int result = fprintf(arq,"\t<tabela=fornecedor>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdFor);
        return result;
    }
    
    for(int i=0; i<lenFor; i++){   //para cada fornecedor cadastrado cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<nome>%s</nome>\n"
                           "\t\t\t<endereco>%s,%d,%s,%s,%s,%s</endereco>\n"
                           "\t\t\t<telefone>%s</telefone>\n"
                           "\t\t\t<email>%s</email>\n"
                           "\t\t\t<inscricao_estadual>%d</inscricao_estadual>\n"
                           "\t\t\t<razao_social>%s</razao_social>\n"
                           "\t\t\t<cnpj>%s</cnpj>\n"
                           "\t\t</registro>\n"
        ,bdFor[i].cod,bdFor[i].nome,bdFor[i].end.rua,bdFor[i].end.num,bdFor[i].end.comp
        ,bdFor[i].end.bairro,bdFor[i].end.cidade,bdFor[i].end.estado,bdFor[i].telefone
        ,bdFor[i].email,bdFor[i].inscEstadual,bdFor[i].razaoSocial,bdFor[i].cnpj);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdFor);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdFor);
        return result;
    }
    
    free(bdFor);
    return result;
}

//escreve tabela dos operadores
int exporta_Operador(FILE *arq){
    
    operador *bdOpe=dados_Operadores(bdOpe);  //abre banco de dados
    int lenOpe=len_Ope(bdOpe);
    
    int result = fprintf(arq,"\t<tabela=operador>\n");  //inicia tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdOpe);
        return result;
    }
    
    for(int i=0; i<lenOpe; i++){   //para cada operador cadastrado cria um registro
        result=fprintf(arq,"\t\t<registro>\n"
                           "\t\t\t<codigo>%d</codigo>\n"
                           "\t\t\t<nome>%s</nome>\n"
                           "\t\t\t<usuario>%s</usuario>\n"
                           "\t\t\t<senha>%s</senha>\n"
                           "\t\t\t<acesso>%d%d%d%d%d</acesso>\n"
                           "\t\t</registro>\n"
        ,bdOpe[i].cod,bdOpe[i].nome,bdOpe[i].usuario,bdOpe[i].senha,bdOpe[i].acesso[0]
        ,bdOpe[i].acesso[1],bdOpe[i].acesso[2],bdOpe[i].acesso[3],bdOpe[i].acesso[4]);
        
        if (result < 0) {
            printf("!===ERRO AO SALVAR ARQUIVO===!\n");
            free(bdOpe);
            return result;
        }
    }
    
    result = fprintf(arq,"\t</tabela>\n"); //fecha tabela
    if (result < 0) {
        printf("!===ERRO AO SALVAR ARQUIVO===!\n");
        free(bdOpe);
        return result;
    }
    
    free(bdOpe);
    return result;
}