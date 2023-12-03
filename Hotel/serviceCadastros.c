/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bancoDados.h"
#include "util.h"
#include "serviceCadastros.h"
#include "serviceTransacoes.h"

//função para cadastrar novo operador
void cadastrar_Operador(operador adm){
    
    operador *bdOpe=dados_Operadores(bdOpe); //carrega Banco de dados
    int lenOpe=len_Ope(bdOpe); //tamanho do BD
    
    int i,op=1;
    operador novo; //cria variavel para novo operador
    
    printf("|==DIGITE OS DADOS DO NOVO OPERADOR==|\n");
    
    do{
        printf("Digite o código da conta: ");     //coleta dados
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DA CONTA DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdOpe[i].cod!=novo.cod && i<lenOpe){ //passa por todo BD, se encontrar código igual quebra o loop
            i++;
        }
        
        if(i!=lenOpe){     //se i diferente do valor total loop foi quebrado
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdOpe);
                return;
            }
        }
    }while(i!=lenOpe);
    
    setbuf(stdin, NULL);
    printf("Digite o nome do operador: ");   //coleta dados
    scanf("%[^\n]s",novo.nome);
    
    do{
        setbuf(stdin, NULL);
        printf("Digite o nome do usuário: ");
        scanf("%[^\n]s",novo.usuario);              //ALGORITMO PARA VERIFICAR NOME DE USUÁRIO
                                                                //IMPOSSIBILITA REPETIÇÃO DE NOMES
        i=0;                                                    
        while(strcmp(novo.usuario,bdOpe[i].usuario)!=0 && i<lenOpe){  //passa por todo BD, se encontrar usuário igual quebra o loop
            i++;
        }
        if(i!=lenOpe){     //se i diferente do valor total loop foi quebrado
            printf("!===USUÁRIO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdOpe);
                return;
            }                   
        }
    }while(i!=lenOpe);
    
    setbuf(stdin, NULL);
    printf("Digite a senha: ");    //coleta dados
    scanf("%[^\n]s",novo.senha);
    system("clear");
    
    for(i=0;i<5;i++){
        novo.acesso[i]=0;  //inicializa vetor de acesso
    }
    
    free(bdOpe);  //libera BD
    
    menu_Acesso(adm,&novo);   //função para administrar acesso do operador
    cadastrar_OperadorBD(novo); //função para salvar no arquivo
    return;
}

//função para editar operadores
void editar_Operador(operador adm){
    
    operador *bdOpe=dados_Operadores(bdOpe);  //carrega BD
    int lenOpe=len_Ope(bdOpe); //tamanho do BD
    
    int i,j,op=1,cod;
    
    
    do{
        printf("Digite o código da conta: ");
        scanf("%d",&cod);
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA CÓDIGO NO BD
        while(bdOpe[i].cod!=cod && i<lenOpe){ //se achar código quebra o loop, i será a coordenada do operador no BD
            i++;
        }
        
        if(i==lenOpe){  //se i igual tamanho o código não está no BD  
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdOpe);
                return;
            }
            
        }
    }while(i==lenOpe);
    
    if(adm.cod==cod){ //Se estiver editando a conta do operador atual será possivel alterar todos dados da conta
        do{
            printf("|====DADOS DA CONTA====|\n" //menu de alteração
               "|1-Nome: %s\n"
               "|2-Usuário: %s\n"
               "|3-Senha: %s\n"
               "|4-Continuar\n"
               "|0-Cancelar\n"
               "|Digite a opção que deseja alterar:  ",bdOpe[i].nome,bdOpe[i].usuario,bdOpe[i].senha);
            scanf("%d",&op);

            switch (op){ //loop que permite alteração de todos os dados, e confirmação para alteração

                case 1:
                    setbuf(stdin, NULL);
                    printf("Digite o nome do operador: "); //altera nome
                    scanf("%[^\n]s",bdOpe[i].nome);
                    system("clear");
                break;

                case 2:
                    int usuario[50];  //altera usuario
                    do{
                        setbuf(stdin, NULL);
                        printf("Digite o nome do usuário: ");
                        scanf("%[^\n]s",usuario);                       //ALGORITMO PARA VERIFICAR NOME DE USUÁRIO
                                                                        //IMPOSSIBILITA REPETIÇÃO DE NOMES
                        j=0;                                                    
                        while(strcmp(usuario,bdOpe[j].usuario)!=0 && j<lenOpe){
                            j++;
                        }
                        if(j!=lenOpe){    
                            printf("!===USUÁRIO JÁ ESTÁ EM USO===!\n\n"
                                   "Digite 0 para cancelar a edição:  ");
                            scanf("%d",&op);
                            system("clear"); 
                            if(op==0){
                                printf("!===EDIÇÃO CANCELADA===!\n\n");
                                free(bdOpe);
                                return;
                            }                   
                        }
                    }while(j!=lenOpe);
                    
                    strcpy(bdOpe[i].usuario,usuario);
                    
                    system("clear");
                break;

                case 3:
                    setbuf(stdin, NULL);          //altera senha
                    printf("Digite a senha: ");
                    scanf("%[^\n]s",bdOpe[i].senha);
                    system("clear");
                break;
                
                case 4:
                    system("clear");
                    atualizar_OperadorBD(bdOpe,lenOpe);  //chama função para salvar alterações no arquivo
                    free(bdOpe);
                    return;
                break;
                    
                case 0:
                    system("clear"); 
                    printf("!===EDIÇÃO CANCELADA===!\n\n");
                    free(bdOpe);
                    return;
                break;

                default:
                    printf("!==CARACTER INVÁLIDO==!\n\n");
                break;
            }
        }while(op!=0);
    
    }else{ //caso operador esteja editando outra conta só poderá editar as permissões de acesso
        
        int sup=0;
        
        printf("|====DADOS DA CONTA====|\n"  //mostra dados da conta, esconde a senha
           "|Nome: %s\n"
           "|Usuário: %s\n"
           "|Senha: ",bdOpe[i].nome,bdOpe[i].usuario);
         
        for(j=0;j<strlen(bdOpe[i].senha);j++){
            printf("*");
        }
        
        printf("\n|Acesso: ");  //mostra permissõeos de acesso, verifica se operador atual é superior a conta
        for(j=0;j<5;j++){                                 //caso seja superior pode mudar permissões de acesso
            printf("%d",bdOpe[i].acesso[j]);              // SUPERIOR: ter mais acesso e ter acesso a todos os módulos que a outra conta 
            if(sup!=-1 && adm.acesso[j]!=bdOpe[i].acesso[j]){   //contas com mesmo acesso não podem se alterar
                if(adm.acesso[j]==1){                           //EX: 10011 pode alterar 10001, 11110 não pode alterar 10001
                    sup=1;
                }else{
                    sup=-1;
                }
            }
        }
        
        if(sup==1){          //se superior chama função de acesso
            printf("\n");
            menu_Acesso(adm,&bdOpe[i]);
            
            system("clear");
            atualizar_OperadorBD(bdOpe,lenOpe);
            free(bdOpe);
        }else{
            printf("\n|=====VOCÊ NÃO TEM PERMISSÃO PARA ALTERAR ESTA CONTA===|\nDigite 0 para continuar:  ");
            scanf("%d",&op);
            
            free(bdOpe);
            system("clear");
            return;
        }
    }
}

//função para excluir operadores
void excluir_Operador(operador *adm){
    
    operador *bdOpe=dados_Operadores(bdOpe); //carrega BD
    int lenOpe=len_Ope(bdOpe); //tamanho BD
    
    int i,j,op=1,cod;
    
    
    do{
        printf("Digite o código da conta: ");
        scanf("%d",&cod);
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdOpe[i].cod!=cod && i<lenOpe){
            i++;
        }
        
        if(i==lenOpe){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdOpe);
                return;
            }
            
        }
    }while(i==lenOpe);
    
    system("clear");
    
    int sup=0;
        
    printf("|====DADOS DA CONTA====|\n"  //Mostra dados
           "|Nome: %s\n"
           "|Usuário: %s\n"
           "|Senha: ",bdOpe[i].nome,bdOpe[i].usuario);
         
    for(j=0;j<strlen(bdOpe[i].senha);j++){
        printf("*");
    }
        
    printf("\n|Acesso: ");
    for(j=0;j<5;j++){
        printf("%d",bdOpe[i].acesso[j]);
        if(sup!=-1 && adm->acesso[j]!=bdOpe[i].acesso[j]){ 
            if(adm->acesso[j]==1){
                sup=1;
            }else{
                sup=-1;
            }
        }
    }
    
    if(sup==1 || adm->cod==cod){        //se superior ou dono da conta pode excluir
        printf("\n|1 - Apagar conta\n"
               "|0 - Cancelar\nDigite uma opção: ");
        scanf("%d",&op);
            
        if(op==1){
        
            system("clear");
        
            lenOpe--;

            if(lenOpe==0){  //caso seja a última conta apaga o arquivo diretamente
                
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//Operadores.txt");
                }else{
                    result = remove(".//Bd//Operadores.bin");
                }

                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdOpe);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdOpe);
                    login(adm);  //força login para criar um novo arquivo e uma conta adm
                    return;     //usuario pode cancelar login
                }
            }

            for(j=i;j<lenOpe;j++){   //move dados para direita apagando operador selecionado
                bdOpe[j].cod=bdOpe[j+1].cod;
                strcpy(bdOpe[j].nome,bdOpe[j+1].nome);
                strcpy(bdOpe[j].usuario,bdOpe[j+1].usuario);
                strcpy(bdOpe[j].senha,bdOpe[j+1].senha);

                for(int k=0;k<5;k++){
                    bdOpe[j].acesso[k]=bdOpe[j+1].acesso[k];
                }
            }

            atualizar_OperadorBD(bdOpe,lenOpe); //salva dados no arquivo
            free(bdOpe);

            if(adm->cod==cod){
                login(adm); //caso operador atual seja o apagado força login de um novo operador
            }

            return;
        }
        
        system("clear");
        free(bdOpe);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
        
    }else{
        printf("\n|=====VOCÊ NÃO TEM PERMISSÃO PARA EXCLUIR ESTA CONTA===|\nDigite 0 para continuar:  ");
        scanf("%d",&op);
            
        free(bdOpe);
        system("clear");
        return;
    }
}

