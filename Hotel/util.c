/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "bancoDados.h"
#include "util.h"
#include "importacao.h"
#include "exportacao.h"

//função para inicializar operadores
void cria_ADM(operador *novo){
    int op; 
        
    setbuf(stdin, NULL);
    printf("NENHUM OPERADOR CADASTRADO:\n1 - CRIE UMA CONTA ADMINISTRATIVA\n0 - CANCELAR\nDigite uma opção: ");
    scanf("%d",&op);
    system("clear");
        
    if(op!=1){
        printf("!===LOGIN CANCELADO===!\n");
        exit(0);
    }
  
    printf("!===ESTA CONTA TERÁ ACESSO A TODO O SISTEMA===!\n\n");
                                        
    do{                                                             //COLETA DADOS DA CONTA ADMINISTRATIVA
        printf("Digite o código da conta: ");                               
        scanf("%d",&novo->cod);  
            
        if(novo->cod<0){             //Códigos positivos para não ocorrer problemas na visualização do tamanho da lista
            system("clear");
            printf("!===CÓDIGO DA CONTA DEVE SER POSITIVO");
        }
            
    }while(novo->cod<0);
            
    setbuf(stdin, NULL);
    printf("Digite o nome do operador: ");
    scanf("%[^\n]s",novo->nome);                 //COLETA DADOS DA CONTA ADMINISTRATIVA
                                                                   
    setbuf(stdin, NULL);
    printf("Digite o nome do usuário: ");
    scanf("%[^\n]s",novo->usuario);

    setbuf(stdin, NULL);
    printf("Digite a senha: ");                             //COLETA DADOS DA CONTA ADMINISTRATIVA
    scanf("%[^\n]s",novo->senha);
    system("clear");
        
    for(int i=0;i<5;i++){
        novo->acesso[i]=1;  //concede acesso a todos os módulos
    }
    
    return;
}

//função para realizar login do sistema
void login(operador *adm){
    
    operador *bdOpe=dados_Operadores(bdOpe);  //abre banco de dados
    
    int i,cont,lenOpe=len_Ope(bdOpe); //tamnho do BD
    char user[50],senha[50];
    
    printf("|=======LOGIN======|\n\n");
    
    do{  //loop para verificar e repetir login
        setbuf(stdin, NULL);
        printf("Digite o nome de usuário: ");
        scanf("%[^\n]s",user);                     

        setbuf(stdin, NULL);
        printf("Digite a senha: ");     
        scanf(" %[^\n]s",senha);                             
        system("clear");
        
        for(i=0;i<lenOpe;i++){  //passa por todo banco de dados
            if(strcmp(user,bdOpe[i].usuario)==0 && strcmp(senha,bdOpe[i].senha)==0){//CASO USUARIO E SENHA ESTEJAM CORRETAS QUEBRA LOOP
                *adm=bdOpe[i];   //salva operador compativel
                free(bdOpe);
                printf("|===LOGIN EFETUADO COM SUCESSO===|\n\n");
                return; //sai da função
            }
        }
        
        printf("!=====SENHA INCORRETA=====!\n\n");   //pergunta se o usuario quer continuar no login
        printf("Digite 0 para cancelar login (programa finalizará):  ");
        scanf("%d",&cont);
        system("clear");
    }while(cont!=0);
    
    free(bdOpe);  //em caso de desistencia, libera BD e fecha sistema
    exit(0);
}

//função para verificar acesso do user ao módulo
int verifica_Acesso(operador adm,int modulo){
    
    if(adm.acesso[modulo-1]==1){  //se valor da possição equivalente ao módulo == 1 acesso liberado
        return 1;
    }else{
        return 0;
    }
}

//função para printar e realizar operações com relação ao acesso do operador
void menu_Acesso(operador adm, operador *novo){
    int op=1,i;
    
    while(op!=6){  //imprime menu
        printf("|===============PERMISSÕES DE ACESSO===============|\n");
        for(i=0;i<5;i++){
            if(i==0){
                printf("|1 - Cadastros e Gestão de dados - : ");
            }
            if(i==1){
                printf("|2 - Reservas  - - - - - - - - - - : ");
            }
            if(i==2){
                printf("|3 - Transações  - - - - - - - - - : ");
            }
            if(i==3){
                printf("|4 - Feedback    - - - - - - - - - : ");
            }
            if(i==4){
                printf("|5 - Importação/Exportação de dados: ");
            }
            
            if(adm.acesso[i]==1){          //printar permissões no menu
                if(novo->acesso[i]==1){
                    printf("   CONCEDIDO  |\n");
                }else{
                    printf("NÃO CONCEDIDO |\n");
                }
            }else{    
                printf("SEM PERMISSÃO |\n");
            }
        }
        printf("|6 - Continuar\n|0 - Cancelar\nDigite uma opção para alterar acesso da conta: ");
        scanf("%d",&op);
        system("clear");
        
        op--;
        if(op>=0 && op<=4){            //caso adm tenho permissão ao módulo, pode conceder acesso à nova conta
            if(adm.acesso[op]==1){
                if(novo->acesso[op]==1){ //inverte situação atual do acesso
                    novo->acesso[op]--;
                }else{
                    novo->acesso[op]++;
                }
            }else{
                printf("!=======ESTA CONTA NÃO PODE DAR PERMISSÃO AO MÓDULO SELECIONADO======!\n\n");
            }
        }
        op++;
        
        if(op==0){
            printf("!===OPERAÇÃO CANCELADA===!\n\n");
            return;
        }
    }
}

