/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bancoDados.h"
#include "importacao.h"

//função para converter arquivo
void importa_Arquivos(tabela verf){
    
    char caminho[100];
    
    printf("Digite o caminho para o arquivo: "); //pede caminho
    scanf("%s",caminho);
    system("clear");
    
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        return NULL;
    }
    
    int result;
    char linha[500], *token,*delimitadores = "<>=\n\t"; //separa tokens por <,>,=
        
    while(!feof(arq)){

        fgets(linha,500,arq);
        token = strtok(linha, delimitadores); //anda linhas e pega primeiro token
        
        if(strcmp(token,"/dados")==0){  //se achar /dados ent fim de arquivo
            printf("!===IMPORTAÇÃO FINALIZADA COM SUCESSO===!\n\n");
            fclose(arq);
            return;
        }
        
        if(strcmp(token,"tabela")==0){    //se achar tabela
            token = strtok(NULL, delimitadores);    //verifica labels existentes
                                            
            if(strcmp(token,"hotel")==0){    
                if(verf.Hot==1){    //verifica se foi requisitada tabela
                    result=importa_Hotel(arq); //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0 && !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"hospede")==0){
                if(verf.Hos==1){     //verifica se foi requisitada tabela
                    result=importa_Hospede(arq);    //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0 && !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"acomodacao")==0){
                if(verf.Aco==1){     //verifica se foi requisitada tabela
                    result=importa_Acomodacao(arq);     //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0 && !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"categoria")==0){
                if(verf.Cat==1){     //verifica se foi requisitada tabela
                    result=importa_Categoria(arq);  //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0 && !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"produto")==0){
                if(verf.Pro==1){     //verifica se foi requisitada tabela
                    result=importa_Produto(arq);    //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0&& !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"fornecedor")==0 ){
                if(verf.For==1){     //verifica se foi requisitada tabela
                    result=importa_Fornecedor(arq);     //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0 && !feof(arq)){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else if(strcmp(token,"operador")==0){
                if(verf.Ope==1){     //verifica se foi requisitada tabela
                    result=importa_Operador(arq);   //importa tabela
                    if(result==1){
                        fclose(arq);
                        return;
                    }
                }else{
                    while(strcmp(token,"/tabela")!=0){ //pula para fim da tabela
                        fgets(linha,500,arq);
                        token = strtok(linha, delimitadores);
                    }
                }
            }else{
                printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                fclose(arq);
                return;
            }
        }
    }
    
    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
    fclose(arq);
    return;
}

//importa dados do hotel
int importa_Hotel(FILE *arq){
    
    char linha[500], *token,*delimitadores = "<>=\n\t";
        
    hotel novo;
    
    fgets(linha,500,arq);
    token = strtok(linha, delimitadores);  //recebe <registro>
        
    while(strcmp(token,"/registro")!=0){ //até o fim do registro,
        fgets(linha,500,arq);               //pula linha e procura token de indentificação
        token = strtok(linha, delimitadores);
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            return 1;
        }

        if (strcmp(token, "nome") == 0) {     //casos de token
            token = strtok(NULL, delimitadores);
            strcpy(novo.nome, token);
        } else if (strcmp(token, "telefone") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.telefone, token);
        } else if (strcmp(token, "email") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.email, token);
        } else if (strcmp(token, "nome_responsavel") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.nomeResp, token);
        } else if (strcmp(token, "telefone_responsavel") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.telefoneResp, token);
        } else if (strcmp(token, "endereco") == 0) {
            token = strtok(NULL, ",");
            strcpy(novo.end.rua, token);
            token = strtok(NULL, ",");
            novo.end.num=atoi(token);
            token = strtok(NULL, ",");
            strcpy(novo.end.comp, token);
            token = strtok(NULL, ",");
            strcpy(novo.end.bairro, token);
            token = strtok(NULL, ",");
            strcpy(novo.end.cidade, token);
            token = strtok(NULL, ",<");
            strcpy(novo.end.estado, token);
        } else if (strcmp(token, "hora_checkin") == 0) {
            token = strtok(NULL, delimitadores);
            novo.horaCheckin = atoi(token);
        } else if (strcmp(token, "hora_checkout") == 0) {
            token = strtok(NULL, delimitadores);
            novo.horaCheckout = atoi(token);
        } else if (strcmp(token, "margem") == 0) {
            token = strtok(NULL, delimitadores);
            novo.margem = atof(token);
        } else if (strcmp(token, "inscricao_estadual") == 0) {
            token = strtok(NULL, delimitadores);
            novo.inscEstadual = atoi(token);
        } else if (strcmp(token, "razao_social") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.razaoSocial,token);
        } else if (strcmp(token, "cnpj") == 0) {
            token = strtok(NULL, delimitadores);
            strcpy(novo.cnpj,token);
        }
    }
    
    cadastrar_HotelBD(novo); //muda dados
    
    return 0;
}

//importa dados do hospede
int importa_Hospede(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    hospede *dados;
    
    dados=calloc(1,sizeof(hospede)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){ //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){ //verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(hospede));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "nome") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].nome, token);
                } else if (strcmp(token, "telefone") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].telefone, token);
                } else if (strcmp(token, "email") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].email, token);
                } else if (strcmp(token, "cpf") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].cpf, token);
                } else if (strcmp(token, "sexo") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].sexo, token);
                } else if (strcmp(token, "endereco") == 0) {
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.rua, token);
                    token = strtok(NULL, ",");
                    dados[i-1].end.num=atoi(token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.comp, token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.bairro, token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.cidade, token);
                    token = strtok(NULL, ",<");
                    strcpy(dados[i-1].end.estado, token);
                } else if (strcmp(token, "est_civil") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].civil, token);
                } else if (strcmp(token, "data_nascimento") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].nasc, token);
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(hospede));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_Hos(dados);
    
    atualizar_HospedeBD(dados,lenDados); //muda dados
    free(dados);
    return 0;
}