//função para vizualizar dados de operadores
void ver_Operadores(){
    operador *bdOpe=dados_Operadores(bdOpe); //carrega Banco de dados
    int lenOpe=len_Ope(bdOpe); //tamanho do BD
    int i,op;
    for(i=0;i<lenOpe;i++){
        printf("|Código: %d\n|Nome: %s\n|Usuário: %s\n|Acesso: %d%d%d%d%d"
               "\n______________________________\n\n"
                ,bdOpe[i].cod,bdOpe[i].nome,bdOpe[i].usuario
                ,bdOpe[i].acesso[0],bdOpe[i].acesso[1],bdOpe[i].acesso[2],bdOpe[i].acesso[3],bdOpe[i].acesso[4]);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar dados do hotel
void cadastrar_Hotel(){
    
    hotel bdHotel;
    
    printf("PREENCHA OS DADOS DO HOTEL:\n");
    setbuf(stdin, NULL);
    printf("Nome:");
    scanf("%[^\n]s",bdHotel.nome);
                                                        //ALGORIMO PARA FAZER FICHA DO HOTEL
    setbuf(stdin, NULL);
    printf("Razão Social:");
    scanf("%[^\n]s",bdHotel.razaoSocial);

    
    printf("Inscrição Estadual (digite apenas números):");
    scanf("%d",&bdHotel.inscEstadual);

    setbuf(stdin, NULL);
    printf("CNPJ (digite apenas números):");
    scanf("%[^\n]s",bdHotel.cnpj);
  
    setbuf(stdin, NULL);
    printf("Endereço Completo:\nRua: ");
    scanf("%[^\n]s",bdHotel.end.rua);
    
    printf("Número: ");
    scanf("%d",&bdHotel.end.num);
    
    setbuf(stdin, NULL);
    printf("Complemento: ");
    scanf("%[^\n]s",bdHotel.end.comp);
    setbuf(stdin, NULL);
    printf("Bairro: ");
    scanf("%[^\n]s",bdHotel.end.bairro);
    setbuf(stdin, NULL);
    printf("Cidade: ");
    scanf("%[^\n]s",bdHotel.end.cidade);
    setbuf(stdin, NULL);
    printf("Estado: ");
    scanf("%[^\n]s",bdHotel.end.estado);

    setbuf(stdin, NULL);
    printf("Telefone:");
    scanf("%[^\n]s",bdHotel.telefone);

    setbuf(stdin, NULL);
    printf("E-mail:");
    scanf("%[^\n]s",bdHotel.email);

    setbuf(stdin, NULL);
    printf("Nome do responsável:");
    scanf("%[^\n]s",bdHotel.nomeResp);

    setbuf(stdin, NULL);
    printf("Telefone do responsável:");
    scanf("%[^\n]s",bdHotel.telefoneResp);
    
    printf("Horário de Check-out(formato 24h):");
    scanf("%d",&bdHotel.horaCheckout);
    
    do{
        printf("Horário de Check-in(formato 24h):");
        scanf("%d",&bdHotel.horaCheckin);
    }while(bdHotel.horaCheckin<bdHotel.horaCheckout);
        
    printf("Margem de lucro dos produtos vendidos(em porcentagem):");
    scanf("%f",&bdHotel.margem);
    system("clear");
    printf("|===FICHA CRIADA COM SUCESSO===|\n\n");
    
    cadastrar_HotelBD(bdHotel); //chama função para salvar dados no arquivo
}

//função para editar dados do hotel
void editar_Hotel(){
    
    int op;
    hotel bdHotel;
    
    dados_Hotel(&bdHotel); // carrega BD
    
    do{
        printf("|==========DADOS HOTEL=========|\n"
           "|1 - Nome: %s\n|2 - Telefone: %s\n|3 - Email: %s\n|4 - Nome Responsavel: %s\n"
           "|5 - Telefone Responsavel: %s\n|6 - Endereço: %s,%d (%s) - %s, %s - %s\n"
           "|7 - Hora do CheckIn: %dh\n|8 - Hora do checkOut: %dh\n|9 - Margem de Lucro: %.2f%%\n"
           "|10 - Inscrição Estadual: %d\n|11 - Razão Social: %s\n|12 - CNPJ: %s\n|13 - Continuar\n"
           "|0 - Cancelar\n|Digite uma opção: ",bdHotel.nome,bdHotel.telefone,bdHotel.email,bdHotel.nomeResp,bdHotel.telefoneResp
        ,bdHotel.end.rua,bdHotel.end.num,bdHotel.end.comp,bdHotel.end.bairro,bdHotel.end.cidade,bdHotel.end.estado
        ,bdHotel.horaCheckin,bdHotel.horaCheckout,bdHotel.margem
        ,bdHotel.inscEstadual,bdHotel.razaoSocial,bdHotel.cnpj);
        scanf("%d",&op);
        
        
        switch (op){
            case 1:
                setbuf(stdin, NULL);
                printf("\nNome: ");
                scanf("%[^\n]s",bdHotel.nome);
                system("clear");
            break;
        
            case 2:
                setbuf(stdin, NULL);
                printf("\nTelefone: ");
                scanf("%[^\n]s",bdHotel.telefone);
                system("clear");
            break;
    
            case 3:
                setbuf(stdin, NULL);
                printf("\nEmail: ");
                scanf("%[^\n]s",bdHotel.email);
                system("clear");
            break;
    
            case 4:
                setbuf(stdin, NULL);
                printf("\nNome do Responsável: ");
                scanf("%[^\n]s",bdHotel.nomeResp);
                system("clear");
            break;
    
            case 5:
                setbuf(stdin, NULL);
                printf("\nTelefone do Responsável: ");
                scanf("%[^\n]s",bdHotel.telefoneResp);
                system("clear");
            break;
    
            case 6:
                setbuf(stdin, NULL);
                printf("\nEndereço Completo:\nRua: ");
                scanf("%[^\n]s",bdHotel.end.rua);
                printf("Número: ");
                scanf("%d",&bdHotel.end.num);
                setbuf(stdin, NULL);
                printf("Complemento: ");
                scanf("%[^\n]s",bdHotel.end.comp);
                setbuf(stdin, NULL);
                printf("Bairro: ");
                scanf("%[^\n]s",bdHotel.end.bairro);
                setbuf(stdin, NULL);
                printf("Cidade: ");
                scanf("%[^\n]s",bdHotel.end.cidade);
                setbuf(stdin, NULL);
                printf("Estado: ");
                scanf("%[^\n]s",bdHotel.end.estado);
                system("clear");
            break;
    
            case 7:
                do{
                    printf("\nHora do CheckIn: ");
                    scanf("%d",&bdHotel.horaCheckin);
                }while(bdHotel.horaCheckin<bdHotel.horaCheckout);
                system("clear");
            break;
    
            case 8:
                do{
                    printf("\nHora do CheckOut: ");
                    scanf("%d",&bdHotel.horaCheckout);
                }while(bdHotel.horaCheckin<bdHotel.horaCheckout);
                system("clear");
            break;
    
            case 9:
                printf("\nMargem de Lucro: ");
                scanf("%f",&bdHotel.margem);
                system("clear");
            break;
    
            case 10:
                printf("\nInscrição Estadual: ");
                scanf("%d",&bdHotel.inscEstadual);
                system("clear");
            break;
    
            case 11:
                setbuf(stdin, NULL);
                printf("\nRazão Social: ");
                scanf("%[^\n]s",bdHotel.razaoSocial);
                system("clear");
            break;
        
            case 12:
                setbuf(stdin, NULL);
                printf("\nCNPJ: ");
                scanf("%[^\n]s",bdHotel.cnpj);
                system("clear");
            break;
            
            case 13:
                cadastrar_HotelBD(bdHotel); //função para salvar no arquivo
                return;
            case 0:
                system("clear");
                return;
            break;
            
            default:
                printf("\n!==CARACTER INVÁLIDO==!\n");
            break;
        }
        
    }while(op!=13);
    
}

//função para vizualizar dados do hotel
void ver_Hotel(){
    
    int op;
    hotel bdHotel;
    
    dados_Hotel(&bdHotel); //carrega banco de dados
    
    printf("|==========DADOS HOTEL=========|\n"
           "|Nome: %s\n|Telefone: %s\n|Email: %s\n|Nome Responsavel: %s\n"
           "|Telefone Responsavel: %s\n|Endereço: %s,%d (%s) - %s, %s - %s\n"
           "|Hora do CheckIn: %d\n|Hora do checkOut: %d\n|Margem de Lucro: %.2f\n"
           "|Inscrição Estadual: %d\n|Razão Social: %s\n|CNPJ: %s\nDigite 0 para continuar: "
    ,bdHotel.nome,bdHotel.telefone,bdHotel.email,bdHotel.nomeResp,bdHotel.telefoneResp
    ,bdHotel.end.rua,bdHotel.end.num,bdHotel.end.comp,bdHotel.end.bairro,bdHotel.end.cidade,bdHotel.end.estado
    ,bdHotel.horaCheckin,bdHotel.horaCheckout,bdHotel.margem
    ,bdHotel.inscEstadual,bdHotel.razaoSocial,bdHotel.cnpj);  //mostra dados
    
    scanf("%d",&op);
    system("clear");
    return;
}

//função para cadastrar novo hóspede
void cadastrar_Hospede(){
    
    hospede *bdHos=dados_Hospedes(bdHos); //carrega BD
    int lenHos=len_Hos(bdHos); //tamanho BD
    
    int i,op=1;
    hospede novo; //variavel para novo hospede
    
    printf("|==DIGITE OS DADOS DO NOVO HÓSPEDE==|\n");
    
    do{
        printf("Digite o código do hóspede: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DO HÓSPEDE DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdHos[i].cod!=novo.cod && i<lenHos){
            i++;
        }
        
        if(i!=lenHos){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdHos);
                return;
            }
        }
    }while(i!=lenHos);
    
    setbuf(stdin, NULL);
    printf("Digite o nome: ");
    scanf("%[^\n]s",&novo.nome);
    
    setbuf(stdin, NULL);
    printf("Endereço Completo:\nRua: ");
    scanf("%[^\n]s",&novo.end.rua);
    printf("Número: ");
    scanf("%d",&novo.end.num);
    setbuf(stdin, NULL);
    printf("Complemento: ");
    scanf("%[^\n]s",&novo.end.comp);
    setbuf(stdin, NULL);
    printf("Bairro: ");
    scanf("%[^\n]s",&novo.end.bairro);
    setbuf(stdin, NULL);
    printf("Cidade: ");
    scanf("%[^\n]s",&novo.end.cidade);
    setbuf(stdin, NULL);
    printf("Estado: ");
    scanf("%[^\n]s",&novo.end.estado);
    
    setbuf(stdin, NULL);
    printf("Digite o CPF: ");
    scanf("%[^\n]s",&novo.cpf);
    
    setbuf(stdin, NULL);
    printf("Digite o telefone: ");
    scanf("%[^\n]s",&novo.telefone);
    
    setbuf(stdin, NULL);
    printf("Digite o e-mail: ");
    scanf("%[^\n]s",&novo.email);
    
    setbuf(stdin, NULL);
    printf("Digite o gênero: ");
    scanf("%[^\n]s",&novo.sexo);
    
    setbuf(stdin, NULL);
    printf("Digite o Estado Civil: ");
    scanf("%[^\n]s",&novo.civil);
   
    setbuf(stdin, NULL);
    printf("Digite a data de nascimento(dd/mm/aaaa):");
    scanf("%[^\n]s",&novo.nasc);
    
    free(bdHos);
    cadastrar_HospedeBD(novo); //função para salvar dados no arquivo

    return;
}