//menu de importação ou exportação de dados
void menu_Tabelas(int tipo){
    
    int op=1;
    tabela verf;
    
    verf.Aco=-1;
    verf.Cat=-1; //Verifica quais tabelas serão selecionadas
    verf.For=-1;
    verf.Hos=-1;
    verf.Hot=-1;
    verf.Ope=-1;
    verf.Pro=-1;
    
    while (op != 0) {

        printf("|=============TABELAS===========|\n");         //MENU DINAMICO
        if(verf.Hot!=-1){
            if(tipo==1){
                printf("|1 - Hotel:          IMPORTAR   |\n");
            }else{
                printf("|1 - Hotel:          EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|1 - Hotel:        NÃO IMPORTAR |\n");
            }else{
                printf("|1 - Hotel:        NÃO EXPORTAR |\n");
            }
        }
        if(verf.Hos!=-1){
            if(tipo==1){
                printf("|2 - Hóspedes:       IMPORTAR   |\n");
            }else{
                printf("|2 - Hóspedes:       EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|2 - Hóspedes:     NÃO IMPORTAR |\n");
            }else{
                printf("|2 - Hóspedes:     NÃO EXPORTAR |\n");
            }
        }
        if(verf.Aco!=-1){
            if(tipo==1){
                printf("|3 - Acomodações:    IMPORTAR   |\n");
            }else{
                printf("|3 - Acomodações:    EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|3 - Acomodações:  NÃO IMPORTAR |\n");
            }else{
                printf("|3 - Acomodações:  NÃO EXPORTAR |\n");
            }
        }
        if(verf.Cat!=-1){
            if(tipo==1){
                printf("|4 - Categorias:     IMPORTAR   |\n");
            }else{
                printf("|4 - Categorias:     EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|4 - Categorias:   NÃO IMPORTAR |\n");
            }else{
                printf("|4 - Categorias:   NÃO EXPORTAR |\n");
            }
        }
        if(verf.Pro!=-1){
            if(tipo==1){
                printf("|5 - Produtos:       IMPORTAR   |\n");
            }else{
                printf("|5 - Produtos:       EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|5 - Produtos:     NÃO IMPORTAR |\n");
            }else{
                printf("|5 - Produtos:     NÃO EXPORTAR |\n");
            }
        }
        if(verf.For!=-1){
            if(tipo==1){
                printf("|6 - Fornecedores:   IMPORTAR   |\n");
            }else{
                printf("|6 - Fornecedores:   EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|6 - Fornecedores: NÃO IMPORTAR |\n");
            }else{
                printf("|6 - Fornecedores: NÃO EXPORTAR |\n");
            }
        }
        if(verf.Ope!=-1){
            if(tipo==1){
                printf("|7 - Operadores:     IMPORTAR   |\n");
            }else{
                printf("|7 - Operadores:     EXPORTAR   |\n");
            }
        }else{
            if(tipo==1){
                printf("|7 - Operadores:   NÃO IMPORTAR |\n");
            }else{
                printf("|7 - Operadores:   NÃO EXPORTAR |\n");
            }
        }
        printf("|8 - Confirmar filtro           |\n"
                "|0 - Voltar                     |\n"
                "|Digite uma opção para prosseguir: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){             // marca/desmarca tabelas
                
            case 1:
                if(verf.Hot==1){
                    verf.Hot=-1;
                }else{
                    verf.Hot=1;
                }
            break;
            
            case 2:
                if(verf.Hos==1){
                    verf.Hos=-1;
                }else{
                    verf.Hos=1;
                }
            break;
            
            case 3:
                if(verf.Aco==1){
                    verf.Aco=-1;
                }else{
                    verf.Aco=1;
                }
            break;
            
            case 4:
                if(verf.Cat==1){
                    verf.Cat=-1;
                }else{
                    verf.Cat=1;
                }
            break;
            
            case 5:
                if(verf.Pro==1){
                    verf.Pro=-1;
                }else{
                    verf.Pro=1;
                }
            break;
            
            case 6:
                if(verf.For==1){
                    verf.For=-1;
                }else{
                    verf.For=1;
                }
            break;
            
            case 7:
                if(verf.Ope==1){
                    verf.Ope=-1;
                }else{
                    verf.Ope=1;
                }
            break;
            
            case 8:
                if(tipo==1){
                    importa_Arquivos(verf);
                    return;
                }else{
                    exporta_Arquivos(verf);
                    return;
                }
            break;
            
            case 0:
                printf("!===AÇÃO CANCELADA===!\n\n");
                return;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
}

//COLETA DATA DE CHECK-IN E CHECK-OUT
data coleta_data(){
    
    int data_pi,data_pf;
    data busca; 
    
    printf("Digite o periodo em que deseja fazer a reserva:\n");
    do{
        printf("Digite a data de check-in:\nDia: ");
        scanf("%d",&busca.dia_i);
        printf("Mês(númerico): ");
        scanf("%d",&busca.mes_i);
        printf("Ano: ");
        scanf("%d",&busca.ano_i);
                
        printf("\nDigite a data de check-out:\nDia: ");
        scanf("%d",&busca.dia_f);
        printf("Mês(númerico): ");
        scanf("%d",&busca.mes_f);
        printf("Ano: ");
        scanf("%d",&busca.ano_f);
        system("clear");
                                
        data_pi= busca.ano_i*10000+busca.mes_i*100+busca.dia_i;   //transforma data em inteiro para compara maior
        data_pf= busca.ano_f*10000+busca.mes_f*100+busca.dia_f;
        
        if(data_pf<=data_pi){
            printf("!===DATA DE CHECK-OUT NÃO PODE SER ANTERIOR OU IGUAL DATA DE CHECK-IN===!\n\n");
        }
        
    }while(data_pf<=data_pi);    
    return busca;
}

//função para controlar filtros da reserva
int filtro_Reserva(pesquisa *busca){
    pesquisa novo;      //armazena filtros
    novo.data_pes=coleta_data(); //data obrigatoria
    novo.adulto=-1;     //inicializa filtros
    novo.crianca=-1;    // -1 == sem filtro
    novo.cat=-1;
    strcpy(novo.fac,""); 
    
    categoria *bdCat=dados_Categorias(bdCat); //carrega BD de categoria para verificar novo código
    int lenCat=len_Cat(bdCat);
    
    int op=1,cod,j=0;
    
    do{
        printf("|======MENU DE FILTROS======|\n|1 - Periodo: %d/%d/%d - %d/%d/%d\n",novo.data_pes.dia_i
            ,novo.data_pes.mes_i,novo.data_pes.ano_i,novo.data_pes.dia_f,novo.data_pes.mes_f,novo.data_pes.ano_f);
        
        if(novo.cat!=-1){
            printf("|2 - Categoria: %d\n",bdCat[novo.cat].cod);        //MENU DINAMICO
        }else{
            printf("|2 - Categoria:   SEM FILTRO\n");
        }
        
        if(strcmp(novo.fac,"")!=0){
            printf("|3 - Facilidades: %s\n",novo.fac);
        }else{
            printf("|3 - Facilidades: SEM FILTRO\n");
        }
        
        if(novo.adulto!=-1){
            printf("|4 - Nº Adultos: %d\n",novo.adulto);
        }else{
            printf("|4 - Nº Adultos:  SEM FILTRO\n");
        }
        
        if(novo.crianca!=-1){
            printf("|5 - Nº Crianças: %d\n",novo.crianca);
        }else{
            printf("|5 - Nº Crianças: SEM FILTRO\n");
        }
        
        printf("|6 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                novo.data_pes=coleta_data(); //COLETA NOVA DATA
            break;
            
            case 2:
                 
                do{
                    printf("Digite o código da categoria (-1 para cancelar filtro): ");
                    scanf("%d",&cod);                                   
                                                   
                    
                    if(cod==-1){   //se -1 cancela filtro
                        novo.cat=cod;
                        system("clear");
                        break;
                    }
                                                                        //ALGORITMO PARA VALIDAR CÓDIGOS
                    j=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
                    while(bdCat[j].cod!=cod && j<lenCat){
                        j++;
                    }

                    if(j==lenCat){     
                        printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                               "Digite 0 para cancelar procura:  ");
                        scanf("%d",&op);
                        system("clear"); 

                        if(op==0){
                            printf("!===FILTRO CANCELADO===!\n\n");
                            free(bdCat);
                            op=1;
                            break;
                        }
                    }else{
                        novo.cat=j;
                        system("clear");
                    }
                }while(j==lenCat);
                
            break;
            
            case 3:
                acomodacao *bdAco=dados_Acomodacoes(bdAco); //carrega BD de acomodações para verificar facilidades
                int lenAco=len_Aco(bdAco);
                char fac[50];
                 
                do{
                    setbuf(stdin, NULL);
                    printf("Digite as facilidades da acomodação (-1 para cancelar filtro): ");
                    scanf("%[^\n]s",&fac);                            
                                                   
                    if(atoi(fac)==-1){   //-1 cancela filtro
                        strcpy(novo.fac,"");
                        system("clear");
                        break;
                    }
                                                                        //ALGORITMO PARA VALIDAR FACILIDADES
                    j=0;                                                //PROCURA REPETIÇÃO DE FACILIDADES
                    while(strcmp(bdAco[j].fac,fac)!=0 && j<lenAco){
                        j++;
                    }

                    if(j==lenAco){     
                        printf("!===FACILIDADE NÃO ESTÁ EM USO===!\n\n"
                               "Digite 0 para cancelar procura:  ");
                        scanf("%d",&op);
                        system("clear"); 

                        if(op==0){
                            printf("!===FILTRO CANCELADO===!\n\n");
                            free(bdAco);
                            op=1;
                            break;
                        }
                    }else{
                        free(bdAco);
                        strcpy(novo.fac,fac);
                        system("clear");
                    }
                }while(j==lenAco);
            break;
            
            case 4:
                printf("Digite o Nº de Adultos (-1 para cancelar filtro): ");
                scanf("%d",&cod);
                novo.adulto=cod;;
                system("clear");
            break;
            
            case 5:
                printf("Digite o Nº de Crianças (-1 para cancelar filtro): ");
                scanf("%d",&cod);
                novo.crianca=cod;;
                system("clear");
            break;
            
            case 6:
                system("clear");
                *busca=novo; //salva filtro
                
                printf("|===FILTROS CADASTRADOS COM SUCESSO===|\n\n");
                free(bdCat);
                return 0; //sem erro
            break;
            
            case 0:
                system("clear");
                printf("|=====RESERVA CANCELADA=====|\n\n");
                free(bdCat);
                return 1; //busca cancelada
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;   
        }
        
    }while(op!=0);
}

//função para controlar filtros de hospede
int filtro_Hospedes(int *codI,int *codF,char *sexo){
    
    int op;
    
    *codI=-1;
    strcpy(sexo,"");
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codI!=-1){
            printf("|1 - Faixa de Códigos: %d até %d\n",*codI,*codF);        //MENU DINAMICO
        }else{
            printf("|1 - Faixa de Códigos:  SEM FILTRO\n");
        }
        
        if(strcmp(sexo,"")!=0){
            printf("|2 - Sexo: %s\n",sexo);
        }else{
            printf("|2 - Sexo:  SEM FILTRO\n");
        }
     
        printf("|3 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o valor inicial do intervalo (-1 para cancelar filtro): ");
                scanf("%d",codI);
                
                if(*codI>=0){
                    
                    printf("Digite o valor final do intervalo (-1 para cancelar filtro): ");
                    scanf("%d",codF);
                    
                    if(*codI>*codF){
                        *codI=-1;
                        system("clear");
                        printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                    }else{
                        system("clear");
                    }
                    
                }else{
                    *codI=-1;
                    system("clear");
                    printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                setbuf(stdin, NULL);
                printf("Digite o sexo dos hospédes (-1 para cancelar filtro): ");
                scanf("%[^\n]s",sexo);                            
                                                   
                if(atoi(sexo)==-1){   //-1 cancela filtro
                    strcpy(sexo,"");
                }
                
                system("clear");
                
            break;
            
            case 3:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
    
}

//função para controlar filtros de acomodações
int filtro_Acomodacoes(int *codI,int *codF,int *codCat,data *busca){
    int op;
    
    *codI=-1;
    *codCat=-1;
    busca->dia_i=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codI!=-1){
            printf("|1 - Faixa de Códigos: %d até %d\n",*codI,*codF);        //MENU DINAMICO
        }else{
            printf("|1 - Faixa de Códigos:  SEM FILTRO\n");
        }
        
        if(*codCat!=-1){
            printf("|2 - Categoria: %d\n",*codCat);
        }else{
            printf("|2 - Categoria:  SEM FILTRO\n");
        }
     
        if(busca->dia_i!=-1){
            printf("|3 - Periodo livre: %d/%d/%d - %d/%d/%d\n",busca->dia_i
            ,busca->mes_i,busca->ano_i,busca->dia_f,busca->mes_f,busca->ano_f);        //MENU DINAMICO
        }else{
            printf("|3 - Periodo livre:  SEM FILTRO\n");
        }
        printf("|4 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o valor inicial do intervalo (-1 para cancelar filtro): ");
                scanf("%d",codI);
                
                if(*codI>=0){
                    
                    printf("Digite o valor final do intervalo (-1 para cancelar filtro): ");
                    scanf("%d",codF);
                    
                    if(*codI>*codF){
                        *codI=-1;
                        system("clear");
                        printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                    }else{
                        system("clear");
                    }
                }else{
                    *codI=-1;
                    system("clear");
                    printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                printf("Digite o código da categoria (-1 para cancelar filtro): ");
                scanf("%d",codCat);
                system("clear");
                
                if(*codCat<0){
                    *codCat=-1;
                    system("clear");
                    printf("!===VALOR DE CÓDIGO INVÁLIDO===!\n\n");
                }
                
            break;
            
            case 3:
                if(busca->dia_i!=-1){
                    printf("Digite -1 para cancelar filtro antigo ou 0 para continuar: ");
                    scanf("%d",&busca->dia_i);
                    system("clear");
                    
                    if(busca->dia_i==-1){
                        break;
                    }
                }
                *busca=coleta_data();
            break;
                
            
            case 4:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de reservas (para relatorio)
int filtro_ReservaRelatorio(int *codHos,int *codAco,data *busca){
    int op;
    
    *codHos=-1;
    *codAco=-1;
    busca->dia_i=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codHos!=-1){
            printf("|1 - Hóspede: %d\n",*codHos);        //MENU DINAMICO
        }else{
            printf("|1 - Hóspede:  SEM FILTRO\n");
        }
        
        if(*codAco!=-1){
            printf("|2 - Acomodação: %d\n",*codAco);
        }else{
            printf("|2 - Acomodação:  SEM FILTRO\n");
        }
     
        if(busca->dia_i!=-1){
            printf("|3 - Periodo reservado: %d/%d/%d - %d/%d/%d\n",busca->dia_i
            ,busca->mes_i,busca->ano_i,busca->dia_f,busca->mes_f,busca->ano_f);        //MENU DINAMICO
        }else{
            printf("|3 - Periodo reservado:  SEM FILTRO\n");
        }
        printf("|4 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite ocódigo do Hóspede (-1 para cancelar filtro): ");
                scanf("%d",codHos);
                
                if(*codHos<0){
                    *codHos=-1;
                    system("clear");
                    printf("!===VALOR DE CÓDIGO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                printf("Digite o código da Acomodação (-1 para cancelar filtro): ");
                scanf("%d",codAco);
                system("clear");
                
                if(*codAco<0){
                    *codAco=-1;
                    system("clear");
                    printf("!===VALOR DE CÓDIGO INVÁLIDO===!\n\n");
                }
                
            break;
            
            case 3:
                if(busca->dia_i!=-1){
                    printf("Digite -1 para cancelar filtro antigo ou 0 para continuar: ");
                    scanf("%d",&busca->dia_i);
                    system("clear");
                    
                    if(busca->dia_i==-1){
                        break;
                    }
                }
                *busca=coleta_data();
            break;
                
            
            case 4:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de movimento de acomodação
int filtro_movAcomodacoes(int *codAco,int *numDia,float *valor){
    int op;
    
    *valor=-1;
    *codAco=-1;
    *numDia=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codAco!=-1){
            printf("|1 - Acomodação: %d\n",*codAco);
        }else{
            printf("|1 - Acomodação:  SEM FILTRO\n");
        }
        
        if(*numDia!=-1){
            printf("|2 - Quantidade de diárias: %d\n",*numDia);        //MENU DINAMICO
        }else{
            printf("|2 - Quantidade de diárias:  SEM FILTRO\n");
        }
        
        if(*valor!=-1){
            printf("|3 - Rendimento p/ hospedagem: %.2f\n",*valor);        //MENU DINAMICO
        }else{
            printf("|3 - Rendimento p/ hospedagem:  SEM FILTRO\n");
        }
    
        printf("|4 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o código da Acomodação (-1 para cancelar filtro): ");
                scanf("%d",codAco);
                system("clear");
                
                if(*codAco<0){
                    *codAco=-1;
                    system("clear");
                    printf("!===VALOR DE CÓDIGO INVÁLIDO===!\n\n");
                }
                
            break;
            
            case 2:
                printf("Digite o número de diárias (-1 para cancelar filtro): ");
                scanf("%d",numDia);
                system("clear");
                
                if(*numDia<=0){
                    *numDia=-1;
                    system("clear");
                    printf("!===VALOR INVÁLIDO===!\n\n");
                }
            break;
            
            case 3:
                printf("Digite o rendimento (-1 para cancelar filtro): ");
                scanf("%f",valor);
                system("clear");
                
                if(*valor<0){
                    *valor=-1;
                    system("clear");
                    printf("!===VALOR INVÁLIDO===!\n\n");
                }
            break;
                
            case 4:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de produtos
int filtro_Produtos(int *codI,int *codF){
    int op;
    
    *codI=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codI!=-1){
            printf("|1 - Faixa de Códigos: %d até %d\n",*codI,*codF);        //MENU DINAMICO
        }else{
            printf("|1 - Faixa de Códigos:  SEM FILTRO\n");
        }

        printf("|2 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o valor inicial do intervalo (-1 para cancelar filtro): ");
                scanf("%d",codI);
                
                if(*codI>=0){
                    
                    printf("Digite o valor final do intervalo (-1 para cancelar filtro): ");
                    scanf("%d",codF);
                    
                    if(*codI>*codF){
                        *codI=-1;
                        system("clear");
                        printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                    }else{
                        system("clear");
                    }
                    
                }else{
                    *codI=-1;
                    system("clear");
                    printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de vendas
int filtro_Vendas(char *pag){
    int op;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n"
               "|1 - Dinheiro\n|2 - Crédito\n|3 - Débito\n"
               "|4 - Sem filtro\n|0 - Cancelar\n|Digite uma opção:");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                strcpy(pag,"dinheiro");
                return 0;
            break;
            
            case 2:
                strcpy(pag,"credito");
                return 0;
            break;
            
            case 3:
                strcpy(pag,"debito");
                return 0;
            break;
            
            case 4:
                strcpy(pag,"");
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de contas a receber
int filtro_ContasReceber(int *codI,int *codF,data *busca){
    int op;
    
    *codI=-1;
    busca->dia_f=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codI!=-1){
            printf("|1 - Faixa de Códigos Clientes: %d até %d\n",*codI,*codF);        //MENU DINAMICO
        }else{
            printf("|1 - Faixa de Códigos Clientes:  SEM FILTRO\n");
        }
        
        if(busca->dia_f!=-1){
            printf("|2 - Data de Recebimento: %d/%d/%d\n"
                ,busca->dia_f,busca->mes_f,busca->ano_f);        //MENU DINAMICO
        }else{
            printf("|2 - Data de Recebimento:  SEM FILTRO\n");
        }

        printf("|3 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o valor inicial do intervalo (-1 para cancelar filtro): ");
                scanf("%d",codI);
                
                if(*codI>=0){
                    
                    printf("Digite o valor final do intervalo (-1 para cancelar filtro): ");
                    scanf("%d",codF);
                    
                    if(*codI>*codF){
                        *codI=-1;
                        system("clear");
                        printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                    }else{
                        system("clear");
                    }
                    
                }else{
                    *codI=-1;
                    system("clear");
                    printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                if(busca->dia_f!=-1){
                    printf("Digite -1 para cancelar filtro antigo ou 0 para continuar: ");
                    scanf("%d",&busca->dia_f);
                    system("clear");
                    
                    if(busca->dia_f==-1){
                        break;
                    }
                }
                printf("Digite a data de Recebimento:\n");
                printf("Dia(DD): ");
                scanf("%d",&busca->dia_f);
                printf("Mes(MM): ");
                scanf("%d",&busca->mes_f);
                printf("Ano(AAAA): ");
                scanf("%d",&busca->ano_f);
                system("clear");
            break;
            
            case 3:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de contas a pagar
int filtro_ContasPagar(int *codI,int *codF,data *busca){
    int op;
    
    *codI=-1;
    busca->dia_i=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(*codI!=-1){
            printf("|1 - Faixa de Códigos Fornecedor: %d até %d\n",*codI,*codF);        //MENU DINAMICO
        }else{
            printf("|1 - Faixa de Códigos Fornecedor:  SEM FILTRO\n");
        }
     
        if(busca->dia_i!=-1){
            printf("|2 - Periodo Vencimento: %d/%d/%d - %d/%d/%d\n",busca->dia_i
            ,busca->mes_i,busca->ano_i,busca->dia_f,busca->mes_f,busca->ano_f);        //MENU DINAMICO
        }else{
            printf("|2 - Periodo Vencimento:  SEM FILTRO\n");
        }
        printf("|3 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                printf("Digite o valor inicial do intervalo (-1 para cancelar filtro): ");
                scanf("%d",codI);
                
                if(*codI>=0){
                    
                    printf("Digite o valor final do intervalo (-1 para cancelar filtro): ");
                    scanf("%d",codF);
                    
                    if(*codI>*codF){
                        *codI=-1;
                        system("clear");
                        printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                    }else{
                        system("clear");
                    }
                }else{
                    *codI=-1;
                    system("clear");
                    printf("!===VALOR DE INTERVALO INVÁLIDO===!\n\n");
                }
            break;
            
            case 2:
                if(busca->dia_i!=-1){
                    printf("Digite -1 para cancelar filtro antigo ou 0 para continuar: ");
                    scanf("%d",&busca->dia_i);
                    system("clear");
                    
                    if(busca->dia_i==-1){
                        break;
                    }
                }
                *busca=coleta_data();
            break;
                
            
            case 3:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para controlar filtros de movimento no caixa
int filtro_movCaixa(data *busca){
    int op;

    busca->dia_i=-1;
    
    do{
        printf("|=============MENU DE FILTROS===========|\n");
        
        if(busca->dia_i!=-1){
            printf("|1 - Periodo: %d/%d/%d - %d/%d/%d\n",busca->dia_i
            ,busca->mes_i,busca->ano_i,busca->dia_f,busca->mes_f,busca->ano_f);        //MENU DINAMICO
        }else{
            printf("|1 - Periodo:  SEM FILTRO\n");
        }
        printf("|2 - Confirmar Dados\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                if(busca->dia_i!=-1){
                    printf("Digite -1 para cancelar filtro antigo ou 0 para continuar: ");
                    scanf("%d",&busca->dia_i);
                    system("clear");
                    
                    if(busca->dia_i==-1){
                        break;
                    }
                }
                *busca=coleta_data();
            break;
                
            
            case 2:
                return 0;
            break;
            
            case 0:
                system("clear");
                printf("|=====RELATÓRIO CANCELADO=====|\n\n");
                return 1;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
        
    }while(op!=0);
}

//função para associar vetores de comandas ao seu respectivo checkin (arq BIN) 
void associa_Comandas(checkin *bdCIn,comanda *bdCom){
    
    int lenCIn=len_CIn(bdCIn),j,k=0;  //IMPORTANTE: variavel K caminha no bdCom
    
    for(int i=0;i<lenCIn;i++){        //para cada checkIn
        
        j=0;
        comanda *temp=calloc(1,sizeof(comanda));   //cria vetor de comandas temporario
        while(bdCom[k].cod!=-1){               //percorre todas as comandas até achar -1
            j++;                               //-1 == sinal de fim de um vetor de comandas
            temp=realloc(temp,j*sizeof(comanda));
            
            temp[j-1].cod=bdCom[k].cod;     //armazena todos os dados de um vetor de comandas no temp
            temp[j-1].valor=bdCom[k].valor; 
            k++;
        }
        
        temp=realloc(temp,(j+1)*sizeof(comanda));//coloca marca de fim no final
        temp[j].cod=bdCom[k].cod;
        k++;
        bdCIn[i].prod=temp;  //associa temp no banco de dados do checkin
    }
}

//função para associar vetores de compras à sua respectiva nota (arq BIN) 
void associa_Compras(notaEntrada *bdNotas,compra *bdCom){
    
    int lenNotas=len_Notas(bdNotas),j,k=0;  //IMPORTANTE: variavel K caminha no bdCom
    
    for(int i=0;i<lenNotas;i++){        //para cada checkIn
        
        j=0;
        compra *temp=calloc(1,sizeof(compra));   //cria vetor de compras temporario
        while(bdCom[k].cod!=-1){               //percorre todas as compras até achar -1
            j++;                               //-1 == sinal de fim de um vetor de compras
            temp=realloc(temp,j*sizeof(compra));
            
            temp[j-1].cod=bdCom[k].cod;     //armazena todos os dados de um vetor de compras no temp
            temp[j-1].qtd=bdCom[k].qtd; 
            temp[j-1].vUnid=bdCom[k].vUnid; 
            k++;
        }
        
        temp=realloc(temp,(j+1)*sizeof(compra));//coloca marca de fim no final
        temp[j].cod=bdCom[k].cod;
        k++;
        bdNotas[i].prod=temp;  //associa temp no banco de dados de notas
    }
}

FILE *opcao_Arquivo(FILE *arq){
    int op=1;
    char caminho[100];
    
    while(op!=0){
        printf("|=====ARQUIVO=====|\n"
           "|1 - Gerar arquivo em caminho pré-definido\n"
           "|2 - Gerar arquivo em caminho à ser definido\n"
           "|0 - Não gerar arquivo\n"
           "|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        switch(op){
            
            case 1:
                strcpy(caminho,"");
                arq=cria_ArquivoRelatorio(arq,caminho);
                
                if(arq == NULL){
                    return NULL;
                }
                
                return arq;
            break;
            
            case 2:
                setbuf(stdin, NULL);
                printf("Defina o caminho do arquivo: ");
                scanf("%[^\n]s",&caminho);   
                system("clear");
                
                arq=cria_ArquivoRelatorio(arq,caminho);
                
                if(arq == NULL){
                    return NULL;
                }
                
                return arq;
            break;
            
            case 0:
                printf("|=====ARQUIVOS NÃO FORAM GERADOS=====|\n\n");
                return NULL;
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    
}

//função para selecionar tipo de arquivo do sistema
void tipo_Arquivo(){
    
    int op;
             //menu de tipos
    printf("|===TIPO DE ARQUIVO===|\n"
           "|1 - Texto            |\n"
           "|2 - Binário          |\n"
           "|0 - Cancelar         |\n"
           "|Digite uma opção:");
    scanf("%d",&op);
    system("clear");
    
    if(op==1){ 
        FILE *arq=fopen(".//Bd//Texto.txt","r");      //se ja for tipo texto retorna
        if(arq!=NULL){
            printf("!===ARQUIVOS JÁ SÃO TIPO TEXTO===!\n\n");
            fclose(arq);
            return;
        }
        arq=fopen(".//Bd//Binario.bin","rb");  //senao converte para binario
        if(arq!=NULL){
            fclose(arq);
            converte_Arquivos(); //função para converter
            return;
        }
        arq=fopen(".//Bd//Texto.txt","w"); //se n tiver nenhum cria texto
        fclose(arq);
        inicializa_Arquivos(); //inicializa arquivos
        
    }else{
        if(op==2){
            FILE *arq=fopen(".//Bd//Binario.bin","rb");   //se ja for tipo binario retorna
            if(arq!=NULL){
                printf("!===ARQUIVOS JÁ SÃO TIPO BINÁRIO===!\n\n");
                fclose(arq);
                return;
            }
            arq=fopen(".//Bd//Texto.txt","r");  //senao converte para texto
            if(arq!=NULL){
                fclose(arq);
                converte_Arquivos();  //função para converter
                return;
            }
            arq=fopen(".//Bd//Binario.bin","wb");  //se n tiver nenhum cria binario
            fclose(arq);
            inicializa_Arquivos();   //inicializa arquivos
        }else{
            printf("!===AÇÃO CANCELADA===!\n\n");
        }
    }
}

//função para converter tipo de arquivos do sistema
void converte_Arquivos(){
    
    float caixa;
    dados_Caixa(&caixa);
    hotel bdHotel;                  //puxa todos bancos de dados
    dados_Hotel(&bdHotel);
    acomodacao *bdAco=dados_Acomodacoes(bdAco);
    categoria *bdCat=dados_Categorias(bdCat);
    fornecedor *bdFor=dados_Fornecedores(bdFor);
    hospede *bdHos=dados_Hospedes(bdHos);
    operador *bdOpe=dados_Operadores(bdOpe);
    produto *bdPro=dados_Produtos(bdPro);
    reserva *bdRes=dados_Reservas(bdRes);
    checkin *bdCIn=dados_CheckIn(bdCIn);
    movCaixa *bdMovC=dados_movCaixa(bdMovC);
    movAcomodacao *bdMovA=dados_movAcomodacao(bdMovA);
    movCartao *bdCRec=dados_ContasReceber(bdCRec);
    venda *bdVen=dados_Vendas(bdVen);
    movCartao *bdCPag=dados_ContasPagar(bdCPag);
    notaEntrada *bdNotas=dados_NotasEntrada(bdNotas);
    
    int lenAco=len_Aco(bdAco),lenCat=len_Cat(bdCat),lenFor=len_For(bdFor),lenHos=len_Hos(bdHos),
            lenOpe=len_Ope(bdOpe),lenPro=len_Pro(bdPro),lenRes=len_Res(bdRes),lenCIn=len_CIn(bdCIn),lenMovC=len_MovC(bdMovC),
            lenMovA=len_MovA(bdMovA),lenCRec=len_Conta(bdCRec),lenVen=len_Ven(bdVen),lenCPag=len_Conta(bdCPag),lenNotas=len_Notas(bdNotas); //seus tamanhos
    
    int result;
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
                
    if(arq!=NULL){
        fclose(arq);
        result = remove(".//Bd//Acomodacoes.txt");    //remove todos os arquivos
        result = remove(".//Bd//Categorias.txt");
        result = remove(".//Bd//Fornecedores.txt");
        result = remove(".//Bd//Hospedes.txt");
        result = remove(".//Bd//Hotel.txt");
        result = remove(".//Bd//Operadores.txt");
        result = remove(".//Bd//Produtos.txt");
        result = remove(".//Bd//Reservas.txt");
        result = remove(".//Bd//CheckIn.txt");
        result = remove(".//Bd//Caixa.txt");
        result = remove(".//Bd//MovimentacaoCaixa.txt");
        result = remove(".//Bd//MovimentacaoAcomodacao.txt");
        result = remove(".//Bd//ContasReceber.txt");
        result = remove(".//Bd//Vendas.txt");
        result = remove(".//Bd//ContasPagar.txt");
        result = remove(".//Bd//NotasEntrada.txt");
        result = remove(".//Bd//Texto.txt");
        arq=fopen(".//Bd//Binario.bin","wb"); //cria binario
    }else{
        result = remove(".//Bd//Acomodacoes.bin");
        result = remove(".//Bd//Categorias.bin");  //remove todos os arquivos
        result = remove(".//Bd//Fornecedores.bin");
        result = remove(".//Bd//Hospedes.bin");
        result = remove(".//Bd//Hotel.bin");
        result = remove(".//Bd//Operadores.bin");
        result = remove(".//Bd//Produtos.bin");
        result = remove(".//Bd//Reservas.bin");
        result = remove(".//Bd//CheckIn.bin");
        result = remove(".//Bd//Comandas.bin");
        result = remove(".//Bd//Caixa.bin");
        result = remove(".//Bd//MovimentacaoCaixa.bin");
        result = remove(".//Bd//MovimentacaoAcomodacao.bin");
        result = remove(".//Bd//ContasReceber.bin");
        result = remove(".//Bd//Vendas.bin");
        result = remove(".//Bd//ContasPagar.bin");
        result = remove(".//Bd//NotasEntrada.bin");
        result = remove(".//Bd//Compras.bin");
        result = remove(".//Bd//Binario.bin");  
        arq=fopen(".//Bd//Texto.txt","w");    //cria texto
    } 
    fclose(arq);
    
    if(result!=0){
        printf("!===ERRO NA CONVERSÃO DOS ARQUIVOS===!\n\n");
        free(bdHos);
        free(bdAco);
        free(bdCat);
        free(bdFor);
        free(bdOpe);
        free(bdPro);
        free(bdRes);
        free(bdCIn);
        free(bdMovC);
        free(bdMovA);
        free(bdCRec);
        free(bdVen);
        free(bdCPag);
        free(bdNotas);
        return;
    }else{
        cadastrar_HotelBD(bdHotel);           //cadastra novamente bancos de dados
        atualizar_AcomodacaoBD(bdAco,lenAco);
        atualizar_CategoriaBD(bdCat,lenCat);
        atualizar_FornecedorBD(bdFor,lenFor);
        atualizar_HospedeBD(bdHos,lenHos);
        atualizar_OperadorBD(bdOpe,lenOpe);
        atualizar_ProdutoBD(bdPro,lenPro);
        atualizar_ReservaBD(bdRes,lenRes);
        atualizar_CheckInBD(bdCIn,lenCIn);
        atualizar_CaixaBD(caixa);
        atualizar_movCaixaBD(bdMovC,lenMovC);
        atualizar_movAcomodacaoBD(bdMovA,lenMovA);
        atualizar_ContasReceberBD(bdCRec,lenCRec);
        atualizar_VendasBD(bdVen,lenVen);
        atualizar_ContasPagarBD(bdCPag,lenCPag);
        atualizar_NotasEntradaBD(bdNotas,lenNotas);
        
        printf("!===ARQUIVOS CONVERTIDOS COM SUCESSO===!\n\n");
        free(bdHos);
        free(bdAco);
        free(bdCat);
        free(bdFor);
        free(bdOpe);
        free(bdPro);
        free(bdRes);
        free(bdCIn);
        free(bdMovC);
        free(bdMovA);
        free(bdCRec);
        free(bdVen);
        free(bdCPag);
        free(bdNotas);
        return;
    }
}

//função que retorna tamanho de BD operadores
int len_Ope(operador *bdOpe){
    
    int i=0;
    
    while(bdOpe[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD hospedes
int len_Hos(hospede *bdHos){
    
    int i=0;
    
    while(bdHos[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD categorias
int len_Cat(categoria *bdCat){
    
    int i=0;
    
    while(bdCat[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD acomodações
int len_Aco(acomodacao *bdAco){
    
    int i=0;
    
    while(bdAco[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD produtos
int len_Pro(produto *bdPro){
    
    int i=0;
    
    while(bdPro[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD fornecedores
int len_For(fornecedor *bdFor){
    
    int i=0;
    
    while(bdFor[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD reservas
int len_Res(reserva *bdRes){
    
    int i=0;
    
    while(bdRes[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD CheckIn
int len_CIn(checkin *bdCIn){
    
    int i=0;
    
    while(bdCIn[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD comandas
int len_Com(comanda *prod){
    
    int i=0;
    
    while(prod[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD movimento Caixa
int len_MovC(movCaixa *bdMovC){
    
    int i=0;
    
    while(bdMovC[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD movimento Aco
int len_MovA(movAcomodacao *bdMovA){
    
    int i=0;
    
    while(bdMovA[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD Contas a receber
int len_Conta(movCartao *bdConta){
    
    int i=0;
    
    while(bdConta[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD Vendas
int len_Ven(venda *bdVen){
    
    int i=0;
    
    while(bdVen[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD Notas
int len_Notas(notaEntrada *bdNotas){
    
    int i=0;
    
    while(bdNotas[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}

//função que retorna tamanho de BD compras
int len_Comp(compra *prod){
    
    int i=0;
    
    while(prod[i].cod!=-1){ //conta quantos loops até achar -1
        i++;
    }
    return i;
}