//importa dados da acomodacao
int importa_Acomodacao(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    acomodacao *dados;
    
    dados=calloc(1,sizeof(acomodacao)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){ //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){ //verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(acomodacao));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "descricao") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].desc, token);
                } else if (strcmp(token, "facilidade") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].fac, token);
                } else if (strcmp(token, "categoria") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cat = atoi(token);
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(acomodacao));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_Aco(dados);
    
    atualizar_AcomodacaoBD(dados,lenDados);//muda dados
    free(dados);
    return 0;
}

//importa dados da categoria
int importa_Categoria(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    categoria *dados;
    
    dados=calloc(1,sizeof(categoria)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){ //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){ //verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(categoria));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "descricao") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].desc, token);
                } else if (strcmp(token, "valor") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].vlr=atof(token);
                } else if (strcmp(token, "adulto") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].adulto = atoi(token);
                } else if (strcmp(token, "crianca") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].crianca = atoi(token);
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(categoria));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_Cat(dados);
    
    atualizar_CategoriaBD(dados,lenDados); //muda dados
    free(dados);
    return 0;
}

//importa dados de produtos
int importa_Produto(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    produto *dados;
    
    dados=calloc(1,sizeof(produto)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){ //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){  //verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(produto));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "descricao") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].desc, token);
                } else if (strcmp(token, "estoque_minimo") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].estmin=atoi(token);
                } else if (strcmp(token, "estoque") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].est=atoi(token);
                } else if (strcmp(token, "custo") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].custo=atof(token);
                }
                else if (strcmp(token, "venda") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].venda=atof(token);
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(produto));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_Pro(dados);
    
    atualizar_ProdutoBD(dados,lenDados);
    free(dados);
    return 0;
}

//importa dados de fornecedores
int importa_Fornecedor(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    fornecedor *dados;
    
    dados=calloc(1,sizeof(fornecedor)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){  //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){ //verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(fornecedor));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "nome") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].nome, token);
                } else if (strcmp(token, "telefone") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].telefone, token);
                } else if (strcmp(token, "email") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].email, token);
                } else if (strcmp(token, "cnpj") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].cnpj, token);
                } else if (strcmp(token, "endereco") == 0) {
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.rua, token);
                    token = strtok(NULL, ",");
                    dados[i-1].end.num=atoi(token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.comp, token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.bairro, token);
                    token = strtok(NULL, ",");
                    strcpy(dados[i-1].end.cidade, token);
                    token = strtok(NULL, ",<");
                    strcpy(dados[i-1].end.estado, token);
                } else if (strcmp(token, "inscricao_estadual") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].inscEstadual = atoi(token);
                } else if (strcmp(token, "razao_social") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].razaoSocial, token);
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(fornecedor));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_For(dados);
    
    atualizar_FornecedorBD(dados,lenDados); //muda dados
    free(dados);
    return 0;
}

//importa dados dos operadores
int importa_Operador(FILE *arq){
    
    int i=0;
    char linha[500], *token,*delimitadores = "<>=\n\t";
    operador *dados;
    
    dados=calloc(1,sizeof(operador)); //vetor dinamico
    
    strcpy(token,"tabela");
        
    while(strcmp(token,"/tabela")!=0){ //percorre tabela
        
        fgets(linha,500,arq);
        token = strtok(linha, delimitadores);  //recebe <registro>
        
        if (token == NULL) {
            printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
            free(dados);
            return 1;
        }
    
        if(strcmp(token,"registro")==0){ // verifica se entrou em registro
            
            i++;
            dados=realloc(dados,i*sizeof(operador));
            
            while(strcmp(token,"/registro")!=0){ //até o fim do registro,
                fgets(linha,500,arq);               //pula linha e procura token de indentificação
                token = strtok(linha, delimitadores);

                if (token == NULL) {
                    printf("|===ARQUIVO NÃO ESTÁ FORMATADO CORRETAMENTE===|\n\n");
                    return 1;
                }
                if(strcmp(token, "codigo") == 0){
                    token = strtok(NULL, delimitadores);
                    dados[i-1].cod = atoi(token);
                } else if (strcmp(token, "nome") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].nome, token);
                } else if (strcmp(token, "usuario") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].usuario,token);
                } else if (strcmp(token, "senha") == 0) {
                    token = strtok(NULL, delimitadores);
                    strcpy(dados[i-1].senha,token);
                } else if (strcmp(token, "acesso") == 0) {
                    token = strtok(NULL, delimitadores);
                    dados[i-1].acesso[0]=token[0]-'0';          
                    dados[i-1].acesso[1]=token[1]-'0';
                    dados[i-1].acesso[2]=token[2]-'0';          //'-0' para transforar char em int
                    dados[i-1].acesso[3]=token[3]-'0';
                    dados[i-1].acesso[4]=token[4]-'0';
                }
            }
        }
    }
    
    dados=realloc(dados,(i+1)*sizeof(operador));
    dados[i].cod=-1; //sinaliza fim
    
    int lenDados=len_Ope(dados);
    
    atualizar_OperadorBD(dados,lenDados); //muda dados
    free(dados);
    return 0;
}