//função para editar hóspedes
void editar_Hospede(){
    
    hospede *bdHos=dados_Hospedes(bdHos); //carrega BD
    int lenHos=len_Hos(bdHos); //tamanho BD
    
    if(lenHos==0){
        printf("!===NENHUM HÓSPEDE CADASTRADO===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    
    do{
        printf("Digite o código do hóspede: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGO
        while(bdHos[i].cod!=cod && i<lenHos){
            i++;
        }
        
        if(i==lenHos){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdHos);
                return;
            }
            
        }
    }while(i==lenHos);
    
    op=1;
    while(op!=0){ //menu de dados
        printf("|====DADOS DO HÓSPEDE====|\n1 - Nome: %s\n2 - Endereço: %s, %d - %s, %s, %s-%s\n3 - CPF: %s\n"
                "4 - Telefone: %s\n5 - E-mail: %s\n6 - Gênero: %s\n7 - Estado Civil: %s\n8 - Data de nascimento: %s\n9 - Continuar\n"
               "0 - Cancelar\n\n!==DADOS DIGITADOS ANTERIORMENTE SERÃO SOBSCRITOS==!\n\nDigite a opção que deseja alterar: "
               ,bdHos[i].nome,bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp,bdHos[i].end.bairro,bdHos[i].end.cidade,bdHos[i].end.estado
               ,bdHos[i].cpf,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc);
        scanf("%d",&op);
        system("clear");
        
        switch(op){        
                    
            case 1:
                setbuf(stdin, NULL);
                printf("Nome: ");
                scanf("%[^\n]s",&bdHos[i].nome);
                system("clear");
            break;
                            
            case 2:
                setbuf(stdin, NULL);
                printf("Endereço Completo:\nRua: ");
                scanf("%[^\n]s",&bdHos[i].end.rua);
                printf("Número: ");
                scanf("%d",&bdHos[i].end.num);
                setbuf(stdin, NULL);
                printf("Complemento: ");
                scanf("%[^\n]s",&bdHos[i].end.comp);
                setbuf(stdin, NULL);
                printf("Bairro: ");
                scanf("%[^\n]s",&bdHos[i].end.bairro);
                setbuf(stdin, NULL);
                printf("Cidade: ");
                scanf("%[^\n]s",&bdHos[i].end.cidade);
                setbuf(stdin, NULL);
                printf("Estado: ");
                scanf("%[^\n]s",&bdHos[i].end.estado);
                system("clear");  
            break;
                            
            case 3:
                setbuf(stdin, NULL);
                printf("CPF: ");
                scanf("%[^\n]s",&bdHos[i].cpf);
                system("clear");    
            break;
            
            case 4:
                setbuf(stdin, NULL);
                printf("Telefone: ");
                scanf("%[^\n]s",&bdHos[i].telefone);
                system("clear");    
            break;    
            
            case 5:
                setbuf(stdin, NULL);
                printf("E-mail: ");
                scanf("%[^\n]s",&bdHos[i].email);
                system("clear");
            break;
            
            case 6:
                setbuf(stdin, NULL);
                printf("Gênero: ");
                scanf("%[^\n]s",&bdHos[i].sexo);
                system("clear");
            break;
            
            case 7:
                setbuf(stdin, NULL);
                printf("Estado Civil: ");
                scanf("%[^\n]s",&bdHos[i].civil);
                system("clear");
            break;
            
            case 8: 
                setbuf(stdin, NULL);
                printf("Data de nascimento(dd/mm/aaaa): ");
                scanf("%[^\n]s",&bdHos[i].nasc);
                system("clear");
            break;
            
            case 9:
                system("clear");
                atualizar_HospedeBD(bdHos,lenHos);  //função para salvar dados no arquivo
                free(bdHos);
                return;
            break;
            
            case 0:
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdHos);
                return;
            break;    
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    return;
}

//função para excluir hóspedes
void excluir_Hospede(){
    
    hospede *bdHos=dados_Hospedes(bdHos); //carrega BD
    int lenHos=len_Hos(bdHos);  //tamnho BD
    
    int i,j,op=1,cod;
    
    if(lenHos==0){
        printf("!===NENHUM HÓSPEDE CADASTRADO===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código do hóspede: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGO
        while(bdHos[i].cod!=cod && i<lenHos){
            i++;
        }
        
        if(i==lenHos){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdHos);
                return;
            }
            
        }
    }while(i==lenHos);
    
    system("clear");
    
    op=1;
    while(op!=0){ //mostra dados da conta
        printf("|====DADOS DO HÓSPEDE====|\nNome: %s\nEndereço: %s, %d - %s, %s, %s-%s\nCPF: %s\n"
                "Telefone: %s\nE-mail: %s\nGênero: %s\nEstado Civil: %s\nData de nascimento: %s\n"
                "|1 - Apagar hóspede\n|0 - Cancelar\nDigite uma opção: "
               ,bdHos[i].nome,bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp,bdHos[i].end.bairro,bdHos[i].end.cidade,bdHos[i].end.estado
               ,bdHos[i].cpf,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
        
            system("clear");
        
            lenHos--;

            if(lenHos==0){ //remove arquivo direto caso seja o último
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//Hospedes.txt");
                }else{
                    result = remove(".//Bd//Hospedes.bin");
                }
                
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdHos);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdHos);
                    inicializa_Arquivos(); //cria arquivo novo
                    return;
                }
            }

            for(j=i;j<lenHos;j++){ //move dados pra esquerda
                bdHos[j].cod=bdHos[j+1].cod;
                strcpy(bdHos[j].nome,bdHos[j+1].nome);
                strcpy(bdHos[j].cpf,bdHos[j+1].cpf);
                strcpy(bdHos[j].telefone,bdHos[j+1].telefone);
                strcpy(bdHos[j].email,bdHos[j+1].email);
                strcpy(bdHos[j].sexo,bdHos[j+1].sexo);
                strcpy(bdHos[j].civil,bdHos[j+1].civil);
                strcpy(bdHos[j].nasc,bdHos[j+1].nasc);
                strcpy(bdHos[j].end.rua,bdHos[j+1].end.rua);
                bdHos[j].end.num=bdHos[j+1].end.num;
                strcpy(bdHos[j].end.comp,bdHos[j+1].end.comp);
                strcpy(bdHos[j].end.bairro,bdHos[j+1].end.bairro);
                strcpy(bdHos[j].end.cidade,bdHos[j+1].end.cidade);
                strcpy(bdHos[j].end.estado,bdHos[j+1].end.estado);
            }

            atualizar_HospedeBD(bdHos,lenHos); //salva alteração no arquivo
            free(bdHos);

            return;
        }
        
        system("clear");
        free(bdHos);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados de Hóspedes
void ver_Hospedes(){
    hospede *bdHos=dados_Hospedes(bdHos); //carrega Banco de dados
    int lenHos=len_Hos(bdHos); //tamanho do BD
    
    if(lenHos==0){
        printf("!===NENHUM HÓSPEDE CADASTRADO===!\n\n");
        return;
    }
    
    int i,op;
    
    for(i=0;i<lenHos;i++){
        printf("|Código: %d\n|Nome: %s\n|Endereço: %s, %d - %s, %s, %s-%s\n|CPF: %s\n"
                "|Telefone: %s\n|E-mail: %s\n|Gênero: %s\n|Estado Civil: %s\n|Data de Nascimento: %s"
                "\n__________________________________\n\n"
               ,bdHos[i].cod,bdHos[i].nome,bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp,bdHos[i].end.bairro
               ,bdHos[i].end.cidade,bdHos[i].end.estado,bdHos[i].cpf,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar novo categoria
void cadastrar_Categoria(){
    
    categoria *bdCat=dados_Categorias(bdCat); //carrega BD
    int lenCat=len_Cat(bdCat); //tamanho
    
    int i,op=1;
    categoria novo;
    
    printf("|==DIGITE OS DADOS DA NOVA CATEGORIA==|\n");
    
    do{
        printf("Digite o código da categoria: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DA CATEGORIA DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdCat[i].cod!=novo.cod && i<lenCat){
            i++;
        }
        
        if(i!=lenCat){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdCat);
                return;
            }
        }
    }while(i!=lenCat);
    
    setbuf(stdin, NULL);
    printf("Digite a descrição: ");
    scanf("%[^\n]s",&novo.desc);
    
    printf("Digite o valor da categoria: ");
    scanf("%f",&novo.vlr);
    printf("Digite a quantidade de adultos da categoria: ");
    scanf("%d",&novo.adulto);
    printf("Digite a quantidade de crianças da categoria: ");
    scanf("%d",&novo.crianca);
    
    free(bdCat);
    cadastrar_CategoriaBD(novo);  //salva dados no arquivo

    return;
}

//função para editar categorias
void editar_Categoria(){
    
    categoria *bdCat=dados_Categorias(bdCat); //Carrega BD
    int lenCat=len_Cat(bdCat);
    
    if(lenCat==0){
        printf("!===NENHUMA CATEGORIA CADASTRADA===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    do{
        printf("Digite o código da categoria: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGO
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGO
        while(bdCat[i].cod!=cod && i<lenCat){
            i++;
        }
        
        if(i==lenCat){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdCat);
                return;
            }
            
        }
    }while(i==lenCat);
    
    op=1;
    while(op!=0){  //menu de dados
        printf("|====DADOS DA CATEGORIA====|\n1 - Descrição: %s\n2 - Valor: %.2f\n3 - Nº Adultos: %d\n4 - Nº Crianças: %d\n"
               "5 - Continuar\n0 - Cancelar\n\n!==DADOS DIGITADOS ANTERIORMENTE SERÃO SOBSCRITOS==!\n\nDigite a opção que deseja alterar: "
               ,bdCat[i].desc,bdCat[i].vlr,bdCat[i].adulto,bdCat[i].crianca);
        scanf("%d",&op);
        system("clear");
        
        switch(op){        
                    
            case 1:
                setbuf(stdin, NULL);
                printf("Descrição: ");
                scanf("%[^\n]s",&bdCat[i].desc);
                system("clear");
            break;
                            
            case 2:
                printf("Valor: ");
                scanf("%f",&bdCat[i].vlr);
                system("clear");  
            break;
                            
            case 3:
                printf("Nº Adultos: ");
                scanf("%d",&bdCat[i].adulto);
                system("clear");    
            break;
            
            case 4:
                printf("Nº Crianças: ");
                scanf("%d",&bdCat[i].crianca);
                system("clear");  
            break;    
            
            case 5:
                system("clear");
                atualizar_CategoriaBD(bdCat,lenCat); //salva dados no arquivo
                free(bdCat);
                return;
            break;
            
            case 0:
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdCat);
                return;
            break;    
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    return;
}

//função para excluir categorias
void excluir_Categoria(){
    
    categoria *bdCat=dados_Categorias(bdCat); //carrega BD
    int lenCat=len_Cat(bdCat);
    
    int i,j,op=1,cod;
    
    if(lenCat==0){
        printf("!===NENHUMA CATEGORIA CADASTRADA===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código da categoria: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdCat[i].cod!=cod && i<lenCat){
            i++;
        }
        
        if(i==lenCat){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdCat);
                return;
            }
            
        }
    }while(i==lenCat);
    
    system("clear");
    
    op=1;
    while(op!=0){ //menu de dados
       printf("|====DADOS DA CATEGORIA====|\nDescrição: %s\nValor: %.2f\nNº Adultos: %d\nNº Crianças: %d\n"
               "|1 - Apagar categoria\n|0 - Cancelar\nDigite uma opção: "
               ,bdCat[i].desc,bdCat[i].vlr,bdCat[i].adulto,bdCat[i].crianca);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
        
            system("clear");
            
            acomodacao *bdAco=dados_Acomodacoes(bdAco);  //carrega bd de acomodações
            int lenAco=len_Aco(bdAco);
            
            if(lenAco!=0){ //se alguma acomodação criada
                if(lenCat==1){ //cancela processo por causa da dependencia da última categoria
                    printf("!===NÃO É POSSÍVEL EXCLUIR A ÚLTIMA CATEGORIA COM ACOMODAÇÕES CADASTRADAS===!\n\n");
                    free(bdCat);
                    printf("|====EXCLUSÃO CANCELADA====|\n\n");
                    return;
                }
                
                int cont=0;
                for(j=0;j<lenAco;j++){
                    if(bdAco[j].cat==bdCat[i].cod){
                        cont++;
                    } //verifica se tem alguma acomodação relacionada a categoria que será excluída
                }
                if(cont!=0){  //operador decide se vai mudar as relações ou cancelar exclusão
                    printf("!====%d ACOMODAÇÕES ESTÃO ASSOCIADAS COM ESSA CATEGORIA====!\n\n"
                            "|1 - Selecionar nova categoria para as acomodações\n|0 - Cancelar\n"
                            "Digite uma opção: ",cont);
                    scanf("%d",&op);

                    if(op==1){
                        do{
                            printf("Digite o código da categoria: ");
                            scanf("%d",&cod);                                   
                                                                                //ALGORITMO PARA VALIDAR CÓDIGOS
                            j=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
                            while((bdCat[i].cod==cod || bdCat[j].cod!=cod) && j<lenCat){
                                j++;
                            }

                            if(j==lenCat){     
                                printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                                       "Digite 0 para cancelar procura:  ");
                                scanf("%d",&op);
                                system("clear"); 

                                if(op==0){
                                    printf("!===EXCLUSÃO CANCELADA===!\n\n");
                                    free(bdCat);
                                    return;
                                }

                            }
                        }while(j==lenCat);

                        for(j=0;j<lenAco;j++){    //altera codigo das categorias nas acomodações
                            if(bdAco[j].cat==bdCat[i].cod){
                                bdAco[j].cat=cod;
                            }
                        }

                        atualizar_AcomodacaoBD(bdAco,lenAco); //salva alteração das acomodações no arquivo
                        free(bdAco);
                    }else{
                        system("clear");
                        free(bdCat);
                        printf("|====EXCLUSÃO CANCELADA====|\n\n");
                        return;
                    }
                }    
            }
        
            lenCat--;

            if(lenCat==0){ //caso seja a última categora remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");
                                        //verifica tipo de arquivo
                if(arq!=NULL){  
                    fclose(arq);
                    result = remove(".//Bd//Categorias.txt");
                }else{
                    result = remove(".//Bd//Categorias.bin");
                }

                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdCat);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdCat);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }

            for(j=i;j<lenCat;j++){  //move dados pra esquerda
                bdCat[j].cod=bdCat[j+1].cod;
                strcpy(bdCat[j].desc,bdCat[j+1].desc);
                bdCat[j].vlr=bdCat[j+1].vlr;
                bdCat[j].adulto=bdCat[j+1].adulto;
                bdCat[j].crianca=bdCat[j+1].crianca;
            }

            atualizar_CategoriaBD(bdCat,lenCat);  //atualiza dados nos arquivos
            free(bdCat);

            return;
        }
        
        system("clear");
        free(bdCat);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados da categoria
