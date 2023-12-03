#include "bancoDados.h"
#include "serviceCadastros.h"
#include "util.h"
#include "relatorio.h"

/* Integrantes: Thomas Santos Pollarini
 *              Jean Claudio Teixeira
 *              Ana Luiza Ramos
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
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
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
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
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
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
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
                                            printf("!==CARACTER INVÁLIDO==!\n\n");
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
                               "|0 - Voltar                  |\n"
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
                    while(op!=0){

                        printf("|==========TRANSAÇÕES==========|\n"
                               "|1 - CheckIn                   |\n"
                               "|2 - Fazer CheckOut            |\n"
                               "|3 - Saída de produtos         |\n"
                               "|4 - Entrada de produtos       |\n"
                               "|5 - Controle de caixa         |\n"
                               "|6 - Contas a Receber          |\n"
                               "|7 - Contas a Pagar            |\n"
                               "|0 - Voltar                    |\n"
                               "|Digite uma opção para prosseguir: ");
                        scanf("%d",&op);
                        system("clear");

                        switch(op){

                            case 1:
                                while(op!=0){                              //menu checkin
                                    printf("|============CHECKIN===========|\n"
                                           "|1 - Cadastrar                 |\n"
                                           "|2 - Ver Dados Cadastrados     |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            cadastrar_CheckIn();    //função para cadastrar novo checkin
                                        break;

                                        case 2:
                                            ver_CheckIn();    //função para mostrar dados cadastrados no sistema
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
                                fazer_CheckOut();  // função que realiza checkout
                            break;
                            
                            case 3:
                                cadastrar_Venda();  // função para vendas de produtos
                            break;
                            
                            case 4:
                                cadastrar_Compra(); //função para compra de produtos
                            break;

                            case 5:
                                while(op!=0){                              //menu checkin
                                    printf("|=============CAIXA============|\n"
                                           "|1 - Montante atual            |\n"
                                           "|2 - Ver Transações do caixa   |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            ver_Caixa();   //função para mostrar valor em caixa
                                        break;

                                        case 2: 
                                            ver_movCaixa();  //função para mostrar movimentação do caixa
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
                                while(op!=0){                              //menu checkin
                                    printf("|========CONTAS A RECEBER======|\n"
                                           "|1 - Dar Baixa em Nota         |\n"
                                           "|2 - Ver Notas Cadastradas     |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            receber_Nota();    //função para cadastrar novo checkin
                                        break;

                                        case 2:
                                            ver_ContasReceber();    //função para mostrar dados cadastrados no sistema
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
                            
                            case 7:
                                while(op!=0){                              //menu checkin
                                    printf("|========CONTAS A PAGAR======|\n"
                                           "|1 - Dar Baixa em Nota         |\n"
                                           "|2 - Ver Notas Cadastradas     |\n"
                                           "|0 - Voltar                    |\n"
                                           "|Digite uma opção para prosseguir: ");
                                    scanf("%d",&op);
                                    system("clear");

                                    switch(op){

                                        case 1:
                                            pagar_Nota();    //função para cadastrar novo checkin
                                        break;

                                        case 2:
                                            ver_ContasPagar();    //função para mostrar dados cadastrados no sistema
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
            
            case 4:
                if(verifica_Acesso(adm,op)==1){
                    while(op!=0){

                        printf("|================RELATÓRIOS==================|\n"
                               "|1  - Listagem de Hóspedes                   |\n"
                               "|2  - Listagem de Acomodações                |\n"
                               "|3  - Listagem de Reservas                   |\n"
                               "|4  - Listagem de Movimento de Acomodações   |\n"
                               "|5  - Listagem de Produtos de Consumo        |\n"
                               "|6  - Listagem de Produtos em Estoque Mínimo |\n"
                               "|7  - Listagem de Vendas                     |\n"
                               "|8  - Listagem de Contas a Receber           |\n"
                               "|9  - Listagem de Contas a Pagar             |\n"
                               "|10 - Listagem de Movimentação de Caixa      |\n"
                               "|0  - Voltar                                 |\n"
                               "|Digite uma opção para prosseguir: ");
                        scanf("%d",&op);
                        system("clear");

                        switch(op){

                            case 1:
                                lista_Hospedes();  //função para realizar relatorio do hospede
                            break;
                            
                            case 2:
                                lista_Acomodacoes(); //função para realizar relatorio das acomodações
                            break;
                            
                            case 3:
                                lista_Reservas();   //função para realizar relatorio das reservas
                            break;
                            
                            case 4:
                                lista_movAcomodacoes(); //função para realizar relatorio do movimento das acomodações
                            break;
                            
                            case 5:
                                lista_Produtos();   //função para realizar relatorio dos produtos
                            break;
                            
                            case 6:
                                lista_EstoqueMin(); //função para realizar relatorio dos produtos em estoque minimo
                            break;
                            
                            case 7:
                                lista_Vendas();     //função para realizar relatorio das vendas
                            break;
                            
                            case 8:
                                lista_ContasReceber(); //função para realizar relatorio das contas a receber
                            break;
                            
                            case 9:
                                lista_ContasPagar();    //função para realizar relatorio das contas a pagar
                            break;
                            
                            case 10:
                                lista_movCaixa();       //função para realizar relatorio do movimento do caixa
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
                
            case 5:
                if(verifica_Acesso(adm,op)==1){
                    while(op!=0){    
                        printf("|===IMPORTAÇÃO/EXPORTAÇÃO DE DADOS===|\n"
                           "|1 - Importar Dados                  |\n"
                           "|2 - Exportar Dados                  |\n"
                           "|0 - Voltar                          |\n"
                           "|Digite uma opção para prosseguir: ");
                        scanf("%d",&op);
                        system("clear");

                        switch(op){

                            case 1:
                            case 2:
                                menu_Tabelas(op);
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