#include "bancoDados.h"
#include "service.h"
#include "util.h"

/*
 * 
 */

int main(int argc, char** argv) {
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");
    if(arq==NULL){
        arq=fopen(".//Bd//Binario.bin","rb");
        if(arq==NULL){
            tipo_Arquivo(); //cria verificador de tipo pela primeira vez
            fclose(arq);
        }
    }
    
    operador adm;  //armazena os dados do operador atual
    login(&adm);   //função que realiza login
    
    int op=1; //variavel usada para seleção dos menus
    
    while(op!=0){//cria loop para manter menu
        
        printf("|==========MENU DE MÓDULOS==========|\n"  //menu de módulos
               "|1 - Cadastros e Gestão de dados    |\n"
               "|2 - Reservas                       |\n"
               "|3 - Transações                     |\n"
               "|4 - Feedback                       |\n"
               "|5 - Importação/Exportação de dados |\n"
               "|6 - Trocar operador                |\n"
               "|0 - Finalizar programa             |\n"
               "|Digite uma opção para prosseguir: ");
        scanf("%d",&op);
        system("clear");                        //MENU DE MÓDULOS
        
        switch(op){
                        
            case 1:
                if(verifica_Acesso(adm,op)==1){ //verifica acesso do operador
                    while(op!=0){                            //menu de cadastro
                        printf("|=====CADASTROS E GESTÃO DE DADOS======|\n"
                               "|1 - Hotel                             |\n"
                               "|2 - Hóspedes                          |\n"
                               "|3 - Acomodações                       |\n"
                               "|4 - Categorias de acomodações         |\n"
                               "|5 - Produtos                          |\n"
                               "|6 - Fornecedores                      |\n"
                               "|7 - Operadores do sistema             |\n"
                               "|8 - Escolher tipo de arquivo          |\n"
                               "|0 - Voltar                            |\n"
                               "|Digite uma opção para prosseguir: ");
                        scanf("%d",&op);
                        system("clear"); 

                        switch (op){

                            case 1:

                                while(op!=0){        //menu hotel
                                    printf("|==============HOTEL=============|\n"
                                           "|1 - Recadastrar                 |\n"
                                           "|2 - Ver dados cadastrados       |\n"
                                           "|3 - Alterar cadastro            |\n"
                                           "|0 - Voltar                      |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch (op) {

                                        case 1:
                                            cadastrar_Hotel(); //função para cadastrar dados do hotel, 
                                        break;                 //substituirá todos dados do hotel

                                        case 2:
                                            ver_Hotel();    //função para ver dados do hotel
                                        break;

                                        case 3:
                                            editar_Hotel(); //função para editar dados do hotel
                                        break;

                                        case 0:
                                        break;

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
                                        break;
                                    }    
                                }

                                op=1;
                            break;    

                            case 2:

                                while(op!=0){        //menu hóspedes
                                    printf("|===========HÓSPEDES===========|\n"
                                           "|1 - Cadastrar                 |\n"
                                           "|2 - Editar                    |\n"
                                           "|3 - Excluir                   |\n"
                                           "|4 - Ver Dados Cadastrados     |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            cadastrar_Hospede();   //função para cadastrar novo hóspede
                                        break;

                                        case 2:
                                            editar_Hospede();     //função para editar dados de algum hóspede
                                        break;    

                                        case 3:
                                            excluir_Hospede();   //função para excluir dados de algum hóspede
                                        break;
                                        
                                        case 4:
                                            ver_Hospedes();  //função para mostrar dados cadastrados no sistema
                                        break;

                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\nn");
                                        break;   
                                    }
                                }    

                                op=1;
                            break;

                            case 3:

                                while(op!=0){           //menu acomodações
                                    printf("|===========ACOMODAÇÕES==========|\n"
                                           "|1 - Cadastrar                   |\n"
                                           "|2 - Editar                      |\n"
                                           "|3 - Excluir                     |\n"
                                           "|4 - Ver Dados Cadastrados       |\n"
                                           "|0 - Voltar                      |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");                

                                    switch(op){

                                        case 1:
                                            cadastrar_Acomodacao(); //função para cadastrar nova acomodação
                                        break;    

                                        case 2:
                                            editar_Acomodacao();  //função para alterar dados de alguma acomodação
                                        break;

                                        case 3:
                                            excluir_Acomodacao();  //função para excluir dados de alguma acomodação
                                        break;
                                        
                                        case 4:
                                            ver_Acomodacoes();  //função para mostrar dados cadastrados no sistema
                                        break;

                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
                                        break;
                                    }    
                                }

                                op=1;
                            break;

                            case 4:

                                while(op!=0){       //menu categorias
                                    printf("|=====CATEGORIAS DE ACOMODAÇÕES======|\n"
                                           "|1 - Cadastrar                       |\n"
                                           "|2 - Editar                          |\n"
                                           "|3 - Excluir                         |\n"
                                           "|4 - Ver Dados Cadastrados           |\n"
                                           "|0 - Voltar                          |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            cadastrar_Categoria();     //função para cadastrar nova categoria
                                        break;

                                        case 2:
                                            editar_Categoria();       //função para alterar dados de alguma categoria
                                        break;    

                                        case 3:
                                            excluir_Categoria();    //função para excluir dados de alguma categoria
                                        break;
                                        
                                        case 4:
                                            ver_Categorias();  //função para mostrar dados cadastrados no sistema
                                        break;

                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\nn");
                                        break;   
                                    }
                                }    

                                op=1;
                            break;

                            case 5:

                                while(op!=0){                                   //menu produtos
                                    printf("|===========PRODUTOS==========|\n"
                                           "|1 - Cadastrar                |\n"
                                           "|2 - Editar                   |\n"
                                           "|3 - Excluir                  |\n"
                                           "|4 - Ver Dados Cadastrados    |\n"
                                           "|0 - Voltar                   |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");                

                                    switch(op){

                                        case 1:
                                            cadastrar_Produto();    //função para cadastrar novo produto
                                        break;    

                                        case 2:
                                            editar_Produto();    //função para alterar dados de algum produto
                                        break;

                                        case 3:
                                            excluir_Produto();   //função para excluir dados de algum produto
                                        break;
                                        
                                        case 4:
                                            ver_Produtos();  //função para mostrar dados cadastrados no sistema
                                        break;

                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
                                        break;
                                    }    
                                }
                                op=1;
                            break;

                            case 6: 

                                while(op!=0){                              //menu fornecedores
                                    printf("|=========FORNECEDORES=========|\n"
                                           "|1 - Cadastrar                 |\n"
                                           "|2 - Editar                    |\n"
                                           "|3 - Excluir                   |\n"
                                           "|4 - Ver Dados Cadastrados     |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            cadastrar_Fornecedor();    //função para cadastrar novo fornecedor
                                        break;

                                        case 2:
                                            editar_Fornecedor();    //função para alterar dados de algum fornecedor
                                        break;    

                                        case 3:
                                            excluir_Fornecedor();       //função para alterar dados de algum fornecedor
                                        break;
                                        
                                        case 4:
                                            ver_Fornecedores();  //função para mostrar dados cadastrados no sistema
                                        break;

                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\nn");
                                        break;   
                                    }
                                }    

                                op=1;
                            break;

                            case 7:

                                while(op!=0){                                      // menu operadores
                                    printf("|=====OPERADORES DO SISTEMA======|\n"
                                           "|1 - Cadastrar                   |\n"
                                           "|2 - Editar                      |\n"
                                           "|3 - Excluir                     |\n"
                                           "|4 - Ver Dados Cadastrados       |\n"
                                           "|0 - Voltar                      |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            cadastrar_Operador(adm);        //função para cadastrar novo operador
                                        break;

                                        case 2:
                                            editar_Operador(adm);       //função para alterar dados de algum operador
                                        break;    

                                        case 3:
                                            excluir_Operador(&adm);     //função para alterar dados de algum operadoor
                                        break;
                                        
                                        case 4:
                                            ver_Operadores();  //função para mostrar dados cadastrados no sistema
                                        break;
                                            
                                        case 0:
                                        break;    

                                        default:
                                            printf("!==CARACTER INVÁLIDO==!\nn");
                                        break;   
                                    }
                                }    

                                op=1;
                            break;
                            
                            case 8:
                                tipo_Arquivo(); //função para mudar tipo de arquivo do sistema
                            break;    

                            case 0:
                            break; 

                            default:
                                printf("!==CARACTER INVÁLIDO==!\n\n");
                            break;
                        }
                    }
                    op=1;
                }else{
                    printf("!==USUÁRIO NÃO POSSUI ACESSO A ESTE MÓDULO==!\n");
                }
            break;
            
            case 2:
                if(verifica_Acesso(adm,op)==1){
                    while(op!=0){

                        printf("|==========RESERVAS==========|\n"
                               "|1 - Fazer reserva           |\n"
                               "|2 - Cancelar reserva        |\n"
                               "|3 - Ver Dados de Reservas   |\n"
                               "|0 - voltar                  |\n"
                               "|Digite uma opção para prosseguir: ");
                        scanf("%d",&op);
                        system("clear");

                        switch(op){

                            case 1:
                                cadastrar_Reserva();
                            break;

                            case 2:
                                excluir_Reserva();
                            break;
                            
                            case 3:
                                ver_Reservas();  //função para mostrar dados cadastrados no sistema
                            break;
                            
                            case 0:
                            break; 

                            default:
                                printf("!==CARACTER INVÁLIDO==!\n\n");
                            break;    

                        }
                    }
                    op=1;
                }else{
                    printf("!==USUÁRIO NÃO POSSUI ACESSO A ESTE MÓDULO==!\n");
                }
            break;
            
            case 3:
                if(verifica_Acesso(adm,op)==1){
                    
                }else{
                    printf("!==USUÁRIO NÃO POSSUI ACESSO A ESTE MÓDULO==!\n");
                }
            break;
            
            case 4:
                if(verifica_Acesso(adm,op)==1){
                    
                }else{
                    printf("!==USUÁRIO NÃO POSSUI ACESSO A ESTE MÓDULO==!\n");
                }
            break;
                
            case 5:
                if(verifica_Acesso(adm,op)==1){
                    
                }else{
                    printf("!==USUÁRIO NÃO POSSUI ACESSO A ESTE MÓDULO==!\n");
                }
            break;
            
            case 6:
                login(&adm);
            break;
            
            case 0:
            break;   
                
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    
    return (0);
}