void ver_Categorias(){
    categoria *bdCat=dados_Categorias(bdCat); //carrega Banco de dados
    int lenCat=len_Cat(bdCat); //tamanho do BD
    
    if(lenCat==0){
        printf("!===NENHUMA CATEGORIA CADASTRADA===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenCat;i++){
        printf("|Código: %d\n|Descrição: %s\n|Valor: %.2f\n|Nº Adultos: %d\n|Nº Crianças: %d"
               "\n__________________________________\n\n"
               ,bdCat[i].cod,bdCat[i].desc,bdCat[i].vlr,bdCat[i].adulto,bdCat[i].crianca);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar novo acomodação
void cadastrar_Acomodacao(){
    
    categoria *bdCat=dados_Categorias(bdCat); //carrega BD categorias
    int lenCat=len_Cat(bdCat);
    
    if(lenCat==0){ //se nenhuma categoria criada não é possivel criar acomodação
        printf("!===NENHUMA CATEGORIA CADASTRADA===!\n\n");
        return;
    }
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco);  //carrega BD acomodações
    int lenAco=len_Aco(bdAco);
    
    int i,op=1;
    acomodacao novo;
    
    printf("|==DIGITE OS DADOS DA NOVA ACOMODAÇÃO==|\n");
    
    do{
        printf("Digite o código da acomodação: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DA ACOMODAÇÃO DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdAco[i].cod!=novo.cod && i<lenAco){
            i++;
        }
        
        if(i!=lenAco){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdAco);
                free(bdCat);
                return;
            }
        }
    }while(i!=lenAco);
    
    setbuf(stdin, NULL);
    printf("Digite a descrição: ");
    scanf("%[^\n]s",&novo.desc);
    
    setbuf(stdin, NULL);
    printf("Digite as facilidades: ");
    scanf("%[^\n]s",&novo.fac);
    
    do{
        printf("Digite o código da categoria: ");
        scanf("%d",&novo.cat);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS DA CATEGORIA
        while(bdCat[i].cod!=novo.cat && i<lenCat){
            i++;
        }
        
        if(i==lenCat){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADA===!\n\n");
                free(bdAco);
                free(bdCat);
                return;
            }
            
        }
    }while(i==lenCat);
    
    free(bdAco);
    free(bdCat);
    cadastrar_AcomodacaoBD(novo); //salva dados no arquivo

    return;
}

//função para editar acomodações
void editar_Acomodacao(){
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco); //carrega BD 
    int lenAco=len_Aco(bdAco);
    
    if(lenAco==0){
        printf("!===NENHUMA ACOMODAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    do{
        printf("Digite o código da categoria: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdAco[i].cod!=cod && i<lenAco){
            i++;
        }
        
        if(i==lenAco){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdAco);
                return;
            }
            
        }
    }while(i==lenAco);
    
    op=1;
    while(op!=0){ //MENU de DADOS
        printf("|====DADOS DA ACOMODAÇÃO====|\n1 - Descrição: %s\n2 - Facilidades: %s\n3 - Categoria: %d\n"
               "4 - Continuar\n0 - Cancelar\n\n!==DADOS DIGITADOS ANTERIORMENTE SERÃO SOBSCRITOS==!\n\nDigite a opção que deseja alterar: "
               ,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
        scanf("%d",&op);
        system("clear");
        
        switch(op){        
                    
            case 1:
                setbuf(stdin, NULL);
                printf("Descrição: ");
                scanf("%[^\n]s",&bdAco[i].desc);
                system("clear");
            break;
                            
            case 2:
                setbuf(stdin, NULL);
                printf("Facilidades: ");
                scanf("%[^\n]s",&bdAco[i].fac);
                system("clear");  
            break;
                            
            case 3:
                categoria *bdCat=dados_Categorias(bdCat); //carrega BD de categoria para verificar novo código
                int lenCat=len_Cat(bdCat),j=0;
                 
                do{
                    printf("Digite o código da categoria: ");
                    scanf("%d",&cod);                                   
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
                            printf("!===EDIÇÃO CANCELADA===!\n\n");
                            free(bdCat);
                            op=1;
                            break;
                        }

                    }else{
                        free(bdCat);
                        bdAco[i].cat=cod;
                    }
                }while(j==lenCat);
            break;
            
            case 4:
                system("clear");
                atualizar_AcomodacaoBD(bdAco,lenAco); //salva dados no arquivo
                free(bdAco);
                return;
            break;
            
            case 0:
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdAco);
                return;
            break;    
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    return;
}

//função para excluir acomodações
void excluir_Acomodacao(){
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco); //carrega BD
    int lenAco=len_Aco(bdAco);
    
    int i,j,op=1,cod;
    
    if(lenAco==0){
        printf("!===NENHUMA ACOMODAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código da acomodação: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdAco[i].cod!=cod && i<lenAco){
            i++;
        }
        
        if(i==lenAco){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdAco);
                return;
            }
            
        }
    }while(i==lenAco);
    
    system("clear");
    
    op=1;
    while(op!=0){ //Dados
      printf("|====DADOS DA ACOMODAÇÃO====|\nDescrição: %s\nFacilidades: %s\nCategoria: %d\n"
               "|1 - Apagar acomodação\n|0 - Cancelar\nDigite uma opção: "
               ,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
        
            system("clear");
        
            lenAco--;

            if(lenAco==0){ //se última, remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//Acomodacoes.txt");
                }else{
                    result = remove(".//Bd//Acomodacoes.bin");
                }
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdAco);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdAco);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }

            for(j=i;j<lenAco;j++){ //move dados a esquerda
                bdAco[j].cod=bdAco[j+1].cod;
                strcpy(bdAco[j].desc,bdAco[j+1].desc);
                strcpy(bdAco[j].fac,bdAco[j+1].fac);
                bdAco[j].cat=bdAco[j+1].cat;
            }

            atualizar_AcomodacaoBD(bdAco,lenAco); //salva alteração no arquivo
            free(bdAco);

            return;
        }
        
        system("clear");
        free(bdAco);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados das acomodações
void ver_Acomodacoes(){
    acomodacao *bdAco=dados_Acomodacoes(bdAco); //carrega Banco de dados
    int lenAco=len_Aco(bdAco); //tamanho do BD
    
    if(lenAco==0){
        printf("!===NENHUMA ACOMODAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenAco;i++){
        printf("|Código: %d\n|Descrição: %s\n|Facilidades: %s\n|Categoria: %d"
               "\n__________________________________\n\n"
               ,bdAco[i].cod,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar novo produto
void cadastrar_Produto(){
    
    produto *bdPro=dados_Produtos(bdPro); //carrega BD
    int lenPro=len_Pro(bdPro);
    
    int i,op=1;
    produto novo;
    
    printf("|==DIGITE OS DADOS DO NOVO PRODUTO==|\n");
    
    do{
        printf("Digite o código do produto: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DO PRODUTO DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdPro[i].cod!=novo.cod && i<lenPro){
            i++;
        }
        
        if(i!=lenPro){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdPro);
                return;
            }
        }
    }while(i!=lenPro);
    
    setbuf(stdin, NULL);
    printf("Digite a descrição: ");
    scanf("%[^\n]s",&novo.desc);
    
    printf("Digite o estoque mínimo do produto: ");
    scanf("%d",&novo.estmin);
    
    do{
        printf("Digite o estoque atual do produto: ");
        scanf("%d",&novo.est);
        
        if(novo.est<novo.estmin){   //Não permite cadastrar estoque menor que o mínimo
            printf("!===ESTOQUE ABAIXO DO ESTOQUE MÍNIMO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdPro);
                return;
            }
        }
    }while(novo.est<novo.estmin);
        
    printf("Digite o preço de custo produto: ");
    scanf("%f",&novo.custo);
    
    printf("Digite o preço de venda do produto: ");
    scanf("%f",&novo.venda);
    
    free(bdPro);
    cadastrar_ProdutoBD(novo);

    return;
}

//função para editar produtos
void editar_Produto(){
    
    produto *bdPro=dados_Produtos(bdPro); //carrega BD
    int lenPro=len_Pro(bdPro);
    
    if(lenPro==0){
        printf("!===NENHUM PRODUTO CADASTRADO===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    do{
        printf("Digite o código do produto: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdPro[i].cod!=cod && i<lenPro){
            i++;
        }
        
        if(i==lenPro){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdPro);
                return;
            }
            
        }
    }while(i==lenPro);
    
    int est;
    op=1;
    while(op!=0){ //DADOS
        printf("|====DADOS DO PRODUTO====|\n1 - Descrição: %s\n2 - Estoque mínimo: %d\n3 - Estoque atual: %d\n"
                "4 - Preço de Custo: %.2f\n5 - Preço de Venda: %.2f\n6 - Continuar\n0 - Cancelar\n\n"
                "!==DADOS DIGITADOS ANTERIORMENTE SERÃO SOBSCRITOS==!\n\nDigite a opção que deseja alterar: "
               ,bdPro[i].desc,bdPro[i].estmin,bdPro[i].est,bdPro[i].custo,bdPro[i].venda);
        scanf("%d",&op);
        system("clear");
        
        switch(op){        
                    
            case 1:
                setbuf(stdin, NULL);
                printf("Descrição: ");
                scanf("%[^\n]s",&bdPro[i].desc);
                system("clear");
            break;
                            
            case 2:
                printf("Estoque mínimo: ");
                scanf("%d",&est);
                
                system("clear");
                
                if(est>bdPro[i].est){  //Não permite estoque min maior q o atual
                    printf("!===ERRO: Estoque mínimo maior que estoque atual===!\n\n");
                }else{
                    bdPro[i].estmin=est;
                }
            break;
                            
            case 3:
                printf("Estoque atual: ");
                scanf("%d",&est);
                
                system("clear");
                
                if(est<bdPro[i].estmin){ //Não permite estoque atual menor q o min
                    printf("!===ERRO: Estoque mínimo maior que estoque atual===!\n\n");
                }else{
                    bdPro[i].est=est;
                }
            break;
            
            case 4:
                printf("Preço de Custo: ");
                scanf("%f",&bdPro[i].custo);
                system("clear");  
            break;    
            
            case 5:
                printf("Preço de Venda: ");
                scanf("%f",&bdPro[i].venda);
                system("clear");  
            break;
            
            case 6:
                system("clear");
                atualizar_ProdutoBD(bdPro,lenPro); //salva dados no arquivo
                free(bdPro);
                return;
            break;
            
            case 0:
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdPro);
                return;
            break;    
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    return;
}

//função para excluir produtos
void excluir_Produto(){
    
    produto *bdPro=dados_Produtos(bdPro); //carrega BD
    int lenPro=len_Pro(bdPro);
    
    int i,j,op=1,cod;
    
    if(lenPro==0){
        printf("!===NENHUM PRODUTO CADASTRADO===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código do produto: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdPro[i].cod!=cod && i<lenPro){
            i++;
        }
        
        if(i==lenPro){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdPro);
                return;
            }
            
        }
    }while(i==lenPro);
    
    system("clear");
    
    op=1;
    while(op!=0){   //DADOS
        printf("|====DADOS DO PRODUTO====|\nDescrição: %s\nEstoque mínimo: %d\nEstoque atual: %d\n"
                "Preço de Custo: %.2f\nPreço de Venda: %.2f\n|1 - Apagar produto\n|0 - Cancelar\nDigite uma opção: "
               ,bdPro[i].desc,bdPro[i].estmin,bdPro[i].est,bdPro[i].custo,bdPro[i].venda);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
        
            system("clear");
        
            lenPro--;

            if(lenPro==0){ //se último, remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");
                                            //verifica tipo de arquivo
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//Produtos.txt");
                }else{
                    result = remove(".//Bd//Produtos.bin");
                }
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdPro);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdPro);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }

            for(j=i;j<lenPro;j++){  //move dados para esquerda
                bdPro[j].cod=bdPro[j+1].cod;
                strcpy(bdPro[j].desc,bdPro[j+1].desc);
                bdPro[j].estmin=bdPro[j+1].estmin;
                bdPro[j].est=bdPro[j+1].est;
                bdPro[j].custo=bdPro[j+1].custo;
                bdPro[j].venda=bdPro[j+1].venda;
            }

            atualizar_ProdutoBD(bdPro,lenPro); //salva dados no arquivo
            free(bdPro);

            return;
        }
        
        system("clear");
        free(bdPro);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados dos produtos
