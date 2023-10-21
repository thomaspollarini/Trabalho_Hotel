/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "bancoDados.h"
#include "util.h"

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
                        free(bdCat);
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
                return 0; //sem erro
            break;
            
            case 0:
                system("clear");
                printf("|=====RESERVA CANCELADA=====|\n\n");
                return 1; //busca cancelada
            break;
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;   
        }
        
    }while(op!=0);
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
                printf("!===ARQUIVOS JÁ SÃO TIPO TEXTO===!\n\n");
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
    
    hotel bdHotel;                  //puxa todos bancos de dados
    dados_Hotel(&bdHotel);
    acomodacao *bdAco=dados_Acomodacoes(bdAco);
    categoria *bdCat=dados_Categorias(bdCat);
    fornecedor *bdFor=dados_Fornecedores(bdFor);
    hospede *bdHos=dados_Hospedes(bdHos);
    operador *bdOpe=dados_Operadores(bdOpe);
    produto *bdPro=dados_Produtos(bdPro);
    reserva *bdRes=dados_Reservas(bdRes);
    
    int lenAco=len_Aco(bdAco),lenCat=len_Cat(bdCat),lenFor=len_For(bdFor),lenHos=len_Hos(bdHos),
            lenOpe=len_Ope(bdOpe),lenPro=len_Pro(bdPro),lenRes=len_Res(bdRes); //seus tamanhos
    
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
        
        printf("!===ARQUIVOS CONVERTIDOS COM SUCESSO===!\n\n");
        free(bdHos);
        free(bdAco);
        free(bdCat);
        free(bdFor);
        free(bdOpe);
        free(bdPro);
        free(bdRes);
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