void ver_Produtos(){
    produto *bdPro=dados_Produtos(bdPro); //carrega Banco de dados
    int lenPro=len_Pro(bdPro); //tamanho do BD
    
    if(lenPro==0){
        printf("!===NENHUM PRODUTO CADASTRADO===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenPro;i++){
        printf("|Código: %d\n|Descrição: %s\n|Estoque mínimo: %d\n|Estoque atual: %d\n"
                "|Preço de Custo: %.2f\n|Preço de Venda: %.2f\n__________________________________\n\n"
               ,bdPro[i].cod,bdPro[i].desc,bdPro[i].estmin,bdPro[i].est,bdPro[i].custo,bdPro[i].venda);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar novo fornecedor
void cadastrar_Fornecedor(){
    
    fornecedor *bdFor=dados_Fornecedores(bdFor);//carrega BD
    int lenFor=len_For(bdFor);
    
    int i,op=1;
    fornecedor novo;
    
    printf("|==DIGITE OS DADOS DO NOVO FORNECEDOR==|\n");
    
    do{
        printf("Digite o código do fornecedor: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DO FORNECEDOR DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdFor[i].cod!=novo.cod && i<lenFor){
            i++;
        }
        
        if(i!=lenFor){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdFor);
                return;
            }
        }
    }while(i!=lenFor);
    
    setbuf(stdin, NULL);
    printf("Digite o nome: ");
    scanf("%[^\n]s",&novo.nome);
    
    setbuf(stdin, NULL);
    printf("Endereço Completo:\nRua: ");
    scanf("%[^\n]s",&novo.end.rua);
    printf("Número: ");
    scanf("%d",&novo.end.num);
    setbuf(stdin, NULL);
    printf("Complemento: ");
    scanf("%[^\n]s",&novo.end.comp);
    setbuf(stdin, NULL);
    printf("Bairro: ");
    scanf("%[^\n]s",&novo.end.bairro);
    setbuf(stdin, NULL);
    printf("Cidade: ");
    scanf("%[^\n]s",&novo.end.cidade);
    setbuf(stdin, NULL);
    printf("Estado: ");
    scanf("%[^\n]s",&novo.end.estado);
    
    setbuf(stdin, NULL);
    printf("Digite o CNPJ: ");
    scanf("%[^\n]s",&novo.cnpj);
    
    setbuf(stdin, NULL);
    printf("Digite o telefone: ");
    scanf("%[^\n]s",&novo.telefone);
    
    setbuf(stdin, NULL);
    printf("Digite o e-mail: ");
    scanf("%[^\n]s",&novo.email);
    
    setbuf(stdin, NULL);
    printf("Digite a razão social: ");
    scanf("%[^\n]s",&novo.razaoSocial);
    
    printf("Digite a Inscrição Estadual: ");
    scanf("%d",&novo.inscEstadual);
    
    free(bdFor);
    cadastrar_FornecedorBD(novo); //salva dados no arquivo

    return;
}

//função para editar fornecedores
void editar_Fornecedor(){
    
    fornecedor *bdFor=dados_Fornecedores(bdFor); //carrega BD
    int lenFor=len_For(bdFor);
    
    if(lenFor==0){
        printf("!===NENHUM FORNECEDOR CADASTRADO===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    do{
        printf("Digite o código do fornecedor: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdFor[i].cod!=cod && i<lenFor){
            i++;
        }
        
        if(i==lenFor){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdFor);
                return;
            }
            
        }
    }while(i==lenFor);
    
    op=1;
    while(op!=0){ //DADOS
        printf("|====DADOS DO FORNECEDOR====|\n1 - Nome: %s\n2 - Endereço: %s, %d - %s, %s, %s-%s\n3 - CNPJ: %s\n"
                "4 - Telefone: %s\n5 - E-mail: %s\n6 - Razão Social: %s\n7 - Inscrição Estadual: %d\n8 - Continuar\n"
               "0 - Cancelar\n\n!==DADOS DIGITADOS ANTERIORMENTE SERÃO SOBSCRITOS==!\n\nDigite a opção que deseja alterar: "
               ,bdFor[i].nome,bdFor[i].end.rua,bdFor[i].end.num,bdFor[i].end.comp,bdFor[i].end.bairro,bdFor[i].end.cidade,bdFor[i].end.estado
               ,bdFor[i].cnpj,bdFor[i].telefone,bdFor[i].email,bdFor[i].razaoSocial,bdFor[i].inscEstadual);
        scanf("%d",&op);
        system("clear");
        
        switch(op){        
                    
            case 1:
                setbuf(stdin, NULL);
                printf("Nome: ");
                scanf("%[^\n]s",&bdFor[i].nome);
                system("clear");
            break;
                            
            case 2:
                setbuf(stdin, NULL);
                printf("Endereço Completo:\nRua: ");
                scanf("%[^\n]s",&bdFor[i].end.rua);
                printf("Número: ");
                scanf("%d",&bdFor[i].end.num);
                setbuf(stdin, NULL);
                printf("Complemento: ");
                scanf("%[^\n]s",&bdFor[i].end.comp);
                setbuf(stdin, NULL);
                printf("Bairro: ");
                scanf("%[^\n]s",&bdFor[i].end.bairro);
                setbuf(stdin, NULL);
                printf("Cidade: ");
                scanf("%[^\n]s",&bdFor[i].end.cidade);
                setbuf(stdin, NULL);
                printf("Estado: ");
                scanf("%[^\n]s",&bdFor[i].end.estado);
                system("clear");  
            break;
                            
            case 3:
                setbuf(stdin, NULL);
                printf("CNPJ: ");
                scanf("%[^\n]s",&bdFor[i].cnpj);
                system("clear");    
            break;
            
            case 4:
                setbuf(stdin, NULL);
                printf("Telefone: ");
                scanf("%[^\n]s",&bdFor[i].telefone);
                system("clear");    
            break;    
            
            case 5:
                setbuf(stdin, NULL);
                printf("E-mail: ");
                scanf("%[^\n]s",&bdFor[i].email);
                system("clear");
            break;
            
            case 6:
                setbuf(stdin, NULL);
                printf("Razão social: ");
                scanf("%[^\n]s",&bdFor[i].razaoSocial);
                system("clear");
            break;
            
            case 7:
                printf("Inscrição Estadual: ");
                scanf("%d",&bdFor[i].inscEstadual);
                system("clear");
            break;
            
            case 8: 
                system("clear");
                atualizar_FornecedorBD(bdFor,lenFor);  //salva dados no arquivo
                free(bdFor);
                return;
            break;
            
            case 0:
                printf("!===EDIÇÃO CANCELADA===!\n\n");
                free(bdFor);
                return;
            break;    
            
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
    return;
}

//função para excluir fornecedores
void excluir_Fornecedor(){
    
    fornecedor *bdFor=dados_Fornecedores(bdFor); //carrega BD
    int lenFor=len_For(bdFor);
    
    int i,j,op=1,cod;
    
    if(lenFor==0){
        printf("!===NENHUM FORNECEDOR CADASTRADO===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código do fornecedor: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdFor[i].cod!=cod && i<lenFor){
            i++;
        }
        
        if(i==lenFor){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdFor);
                return;
            }
            
        }
    }while(i==lenFor);
    
    system("clear");
    
    op=1;
    while(op!=0){  //dados
        printf("|====DADOS DO FORNECEDOR====|\nNome: %s\nEndereço: %s, %d - %s, %s, %s-%s\nCNPJ: %s\n"
                "Telefone: %s\nE-mail: %s\nRazão Social: %s\nInscrição Estadual: %d\n"
                "|1 - Apagar fornecedor\n|0 - Cancelar\nDigite uma opção: "
               ,bdFor[i].nome,bdFor[i].end.rua,bdFor[i].end.num,bdFor[i].end.comp,bdFor[i].end.bairro,bdFor[i].end.cidade,bdFor[i].end.estado
               ,bdFor[i].cnpj,bdFor[i].telefone,bdFor[i].email,bdFor[i].razaoSocial,bdFor[i].inscEstadual);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
        
            system("clear");
        
            lenFor--;

            if(lenFor==0){ //se último, remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//Fornecedores.txt");
                }else{
                    result = remove(".//Bd//Fornecedores.bin");
                }
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdFor);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdFor);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }

            for(j=i;j<lenFor;j++){  //move dados a esquerda
                bdFor[j].cod=bdFor[j+1].cod;
                strcpy(bdFor[j].nome,bdFor[j+1].nome);
                strcpy(bdFor[j].cnpj,bdFor[j+1].cnpj);
                strcpy(bdFor[j].telefone,bdFor[j+1].telefone);
                strcpy(bdFor[j].email,bdFor[j+1].email);
                strcpy(bdFor[j].razaoSocial,bdFor[j+1].razaoSocial);
                bdFor[j].inscEstadual=bdFor[j+1].inscEstadual;
                strcpy(bdFor[j].end.rua,bdFor[j+1].end.rua);
                bdFor[j].end.num=bdFor[j+1].end.num;
                strcpy(bdFor[j].end.comp,bdFor[j+1].end.comp);
                strcpy(bdFor[j].end.bairro,bdFor[j+1].end.bairro);
                strcpy(bdFor[j].end.cidade,bdFor[j+1].end.cidade);
                strcpy(bdFor[j].end.estado,bdFor[j+1].end.estado);
            }

            atualizar_FornecedorBD(bdFor,lenFor); //salva no arquivo
            free(bdFor);

            return;
        }
        
        system("clear");
        free(bdFor);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados dos fornecedores
void ver_Fornecedores(){
    fornecedor *bdFor=dados_Fornecedores(bdFor); //carrega Banco de dados
    int lenFor=len_For(bdFor); //tamanho do BD
    
    if(lenFor==0){
        printf("!===NENHUM FORNECEDOR CADASTRADO===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenFor;i++){
        printf("|Código: %d\n|Nome: %s\n|Endereço: %s, %d - %s, %s, %s-%s\n|CNPJ: %s\n"
                "|Telefone: %s\n|E-mail: %s\n|Razão Social: %s\n|Inscrição Estadual: %d"
                "\n__________________________________\n\n"
               ,bdFor[i].cod,bdFor[i].nome,bdFor[i].end.rua,bdFor[i].end.num,bdFor[i].end.comp,bdFor[i].end.bairro,bdFor[i].end.cidade,bdFor[i].end.estado
               ,bdFor[i].cnpj,bdFor[i].telefone,bdFor[i].email,bdFor[i].razaoSocial,bdFor[i].inscEstadual);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para cadastrar nova reserva
void cadastrar_Reserva(){
    
    acomodacao *bdAco=dados_Acomodacoes(bdAco);  //carrega BD acomodações
    int lenAco=len_Aco(bdAco);
    
    if(lenAco==0){
        printf("!===NENHUMA ACOMODAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    hospede *bdHos=dados_Hospedes(bdHos);  //carrega BD acomodações
    int lenHos=len_Hos(bdHos);
    
    if(lenHos==0){
        printf("!===NENHUM HÓSPEDE CADASTRADO===!\n\n");
        return;
    }
    
    reserva novo; 
    int i,op;
    
    do{
        printf("Digite o código do hóspede: ");
        scanf("%d",&novo.codHos);
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdHos[i].cod!=novo.codHos && i<lenHos){
            i++;
        }
        
        if(i==lenHos){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===RESERVA CANCELADA===!\n\n");
                free(bdHos);
                free(bdAco);
                return;
            }
            
        }
    }while(i==lenHos);
    
    reserva *bdRes=dados_Reservas(bdRes); //carrega Banco de dados de reservas
    int lenRes=len_Res(bdRes); //tamanho do BD
    
    do{
        printf("Digite o código da reserva: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DA RESERVA DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdRes[i].cod!=novo.cod && i<lenRes){
            i++;
        }
        
        if(i!=lenRes){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdHos);
                free(bdAco);
                free(bdRes);
                return;
            }
        }
    }while(i!=lenRes);
    
    pesquisa busca;//variavel que armazenará dados de filtro para reserva
    int status=filtro_Reserva(&busca); //função para coletar filtro
    if(status==1){//se retorno == 1 cancela reserva
        free(bdHos);
        free(bdAco);
        free(bdRes);
        return;
    }
    int j,dataI_Res,dataF_Res,dataI_busca,dataF_busca,cont=0,*vet;
    
    vet=calloc(1,sizeof(int)); //inicializa vetor para armazenar quartos disponiveis
    
    dataI_busca= busca.data_pes.ano_i*10000+busca.data_pes.mes_i*100+busca.data_pes.dia_i;   //transforma data em inteiro para comparar maior
    dataF_busca= busca.data_pes.ano_f*10000+busca.data_pes.mes_f*100+busca.data_pes.dia_f;
    
    categoria *bdCat=dados_Categorias(bdCat); //carrega BD
    int lenCat=len_Cat(bdCat); //tamanho
    
    for(i=0;i<lenAco;i++){
        if(strcmp(busca.fac,"")!=0 && strcmp(busca.fac,bdAco[i].fac)!=0){ //se filtro ativo, e acomodação não for valida, pula ciclo
            continue;
        }
        if(busca.cat!=-1 && bdAco[i].cat!=bdCat[busca.cat].cod){  //se filtro ativo, e categoria não for valida, pula ciclo
            continue;
        }
        if(busca.adulto!=-1){  //se filtro ativo
            j=0;
            while(j<lenCat && bdAco[i].cat != bdCat[j].cod){   //acha categoria relacionada a acomodação
                j++;
            }
            
            if(busca.adulto!=bdCat[j].adulto){  //e numero de adultos da categoria não for válido, pula ciclo
                continue;
            }
        }
        if(busca.crianca!=-1){  //se filtro ativo
            j=0;
            while(j<lenCat && bdAco[i].cat != bdCat[j].cod){  //acha categoria relacionada a acomodação
                j++;
            }
            if(j!=lenCat && busca.crianca!=bdCat[j].crianca){  //e numero de crianças da categoria não for válido, pula ciclo
                continue;
            }
        }
        
        for(j=0;j<lenRes;j++){  //verifica reservas do quarto atual, se data for sobreposta, pula ciclo
            if(bdRes[j].quarto==bdAco[i].cod){
                dataI_Res= bdRes[j].periodo.ano_i*10000+bdRes[j].periodo.mes_i*100+bdRes[j].periodo.dia_i;   //transforma data em inteiro para comparar maior
                dataF_Res= bdRes[j].periodo.ano_f*10000+bdRes[j].periodo.mes_f*100+bdRes[j].periodo.dia_f;
                
                if((dataI_busca>=dataI_Res && dataI_busca<dataF_Res) || (dataF_busca>dataI_Res && dataF_busca<=dataF_Res)){
                    break;
                }
            }
        }
        
        if(j!=lenRes){
            continue;
        }
        
        printf("|Código: %d\n|Descrição: %s\n|Facilidades: %s\n|Categoria: %d"
               "\n__________________________________\n\n"
               ,bdAco[i].cod,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);
        cont++;
        
        vet=realloc(vet,cont*sizeof(int));
        vet[cont-1]=bdAco[i].cod;   //armazena código de quartos disponiveis
    }
    
    if(cont==0){
        system("clear");
        printf("!===NENHUMA ACOMODAÇÃO DISPONIVEL PARA ESTES FILTROS===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código da acomodação que deseja reservar (-1 para cancelar reserva):");
        scanf("%d",&op);
        
        if(op==-1){
            system("clear");
            printf("!====RESERVA CANCELADA====!\n\n");
            free(bdHos);
            free(bdAco);
            free(bdRes);
            return;
        }
        
        for(i=0;i<cont;i++){
            if(op==vet[i]){      //verifica qual quarto a pessoa escolheu
                novo.quarto=vet[i];
                novo.periodo=busca.data_pes;
                cadastrar_ReservaBD(novo);
                free(bdHos);
                free(bdAco);
                free(bdRes);
                return;
            }
        }
        
        system("clear");
        printf("!===ERRO QUARTO NÃO DISPONÍVEL===!\n\n");
    }while(1);
}

//função para excluir reserva
void excluir_Reserva(){
    
    reserva *bdRes=dados_Reservas(bdRes); //carrega BD
    int lenRes=len_Res(bdRes);
    
    int i,op=1,cod;
    
    if(lenRes==0){
        printf("!===NENHUMA RESERVA CADASTRADA===!\n\n");
        return;
    }
    
    do{
        printf("Digite o código da reserva: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdRes[i].cod!=cod && i<lenRes){
            i++;
        }
        
        if(i==lenRes){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===EXCLUSÃO CANCELADA===!\n\n");
                free(bdRes);
                return;
            }
            
        }
    }while(i==lenRes);
    
    system("clear");
    
    op=1;
    while(op!=0){ //Dados
      printf("|====DADOS DA RESERVA====|\nQuarto: %d\nCódigo Hóspede: %d\nData: %d/%d/%d - %d/%d/%d\n"
               "|1 - Apagar reserva\n|0 - Cancelar\nDigite uma opção: "
               ,bdRes[i].quarto,bdRes[i].codHos,bdRes[i].periodo.dia_i,bdRes[i].periodo.mes_i,bdRes[i].periodo.ano_i
              ,bdRes[i].periodo.dia_f,bdRes[i].periodo.mes_f,bdRes[i].periodo.ano_f);
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
            remove_DadosReserva(bdRes,lenRes,i);
            return;
        }
        
        system("clear");
        free(bdRes);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

void remove_DadosReserva(reserva *bdRes,int lenRes, int i){
    lenRes--;

    if(lenRes==0){ //se última, remove arquivo
        int result;
        FILE *arq=fopen(".//Bd//Texto.txt","r");
                
        if(arq!=NULL){    //verifica tipo de arquivo
            fclose(arq);
            result = remove(".//Bd//Reservas.txt");
        }else{
            result = remove(".//Bd//Reservas.bin");
        }
        if(result!=0){
            printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
            free(bdRes);
            return;
        }else{
            printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
            free(bdRes);
            inicializa_Arquivos(); //recria
            return;
        }
    }

    for(int j=i;j<lenRes;j++){ //move dados a esquerda
        bdRes[j].cod=bdRes[j+1].cod;
        bdRes[j].quarto=bdRes[j+1].quarto;
        bdRes[j].codHos=bdRes[j+1].codHos;
        bdRes[j].periodo.dia_i=bdRes[j+1].periodo.dia_i;
        bdRes[j].periodo.mes_i=bdRes[j+1].periodo.mes_i;
        bdRes[j].periodo.ano_i=bdRes[j+1].periodo.ano_i;
        bdRes[j].periodo.dia_f=bdRes[j+1].periodo.dia_f;
        bdRes[j].periodo.mes_f=bdRes[j+1].periodo.mes_f;
        bdRes[j].periodo.ano_f=bdRes[j+1].periodo.ano_f;                
    }

    atualizar_ReservaBD(bdRes,lenRes); //salva alteração no arquivo
    free(bdRes);
}

//função para vizualizar dados dos reservas
void ver_Reservas(){
    reserva *bdRes=dados_Reservas(bdRes); //carrega Banco de dados
    int lenRes=len_Res(bdRes); //tamanho do BD
    
    if(lenRes==0){
        printf("!===NENHUMA RESERVA CADASTRADA===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenRes;i++){//mostra dados
        printf("|Código: %d\n|Quarto: %d\n|Código Hóspede: %d\n|Data CheckIn: %d/%d/%d\n|Data CheckOut:  %d/%d/%d\n"
                "\n__________________________________\n\n",bdRes[i].cod,bdRes[i].quarto,bdRes[i].codHos,bdRes[i].periodo.dia_i
                ,bdRes[i].periodo.mes_i,bdRes[i].periodo.ano_i,bdRes[i].periodo.dia_f,bdRes[i].periodo.mes_f,bdRes[i].periodo.ano_f);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

////função para cadastrar nova reserva
void cadastrar_CheckIn(){
    
    reserva *bdRes=dados_Reservas(bdRes); //carrega Banco de dados de reservas
    int lenRes=len_Res(bdRes),i,j,op,verf; //tamanho do BD
    
    if(lenRes==0){
        printf("!===NENHUMA RESERVA CADASTRADA===!\n\n");
        return;
    }
    
    checkin *bdCIn=dados_CheckIn(bdCIn),novo;  //carrega Banco de dados de checkin
    int lenCIn=len_CIn(bdCIn); //tamanho do BD 
    
    do{
        printf("Digite o código da reserva: ");
        scanf("%d",&novo.reserva);
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdRes[i].cod!=novo.reserva && i<lenRes){
            i++;
        }
        
        if(i==lenRes){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CHECKIN CANCELADO===!\n\n");
                free(bdRes);
                free(bdCIn);
                return;
            }
            continue;
        }
        
        j=0;
        while(bdCIn[j].reserva!=novo.reserva && j<lenCIn){    //ALGORITMO PARA VALIDAR CÓDIGOS LIVRES
            j++;
        }
        
        if(j!=lenCIn){
            printf("!===CHECKIN PARA ESTÁ RESERVA JÁ FOI REALIZADO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdCIn);
                free(bdRes);
                return;
            }
            i=lenRes; //muda valor de i para continuar no loop
            continue;
        }
        
        printf("Digite o código do hóspede que realizou a reserva: ");
        scanf("%d",&verf);
        
        if(verf!=bdRes[i].codHos){
            printf("!===CÓDIGO DO HÓSPEDE NÃO CORRESPONDE COM A RESERVA===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdCIn);
                free(bdRes);
                return;
            }
            i=lenRes;   //muda valor de i para continuar no loop
        }
    }while(i==lenRes);
    
    do{
        printf("Digite o código do checkIn: ");
        scanf("%d",&novo.cod);
        
        if(novo.cod<0){
            system("clear");
            printf("!===CÓDIGO DO CHECKIN DEVE SER POSITIVO===!\n\n");
            continue;
        }
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        j=0;                                                //IMPOSSIBILITA REPETIÇÃO DE CÓDIGOS
        while(bdCIn[j].cod!=novo.cod && j<lenCIn){
            j++;
        }
        
        if(j!=lenCIn){     
            printf("!===CÓDIGO JÁ ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar o cadastro:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CADASTRO CANCELADO===!\n\n");
                free(bdCIn);
                free(bdRes);
                return;
            }
        }
    }while(j!=lenCIn);
    
    do{
        printf("Pagar diárias no:\n1 - CheckIn\n0 - CheckOut\nEscolha uma opção: ");
        scanf("%d",&op);
    }while(op<0 || op>1);
    
    system("clear");
    novo.pagou=op;  //salva se foi pago no checkin
    
    if(novo.pagou==1){ 
        pagar_Diarias(bdRes[i],novo.pagou);  //chama função para pagar diarias
    }
        
    novo.prod=calloc(1,sizeof(comanda)); //aloca comanda para o checkin
    novo.prod[0].cod=-1;
    
    free(bdCIn);
    free(bdRes);
    cadastrar_CheckInBD(novo); //função para cadastrar no BD
}

void fazer_CheckOut(){
    
    checkin *bdCIn=dados_CheckIn(bdCIn);
    int lenCIn=len_CIn(bdCIn);
    
    if(lenCIn==0){
        printf("!===NENHUM CHECKIN CADASTRADO===!\n\n");
        return;
    }
    
    int i,j,op=1,cod;
    
    do{
        printf("Digite o código do CheckIn: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdCIn[i].cod!=cod && i<lenCIn){
            i++;
        }
        
        if(i==lenCIn){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===CHECKOUT CANCELADO===!\n\n");
                free(bdCIn);
                return;
            }
            
        }
    }while(i==lenCIn);
    
    system("clear");
    
    int lenCom=len_Com(bdCIn[i].prod);
    
    op=1;
    while(op!=0){  //dados
        printf("|====DADOS DO CHECKIN====|\n|Código: %d\n|Código Reserva: %d\n|Pagou no checkIn: %d\n|Produtos:\n"
                ,bdCIn[i].cod,bdCIn[i].reserva,bdCIn[i].pagou);
        
        for(j=0;j<lenCom;j++){
            printf("     -   -   -\n   |Código: %d\n   |Valor: %.2f\n",bdCIn[i].prod[j].cod,bdCIn[i].prod[j].valor); //MENU DINAMICO
        }                                                                                                           //PARA MOSTRAR COMANDA
        
        if(lenCom==0){
            printf("|===NENHUM PRODUTO COMPRADO===|\n");
        }
        printf("|1 - Fazer CheckOut\n|0 - Cancelar\nDigite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
            reserva *bdRes=dados_Reservas(bdRes); //carrega Banco de dados de reservas
            int lenRes=len_Res(bdRes); //tamanho do BD

            for(j=0;j<lenRes;j++){ //acha reserva referente ao checkin
                if(bdCIn[i].reserva==bdRes[j].cod){
                    break;
                }
            }

            if(bdCIn[i].pagou==0){      //caso não tenha pago no Checkin
                pagar_Diarias(bdRes[j],bdCIn[i].pagou); //chama função para pagar diarias
                bdCIn[i].pagou=1;
            }

            if(lenCom!=0){ //se comprou produtos para anotar
                pagar_Produtos(bdCIn[i].prod,bdRes[j].periodo,bdRes[j].codHos); //paga produtos
            }

            remove_DadosReserva(bdRes,lenRes,i); //remove reserva do Bd
        
            lenCIn--;                                   //remove checkin 
            
            if(lenCIn==0){ //se último, remove arquivo
                int result;
                FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
                
                if(arq!=NULL){
                    fclose(arq);
                    result = remove(".//Bd//CheckIn.txt");
                }else{
                    result = remove(".//Bd//CheckIn.bin");
                }
                if(result!=0){
                    printf("!===ERRO NA REMOÇÃO DO ARQUIVO===!\n\n");
                    free(bdCIn);
                    return;
                }else{
                    printf("!===ARQUIVO REMOVIDO COM SUCESSO===!\n\n");
                    free(bdCIn);
                    inicializa_Arquivos(); //recria
                    return;
                }
            }
            
            for(j=i;j<lenCIn;j++){  //move dados a esquerda
                bdCIn[j].cod=bdCIn[j+1].cod;
                bdCIn[j].reserva=bdCIn[j+1].reserva;
                bdCIn[j].pagou=bdCIn[j+1].pagou;
                bdCIn[j].prod=bdCIn[j+1].prod;
                
            }

            atualizar_CheckInBD(bdCIn,lenCIn); //salva no arquivo
            free(bdCIn);

            return;
        }
        
        system("clear");
        free(bdCIn);
        printf("|====EXCLUSÃO CANCELADA====|\n\n");
        return;
    }
}

//função para vizualizar dados dos checkin
void ver_CheckIn(){
    checkin *bdCIn=dados_CheckIn(bdCIn); //carrega Banco de dados
    int lenCIn=len_CIn(bdCIn); //tamanho do BD
    
    if(lenCIn==0){
        printf("!===NENHUM CHECKIN CADASTRADO===!\n\n");
        return;
    }
    
    int i,j,op,lenCom;
    for(i=0;i<lenCIn;i++){ //mostra dados
        printf("|Código: %d\n|Código Reserva: %d\n|Pagou no checkIn: %d\n|Produtos:\n"
                ,bdCIn[i].cod,bdCIn[i].reserva,bdCIn[i].pagou);
        
        lenCom=len_Com(bdCIn[i].prod);
        for(j=0;j<lenCom;j++){
            printf("     -   -   -\n   |Código: %d\n   |Valor: %.2f\n",bdCIn[i].prod[j].cod,bdCIn[i].prod[j].valor);
        }
        
        if(lenCom==0){
            printf("|===NENHUM PRODUTO COMPRADO===|\n");
        }
        
        printf("__________________________________\n\n");
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para vizualizar dados dos checkin
void ver_Caixa(){
    int op;
    float caixa;
    dados_Caixa(&caixa); //carrega dados
     
    printf("Valor do montante em caixa: R$%.2f\n\n",caixa); //mostra dados
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para vizualizar dados da movimentação do caixa
void ver_movCaixa(){
    movCaixa *bdMovC=dados_movCaixa(bdMovC); //carrega Banco de dados
    int lenMovC=len_MovC(bdMovC); //tamanho do BD
    
    if(lenMovC==0){
        printf("!===NENHUMA MOVIMENTAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    int i,op=0;
    char tipo[15];
    
    while(0==0){ //só quebra o loop se uma opção for selecionada
        printf("|=====TRANSAÇÕES=====|\n|1 - Ver Todas\n|2 - Lançamentos\n|3 - Retiradas\n"
                "|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        if(op==1){
            break;
        }else{
            if(op==2){
                strcpy(tipo,"lancamento");  //armazena filtro na variavel
                break;
            }else{   
                strcpy(tipo,"retirada");
                break;
            }
        }
    }
    
    for(i=0;i<lenMovC;i++){
        if(op==1 || strcmp(bdMovC[i].tipo,tipo)==0){ //segue o filtro
            printf("|Código: %d\n|Valor: %.2f\n|Tipo: %s\n|Forma de Pagamento: %s\n|Data: %d/%d/%d" //mostra dados
                   "\n__________________________________\n\n",bdMovC[i].cod,bdMovC[i].valor,bdMovC[i].tipo,bdMovC[i].pag,
                   bdMovC[i].dataTrans.dia_f,bdMovC[i].dataTrans.mes_f,bdMovC[i].dataTrans.ano_f);
        }
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
    
    return;
}

//função para vizualizar dados das contas a receber
void ver_ContasReceber(){
    movCartao *bdCRec=dados_ContasReceber(bdCRec); //carrega Banco de dados
    int lenCRec=len_Conta(bdCRec); //tamanho do BD
    
    if(lenCRec==0){
        printf("!===NENHUMA MOVIMENTAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenCRec;i++){
        printf("|Código: %d\n|Código Hóspede: %d\n|Nº Parcelas: %d\n|Valor: %.2f\n|Data: %d/%d/%d"  //mostra dados
               "\n__________________________________\n\n",bdCRec[i].cod,bdCRec[i].codChave,bdCRec[i].parc,bdCRec[i].valor,
               bdCRec[i].vencimento.dia_f,bdCRec[i].vencimento.mes_f,bdCRec[i].vencimento.ano_f);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
}

void cadastrar_Venda(){
    
    checkin *bdCIn=dados_CheckIn(bdCIn);
    int lenCIn=len_CIn(bdCIn);
    
    if(lenCIn==0){
        printf("!===NENHUM CHECKIN CADASTRADO===!\n\n");
        return;
    }
    
    int i,op=1,cod;
    
    do{
        printf("Digite o código do CheckIn: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdCIn[i].cod!=cod && i<lenCIn){
            i++;
        }
        
        if(i==lenCIn){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===VENDA CANCELADA===!\n\n");
                free(bdCIn);
                return;
            }
            
        }
    }while(i==lenCIn);
    
    produto *bdPro=dados_Produtos(bdPro);
    int lenPro=len_Pro(bdPro);
    
    if(lenPro==0){
        printf("!===NENHUM PRODUTO CADASTRADO===!\n\n");
        return;
    }
    
    comanda *produtos=calloc(1,sizeof(comanda));
    
    int cont=0,j,k;
    while(op!=0){
        printf("|====SAIDA DE PRODUTOS====|\n");   //MENU DINAMICO
        if(cont!=0){
            printf("|Protudos:\n     -   -   -\n");
            for(j=0;j<cont;j++){
                printf("    |Código: %d\n    |Valor: %.2f\n     -   -   -\n",produtos[j].cod,produtos[j].valor);
            }
        }
        printf("|1 - Comprar produto\n|2 - Pagar Produtos\n|0 - Cancelar\n|Digite uma opção: ");
        scanf("%d",&op);
        system("clear");
        
        switch(op){
            
            case 1:
                do{
                    printf("Digite o código do produto: ");
                    scanf("%d",&cod);                                   
                                                                        //ALGORITMO PARA VALIDAR CÓDIGOS
                    j=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
                    while(bdPro[j].cod!=cod && j<lenPro){
                        j++;
                    }

                    if(j==lenPro){     
                        printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                               "Digite 0 para cancelar procura:  ");
                        scanf("%d",&op);
                        system("clear"); 

                        if(op==0){
                            printf("!===VENDA CANCELADA===!\n\n");
                            free(bdPro);
                            return;
                        }

                    }
                }while(j==lenPro);
                printf("|Descrição: %s\n|Valor: %.2f\n|Estoque: %d\n\nDigite a quantidade: "
                        ,bdPro[j].desc,bdPro[j].venda,bdPro[j].est);
                scanf("%d",&op);
                system("clear");
                
                if(bdPro[j].est<op || op<0){
                    printf("!===NÃO HÁ PRODUTO SUFICIENTE NO ESTOQUE===!\n\n");
                    break;
                }
                
                for(k=0;k<op;k++){  //Salva produtos na comanda
                    cont++;
                    produtos=realloc(produtos,(cont+1)*sizeof(comanda));
                    produtos[cont-1].cod=bdPro[j].cod;
                    produtos[cont-1].valor=bdPro[j].venda;
                    produtos[cont].cod=-1;
                    bdPro[j].est--;
                }
                
                op=1;
            break;
            
            case 2:
                if(cont==0){
                    printf("!===NENHUM PRODUTO VENDIDO===!\n\n");
                    break;
                }
                
                op=0;
                while(op<1 || op>2){  //seleciona forma de pagamento
                    printf("|===Pagamento===|\n|1 - A vista\n|2 - Anotar\n|Digite uma opção:");
                    scanf("%d",&op);
                    system("clear");
                    
                    if(op<1 || op>2){
                        printf("!==CARACTER INVÁLIDO==!\n\n");
                    }
                }
                
                if(op==1){//se a vista :
                    data dtcompra;
                
                    printf("Digite a data da compra:\n");  //pega data
                    printf("Dia(DD): ");
                    scanf("%d",&dtcompra.dia_f);
                    printf("Mes(MM): ");
                    scanf("%d",&dtcompra.mes_f);
                    printf("Ano(AAAA): ");
                    scanf("%d",&dtcompra.ano_f);
                    system("clear");

                    dtcompra.dia_i=NULL;
                    dtcompra.mes_i=NULL;
                    dtcompra.ano_i=NULL;
                    
                    reserva *bdRes=dados_Reservas(bdRes); //acha reserva para pegar codHos
                    int lenRes=len_Res(bdRes),codHos;
                    
                    for(j=0;j<lenRes;j++){
                        if(bdRes[j].cod==bdCIn[i].reserva){
                            codHos=bdRes[j].codHos;
                            break;
                        }
                    }
                    
                    free(bdRes);

                    pagar_Produtos(produtos,dtcompra,codHos); //passa dados para pagar produtos
                }else{ //se para anotar
                    comanda *temp;
                    int lenCom=len_Com(bdCIn[i].prod);      //faz merge da comanda com a do checkin do Hospede

                    temp=calloc(lenCom+cont+1,sizeof(comanda));

                    for(j=0;j<lenCom;j++){  //pega comanda do checkin
                        temp[j].cod=bdCIn[i].prod[j].cod;
                        temp[j].valor=bdCIn[i].prod[j].valor;
                    }

                    for(k=0;k<cont;k++){ //adiciona produtos comprados
                        temp[j+k].cod=produtos[k].cod;
                        temp[j+k].valor=produtos[k].valor;
                    }

                    temp[lenCom+cont].cod=-1;

                    bdCIn[i].prod=temp; //atualiza comanda na memoria 

                    atualizar_CheckInBD(bdCIn,lenCIn); //atualiza nos arquivos
                }
                
                atualizar_ProdutoBD(bdPro,lenPro); // atualiza produtos para controle de estoque
                return;
            break;
                
            case 0:
                printf("!===VENDA CANCELADA===!\n\n");
                free(bdCIn);
                free(bdPro);
                return;
            break;
                
            default:
                printf("!==CARACTER INVÁLIDO==!\n\n");
            break;
        }
    }
}

//função para vizualizar dados das contas a receber
void ver_ContasPagar(){
    movCartao *bdCPag=dados_ContasPagar(bdCPag); //carrega Banco de dados
    int lenCPag=len_Conta(bdCPag); //tamanho do BD
    
    if(lenCPag==0){
        printf("!===NENHUMA MOVIMENTAÇÃO CADASTRADA===!\n\n");
        return;
    }
    
    int i,op;
    for(i=0;i<lenCPag;i++){
        printf("|Código: %d\n|Código do Fornecedor: %d\n|Nº Parcelas: %d\n|Valor: %.2f\n|Data: %d/%d/%d" //mostra dados
               "\n__________________________________\n\n",bdCPag[i].cod,bdCPag[i].codChave,bdCPag[i].parc,bdCPag[i].valor,
               bdCPag[i].vencimento.dia_f,bdCPag[i].vencimento.mes_f,bdCPag[i].vencimento.ano_f);
    }
    
    printf("Digite 0 para continuar: ");
    scanf("%d",&op);
    system("clear");
}

//função para cadastrar compras de produtos
void cadastrar_Compra(){
    
    fornecedor *bdFor=dados_Fornecedores(bdFor);
    int lenFor=len_For(bdFor);
    
    if(lenFor==0){
        printf("!===NENHUM FORNECEDOR CADASTRADO===!\n\n");
        return;
    }
    
    int i,j,op=1,cod;
    
    do{
        printf("Digite o código do fornecedor: ");
        scanf("%d",&cod);                                   
                                                            //ALGORITMO PARA VALIDAR CÓDIGOS
        i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
        while(bdFor[i].cod!=cod && i<lenFor){
            i++;
        }
        
        if(i==lenFor){     
            printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                   "Digite 0 para cancelar procura:  ");
            scanf("%d",&op);
            system("clear"); 
            
            if(op==0){
                printf("!===COMPRA CANCELADA===!\n\n");
                free(bdFor);
                return;
            }
            
        }
    }while(i==lenFor);
    system("clear");
    
    notaEntrada nova; //cria notinha
    
    nova.codFor=cod;
    
    do{
        printf("Digite o valor do frete: ");
        scanf("%f",&nova.vFrete);
        
        if(nova.vFrete<0){
            system("clear");
            printf("!===VALOR INVÁLIDO==!\n\n");  
        }
    }while(nova.vFrete<0);
    
    do{
        printf("Digite o valor do imposto: ");
        scanf("%f",&nova.vImp);
        
        if(nova.vImp<0){
            system("clear");
            printf("!===VALOR INVÁLIDO==!\n\n");
        }
    }while(nova.vImp<0);
    system("clear");
    
    nova.prod=calloc(1,sizeof(compra)); //cria vetor dinamico para produtos
    
    int cont=0,qtd;
    float valor;

    produto *bdPro=dados_Produtos(bdPro);
    int lenPro=len_Pro(bdPro);
    
    
    while(op!=0){
        printf("|====CADASTRO DA COMPRA===|\n");
        
        if(cont!=0){
            for(i=0;i<cont;i++){ //MENU DINAMICO PARA CADASTRO DE PRODUTOS
                printf("|%d - Código: %d\n     Quantidade: %d\n     Valor Unitário: %.2f\n     Valor Total: %.2f\n\n"
                ,i+1,nova.prod[i].cod,nova.prod[i].qtd,nova.prod[i].vUnid,(nova.prod[i].qtd*nova.prod[i].vUnid));
            }
        }
        printf("|%d - Cadastrar novo produto\n|%d - Confirmar Produtos\n|0 - Cancelar\n|Digite uma opção: ",(cont+1),(cont+2));
        scanf("%d",&op);
        system("clear");
        
        if(op<0 || op>cont+2){
            printf("!==CARACTER INVÁLIDO==!\n\n");
            continue;
        }
        
        if(op==cont+1){ //Cadastra novo produto
            do{
                printf("Digite o código do produto: ");
                scanf("%d",&cod);                                   
                                                                    //ALGORITMO PARA VALIDAR CÓDIGOS
                i=0;                                                //PROCURA REPETIÇÃO DE CÓDIGOS
                while(bdPro[i].cod!=cod && i<lenPro){
                    i++;
                }

                if(i==lenPro){     
                    printf("!===CÓDIGO NÃO ESTÁ EM USO===!\n\n"
                           "Digite 0 para cancelar procura:  ");
                    scanf("%d",&op);
                    system("clear"); 

                    if(op==0){
                        printf("!===COMPRA CANCELADA===!\n\n");
                        free(bdPro);
                        return;
                    }

                }
            }while(i==lenPro);
            
            for(i=0;i<cont;i++){ //verifica se produto ja foi cadastrado na nota anteriormente
                if(cod==nova.prod[i].cod){
                    system("clear");
                    printf("!===PRODUTO JÁ CADASTRADO NA NOTA===!\n\n");
                    cod=-1;
                    break;
                }
            }
            if(cod==-1){
                continue;
            }
            
            printf("Digite a quantidade: ");
            scanf("%d",&qtd);
            
            if(qtd<=0){
                system("clear");
                printf("!==QUANTIDADE INVÁLIDA==!\n\n");
                continue;
            }
            
            printf("Digite o valor unitário: ");
            scanf("%f",&valor);
            
            if(valor<=0){
                system("clear");
                printf("!==VALOR INVÁLIDO==!\n\n");
                continue;
            }
            
            cont++;
            nova.prod=realloc(nova.prod,cont*sizeof(compra));
            
            nova.prod[cont-1].cod=cod;
            nova.prod[cont-1].qtd=qtd;
            nova.prod[cont-1].vUnid=valor;
            system("clear");
            continue;
        }
        
        if(op==cont+2){ //confirma produtos cadastrados
            if(cont==0){
                printf("!===NENHUM PRODUTO CADASTRADO===!\n\n");
                continue;
            }
            
            nova.prod=realloc(nova.prod,(cont+1)*sizeof(compra));
            nova.prod[cont].cod=-1;
            
            pagar_Fornecedor(&nova,cont,bdPro,lenPro);   //função para opções de pagamento
            atualizar_ProdutoBD(bdPro,lenPro);  //atualiza bd produtos
            cadastrar_NotaEntradaBD(nova);   //cadastra nota no bd
            
            printf("|====NOTA E PRODUTOS CADASTRADOS COM SUCESSO===|\n\n");
            return;
        }
        
        if(op!=0){ //edita produto 
            printf("Digite a nova quantidade do produto: ");
            scanf("%d",&qtd);
        
            if(qtd<0){
                system("clear");
                printf("!==QUANTIDADE INVÁLIDA==!\n\n");
            }else{
                if(qtd==0){
                    system("clear");
                    for(i=op-1;i<cont-1;i++){ //se qtd == 0 remove da lista
                        nova.prod[i].cod=nova.prod[i+1].cod;
                        nova.prod[i].qtd=nova.prod[i+1].qtd;
                        nova.prod[i].vUnid=nova.prod[i+1].vUnid;
                    }
                    cont--;
                }else{
                    nova.prod[op-1].qtd=qtd;
                    printf("Digite a novo valor unitário do produto: ");
                    scanf("%f",&valor);
                    system("clear");

                    if(valor<=0){
                        printf("!==VALOR INVÁLIDO==!\n\n");
                        continue;
                    }else{
                        nova.prod[op-1].vUnid=valor;
                    }
                }
            }
        }
    }
    printf("!===COMPRA CANCELADA===!\n\n");
    free(bdFor);
    free(bdPro);
    return;
    
}