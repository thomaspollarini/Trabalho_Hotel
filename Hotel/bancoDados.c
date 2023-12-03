/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 *
 */


#include "bancoDados.h"
#include "util.h"


//função para criar arquivos na inicialização do sistema
void inicializa_Arquivos(){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        FILE *hotel=fopen(".//Bd//Hotel.txt","r");   //cria arquivo com dados do hotel
        if(hotel==NULL){                             //caso não exista
            cadastrar_Hotel();  //função para cadastrar hotel, na primeira vez que se abre o sistema
        }
        fclose(hotel);

        FILE *hospedes=fopen(".//Bd//Hospedes.txt","r");  //cria arquivo de dados para hospedes
        if(hospedes==NULL){
            hospedes=fopen(".//Bd//Hospedes.txt","w");

            if(hospedes==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(hospedes,"Código;Nome;CPF;Telefone;Email;Sexo;Status Civil;Nascimento;Endereço"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(hospedes);

        FILE *acomodacoes=fopen(".//Bd//Acomodacoes.txt","r");   //cria arquivo de dados para acomodações
        if(acomodacoes==NULL){
            acomodacoes=fopen(".//Bd//Acomodacoes.txt","w");

            if(acomodacoes==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(acomodacoes,"Código;Descrição;Facilidades;CódigoCategoria"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(acomodacoes);

        FILE *categorias=fopen(".//Bd//Categorias.txt","r");     //cria arquivo de dados para categorias
        if(categorias==NULL){
            categorias=fopen(".//Bd//Categorias.txt","w");

            if(categorias==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(categorias,"Código;Descrição;Valor;Adulto;Criança");  //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(categorias);

        FILE *produtos=fopen(".//Bd//Produtos.txt","r");        //cria arquivo de dados para produtos
        if(produtos==NULL){
            produtos=fopen(".//Bd//Produtos.txt","w");

            if(produtos==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(produtos,"Código;Descrição;EstoqueMin;Estoque;Custo;Venda");  //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(produtos);

        FILE *fornecedores=fopen(".//Bd//Fornecedores.txt","r");    //cria arquivo de dados para fornecedores
        if(fornecedores==NULL){
            fornecedores=fopen(".//Bd//Fornecedores.txt","w");

            if(fornecedores==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(fornecedores,"Código;Nome;Razão Social;Inscrição Estadual;CNPJ;Telefone;Email;Endereço"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(fornecedores);

        FILE *reservas=fopen(".//Bd//Reservas.txt","r");    //cria arquivo de dados para reservas
        if(reservas==NULL){
            reservas=fopen(".//Bd//Reservas.txt","w");

            if(reservas==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(reservas,"Código;Quarto;CódigoHospede;DataInicial;DataFinal"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(reservas);
        
        FILE *checkIn=fopen(".//Bd//CheckIn.txt","r");    //cria arquivo de dados para checkin
        if(checkIn==NULL){
            checkIn=fopen(".//Bd//CheckIn.txt","w");

            if(checkIn==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(checkIn,"Código;CodReserva;Pagou;Comandas"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(checkIn);
        
        FILE *arqCaixa=fopen(".//Bd//Caixa.txt","r");    //cria arquivo de dados para valor do caixa
        if(arqCaixa==NULL){
            arqCaixa=fopen(".//Bd//Caixa.txt","w");

            if(arqCaixa==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(arqCaixa,"0.00;Caixa"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(arqCaixa);
        
        FILE *movimentoC=fopen(".//Bd//MovimentacaoCaixa.txt","r");    //cria arquivo de dados para movimentação do caixa
        if(movimentoC==NULL){
            movimentoC=fopen(".//Bd//MovimentacaoCaixa.txt","w");

            if(movimentoC==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(movimentoC,"Código;Valor;Tipo;FormaDePagamento;Data"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(movimentoC);
        
        FILE *movimentoA=fopen(".//Bd//MovimentacaoAcomodacao.txt","r");    //cria arquivo de dados para movimentação do caixa
        if(movimentoA==NULL){
            movimentoA=fopen(".//Bd//MovimentacaoAcomodacao.txt","w");

            if(movimentoA==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(movimentoA,"Código;CódigoAcomodação;NúmeroDiarias;Valor"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(movimentoA);
        
        FILE *receber=fopen(".//Bd//ContasReceber.txt","r");    //cria arquivo de dados para contas a receber
        if(receber==NULL){
            receber=fopen(".//Bd//ContasReceber.txt","w");

            if(receber==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(receber,"Código;CódigoHóspede;Parcela;Valor;Data"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(receber);
        
        FILE *vendas=fopen(".//Bd//Vendas.txt","r");    //cria arquivo de dados para vendas
        if(vendas==NULL){
            vendas=fopen(".//Bd//Vendas.txt","w");

            if(vendas==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(vendas,"Código;CódigoProduto;FormaDePagamento;Valor"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(vendas);
        
        FILE *pagar=fopen(".//Bd//ContasPagar.txt","r");    //cria arquivo de dados para contas a receber
        if(pagar==NULL){
            pagar=fopen(".//Bd//ContasPagar.txt","w");

            if(pagar==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(pagar,"Código;CódigoFornecedor;Parcela;Valor;Data"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(pagar);
        
        FILE *notas=fopen(".//Bd//NotasEntrada.txt","r");    //cria arquivo de dados para checkin
        if(notas==NULL){
            notas=fopen(".//Bd//NotasEntrada.txt","w");

            if(notas==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(notas,"Código;CódigoFornecedor;Frete;Imposto;Total;Compras"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(notas);
        
        fclose(arq);
        return;
    }
    
    FILE *hotel=fopen(".//Bd//Hotel.bin","rb");   //cria arquivo com dados do hotel
    if(hotel==NULL){                             //caso não exista
        cadastrar_Hotel();  //função para cadastrar hotel, na primeira vez que se abre o sistema
    }
    fclose(hotel);
    
    FILE *hospedes=fopen(".//Bd//Hospedes.bin","rb");  //cria arquivo de dados para hospedes
    if(hospedes==NULL){
        hospedes=fopen(".//Bd//Hospedes.bin","wb");
    }
    fclose(hospedes);
    
    FILE *acomodacoes=fopen(".//Bd//Acomodacoes.bin","rb");   //cria arquivo de dados para acomodações
    if(acomodacoes==NULL){
        acomodacoes=fopen(".//Bd//Acomodacoes.bin","wb");
    }
    fclose(acomodacoes);
    
    FILE *categorias=fopen(".//Bd//Categorias.bin","rb");     //cria arquivo de dados para categorias
    if(categorias==NULL){
        categorias=fopen(".//Bd//Categorias.bin","wb");
    }
    fclose(categorias);
    
    FILE *produtos=fopen(".//Bd//Produtos.bin","rb");        //cria arquivo de dados para produtos
    if(produtos==NULL){
        produtos=fopen(".//Bd//Produtos.bin","wb");
    }
    fclose(produtos);
    
    FILE *fornecedores=fopen(".//Bd//Fornecedores.bin","rb");    //cria arquivo de dados para fornecedores
    if(fornecedores==NULL){
        fornecedores=fopen(".//Bd//Fornecedores.bin","wb");
    }
    fclose(fornecedores);
    
    FILE *reservas=fopen(".//Bd//Reservas.bin","rb");    //cria arquivo de dados para reserva
    if(reservas==NULL){
        reservas=fopen(".//Bd//Reservas.bin","wb");
    }
    fclose(reservas);
    
    FILE *checkIn=fopen(".//Bd//CheckIn.bin","rb");    //cria arquivo de dados para checkin
    if(checkIn==NULL){
        checkIn=fopen(".//Bd//CheckIn.bin","wb");
    }
    fclose(checkIn);
    
    FILE *comandas=fopen(".//Bd//Comandas.bin","rb");    //cria arquivo de dados para comandas
    if(comandas==NULL){
        comandas=fopen(".//Bd//Comandas.bin","wb");
    }
    fclose(comandas);
    
    FILE *arqCaixa=fopen(".//Bd//Caixa.bin","rb");    //cria arquivo de dados para valor do caixa
    if(arqCaixa==NULL){
        arqCaixa=fopen(".//Bd//Caixa.bin","wb");
        
        float init=0;
        
        fwrite(&init,sizeof(float),1,arqCaixa);
    }
    fclose(arqCaixa);
    
    FILE *movimentoC=fopen(".//Bd//MovimentacaoCaixa.bin","rb");    //cria arquivo de dados para movimento do caixa
    if(movimentoC==NULL){
        movimentoC=fopen(".//Bd//MovimentacaoCaixa.bin","wb");
    }
    fclose(movimentoC);
    
    FILE *movimentoA=fopen(".//Bd//MovimentacaoAcomodacao.bin","rb");    //cria arquivo de dados para movimento do caixa
    if(movimentoA==NULL){
        movimentoA=fopen(".//Bd//MovimentacaoAcomodacao.bin","wb");
    }
    fclose(movimentoA);
    
    FILE *receber=fopen(".//Bd//ContasReceber.bin","rb");    //cria arquivo de dados para contas a receber
    if(receber==NULL){
        receber=fopen(".//Bd//ContasReceber.bin","wb");
    }
    fclose(receber);
    
    FILE *vendas=fopen(".//Bd//Vendas.bin","rb");    //cria arquivo de dados para vendas
    if(vendas==NULL){
        vendas=fopen(".//Bd//Vendas.bin","wb");
    }
    fclose(vendas);
    
    FILE *pagar=fopen(".//Bd//ContasPagar.bin","rb");    //cria arquivo de dados para contas a receber
    if(pagar==NULL){
        pagar=fopen(".//Bd//ContasPagar.bin","wb");
    }
    fclose(pagar);
    
    FILE *notas=fopen(".//Bd//NotasEntrada.bin","rb");    //cria arquivo de dados para checkin
    if(notas==NULL){
        notas=fopen(".//Bd//NotasEntrada.bin","wb");
    }
    fclose(notas);
    
    FILE *compras=fopen(".//Bd//Compras.bin","rb");    //cria arquivo de dados para comandas
    if(compras==NULL){
        compras=fopen(".//Bd//Compras.bin","wb");
    }
    fclose(compras);
    
    return;
}

//função para carregar o banco de dados de operadores na mémoria
operador *dados_Operadores(operador *bdOpe){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");    //verifica tipo de arquivo
        
    if(arq!=NULL){
        fclose(arq);
        
        FILE *user = fopen(".//Bd//Operadores.txt","r");   //leitura de arquivo

        if (user==NULL){ //caso não exista arquivo, força criação de operador com acesso total

            operador novo;
            cria_ADM(&novo); //função para coleta de dados

            bdOpe=calloc(1,sizeof(operador));

            bdOpe[0].cod=novo.cod;
            strcpy(bdOpe[0].nome,novo.nome);
            strcpy(bdOpe[0].usuario,novo.usuario);
            strcpy(bdOpe[0].senha,novo.senha);
            for(int i=0;i<5;i++){
                bdOpe[0].acesso[i]=novo.acesso[i];
            }

            user= fopen(".//Bd//Operadores.txt","w");        //abre arquivo para escrita
            if(user == NULL){
                printf("Problemas na ABERTURA do arquivo\n");
                free(bdOpe);
                exit(1);
            }

            int result= fprintf(user,"Codigo;Nome;Usuario;Senha;Acesso\n"           //escreve dados
                    "%d;%s;%s;%s;11111",bdOpe[0].cod,bdOpe[0].nome,bdOpe[0].usuario,bdOpe[0].senha);
            if(result < 0){
                printf("!===ERRO AO SALVAR ARQUIVO===!\n");
                free(bdOpe);
                exit(1);
            }
            fclose(user);          //fecha arquivo                              

            bdOpe[1].cod=-1; //sinaliza fim do banco de dados

            return bdOpe;  //retornar banco de dados
        }else{

            int i=0;
            char linha[200], *token;


            bdOpe=calloc(1,sizeof(operador));   //cria vetor dinamico

            fgets(linha,200,user); //pulo indice doo arquivo

            while(!feof(user)){ //percorre todas as linhas do arquivo
                i++;
                bdOpe=realloc(bdOpe,i*sizeof(operador));  //realoca vetor dinamico
                fgets(linha,200,user);

                token=strtok(linha,";");         //separa dados da linha e aloca na memoria
                bdOpe[i-1].cod=atoi(token);

                token=strtok(NULL,";");             //separa dados da linha e aloca na memoria
                strcpy(bdOpe[i-1].nome,token);

                token=strtok(NULL,";");
                strcpy(bdOpe[i-1].usuario,token);       //separa dados da linha e aloca na memoria

                token=strtok(NULL,";");
                strcpy(bdOpe[i-1].senha,token);     //separa dados da linha e aloca na memoria

                token=strtok(NULL,";");

                bdOpe[i-1].acesso[0]=token[0]-'0';          //separa dados da linha e aloca na memoria
                bdOpe[i-1].acesso[1]=token[1]-'0';
                bdOpe[i-1].acesso[2]=token[2]-'0';          //'-0' para transforar char em int
                bdOpe[i-1].acesso[3]=token[3]-'0';
                bdOpe[i-1].acesso[4]=token[4]-'0';
            }

            fclose(user);  //fecha arquivo
            
            bdOpe=realloc(bdOpe,(i+1)*sizeof(operador));
            bdOpe[i].cod=-1; //sinaliza fim do banco de dados
            return bdOpe; //retorna banco de dados de operadores
        }
    }

    FILE *user = fopen(".//Bd//Operadores.bin","rb");   //leitura de arquivo

    if (user==NULL){ //caso não exista arquivo, força criação de operador com acesso total

        operador novo;
        cria_ADM(&novo); //função para coleta de dados

        bdOpe=calloc(1,sizeof(operador));

        bdOpe[0].cod=novo.cod;
        strcpy(bdOpe[0].nome,novo.nome);
        strcpy(bdOpe[0].usuario,novo.usuario);
        strcpy(bdOpe[0].senha,novo.senha);
        for(int i=0;i<5;i++){
            bdOpe[0].acesso[i]=novo.acesso[i];
        }
        
        user=fopen(".//Bd//Operadores.bin","wb");
        if(user == NULL){
            printf("Problemas na ABERTURA do arquivo\n");
            free(bdOpe);
            exit(1);
        }
        
        fwrite(&bdOpe[0],sizeof(operador),1,user); //escreve no arquivo
        
        fclose(user);  //fecha arquivo
        
        bdOpe=realloc(bdOpe,2*sizeof(operador));
        bdOpe[1].cod=-1; //sinaliza fim do banco de dados
        return bdOpe; //retorna banco de dados de operadores
        
    }else{
        fseek(user,0,SEEK_END);  //move pontenteiro para fim do arquivo
        long tam=ftell(user)/sizeof(operador);  //calcula numero de objetos no arquivo
        fseek(user,0,SEEK_SET);  //retorna ponteiro para inicio
        
        bdOpe=calloc(tam+1,sizeof(operador));  //inicializa bd
        
        fread(bdOpe,sizeof(operador),tam,user);  //lê arquivo
        fclose(user); //fecha arquivo
        bdOpe[tam].cod=-1;  //marca de fim
        return bdOpe;
    }
}

//função para cadastrar novo operador da memoria para o arquivo
void cadastrar_OperadorBD(operador novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        
        FILE *user= fopen(".//Bd//Operadores.txt","a");  //abre arquivo para escrita
    
        if(user==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(user,"\n%d;%s;%s;%s;%d%d%d%d%d",novo.cod,novo.nome,novo.usuario,novo.senha, //atualiza arquivo
                    novo.acesso[0],novo.acesso[1],novo.acesso[2],novo.acesso[3],novo.acesso[4]);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(user); //fecha arquivo

        system("clear");

        printf("|===OPERADOR CADASTRADO COM SUCESSO===|\n\n");
        return;
        
    }

    FILE *user= fopen(".//Bd//Operadores.bin","ab");
    
    if(user==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(operador),1,user);  //escreve no arquivo
    fclose(user); //fecha arquivo

    system("clear");
    printf("|===OPERADOR CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de operadores da memoria para o arquivo
void atualizar_OperadorBD(operador *bdOpe,int lenOpe){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        
        int i=0;
        FILE *user= fopen(".//Bd//Operadores.txt","w");  //recria arquivo do zero
    
        if(user==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(user,"Codigo;Nome;Usuario;Senha;Acesso"); //escreve indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenOpe;i++){  //loop para escrever banco de dados novo no arquivo
            result= fprintf(user,"\n%d;%s;%s;%s;%d%d%d%d%d",bdOpe[i].cod,bdOpe[i].nome,bdOpe[i].usuario,bdOpe[i].senha,
                        bdOpe[i].acesso[0],bdOpe[i].acesso[1],bdOpe[i].acesso[2],bdOpe[i].acesso[3],bdOpe[i].acesso[4]);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(user);//fecha arquivo
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *user= fopen(".//Bd//Operadores.bin","wb");  //recria arquivo do zero
    
    if(user==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdOpe,sizeof(operador),lenOpe,user); //escreve no arquivo
    
    fclose(user);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;

}

//função para carregar o banco de dados do hotel na mémoria
void dados_Hotel(hotel *bdHotel){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *hotel = fopen(".//Bd//Hotel.txt","r"); //abre para leitura
    
        if (hotel==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }else{
            char linha[100], *token;

            fgets(linha,100,hotel); 
            token=strtok(linha,";");
            strcpy(bdHotel->nome,token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->telefone,token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->email,token);           //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->nomeResp,token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->telefoneResp,token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->end.rua,token);     //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            bdHotel->end.num=atoi(token);       //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->end.comp,token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->end.bairro,token);      //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->end.cidade,token);      //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->end.estado,token);      //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            bdHotel->horaCheckin=atoi(token);       //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            bdHotel->horaCheckout=atoi(token);      //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            bdHotel->margem=atof(token);        //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            bdHotel->inscEstadual=atoi(token);      //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->razaoSocial,token);     //separa dados da linha e aloca na memoria

            fgets(linha,100,hotel);
            token=strtok(linha,";");
            strcpy(bdHotel->cnpj,token);        //separa dados da linha e aloca na memoria

            fclose(hotel);//fecha arquivo

            return; 
        }
    }
    FILE *hot = fopen(".//Bd//Hotel.bin","rb"); //abre para leitura
    
    if (hot==NULL){
        printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
        exit(1);
    }
    
    fread(bdHotel,sizeof(hotel),1,hot);  //lê arquivo
    fclose(hot);
    return;
}

//função para cadastrar hotel da memoria para o arquivo
void cadastrar_HotelBD(hotel bdHotel){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        FILE *hotel= fopen(".//Bd//Hotel.txt","w"); //recria arquivo

        if(hotel==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(hotel,"%s;Nome\n%s;Telefone\n%s;Email\n"     //escreve dados
                                  "%s;Nome Responsavel\n%s;Telefone Responsavel\n"
                                  "%s;Rua\n%d;Numero\n%s;Complemento\n%s;Bairro\n%s;Cidade\n%s;Estado\n"
                                  "%d;Hora checkin\n%d;Hora checkout\n%.2f;Margem lucro\n"
                                  "%d;Inscrição Estadual\n%s;Razão Social\n%s;CNPJ"
        ,bdHotel.nome,bdHotel.telefone,bdHotel.email,bdHotel.nomeResp,bdHotel.telefoneResp
        ,bdHotel.end.rua,bdHotel.end.num,bdHotel.end.comp,bdHotel.end.bairro,bdHotel.end.cidade,bdHotel.end.estado
        ,bdHotel.horaCheckin,bdHotel.horaCheckout,bdHotel.margem
        ,bdHotel.inscEstadual,bdHotel.razaoSocial,bdHotel.cnpj);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(hotel);//fecha arquivo

        system("clear");

        printf("|===HOTEL CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *hot= fopen(".//Bd//Hotel.bin","wb");
    
    if (hot==NULL){
        printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
        exit(1);
    }
    
    fwrite(&bdHotel,sizeof(hotel),1,hot);  //escreve no arquivo
    fclose(hot);
    system("clear");
    printf("|===HOTEL CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de hóspedes na mémoria
hospede *dados_Hospedes(hospede *bdHos){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *hospedes = fopen(".//Bd//Hospedes.txt","r");  //leitura do arquivo

        if(hospedes==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdHos=calloc(1,sizeof(hospede)); // cria vetor dinamico
        
        fgets(linha,500,hospedes);
        
        while(!feof(hospedes)){  //percorre todas as linhas do arquivo
            i++;
            bdHos=realloc(bdHos,i*sizeof(hospede));  //realoca tamanho do vetor
            fgets(linha,500,hospedes);
            
            token=strtok(linha,";");
            bdHos[i-1].cod=atoi(token);      //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].nome,token);  //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].cpf,token);   //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].telefone,token);      //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].email,token);     //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].sexo,token);      //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].civil,token);     //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].nasc,token);      //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].end.rua,token);       //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            bdHos[i-1].end.num=atoi(token);     //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].end.comp,token);      //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].end.bairro,token);        //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].end.cidade,token);        //separa dados da linha e aloca na memoria
            
            token=strtok(NULL,";");
            strcpy(bdHos[i-1].end.estado,token);    //separa dados da linha e aloca na memoria
        }
        fclose(hospedes); //fecha arquivo    
        
        bdHos=realloc(bdHos,(i+1)*sizeof(hospede));
        bdHos[i].cod=-1;  //sinaliza fim do BD
        return bdHos;
    }
    
    FILE *hospedes = fopen(".//Bd//Hospedes.bin","rb");  //leitura do arquivo
    
    if(hospedes==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(hospedes,0,SEEK_END);  //ponteiro no fim
    long tam=ftell(hospedes)/sizeof(hospede);  //numero de objetos
    fseek(hospedes,0,SEEK_SET);  //ponteiro no inicio
        
    bdHos=calloc(tam+1,sizeof(hospede));  //aloca bd
        
    fread(bdHos,sizeof(hospede),tam,hospedes); //lê arquivo
    fclose(hospedes); //fecha
    bdHos[tam].cod=-1; //marca fim
    return bdHos;
}

//função para cadastrar novo hospede da memoria para o arquivo
void cadastrar_HospedeBD(hospede novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *hospedes= fopen(".//Bd//Hospedes.txt","a"); //abre para escrita

        if(hospedes==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Nome;CPF;Telefone;Email;Sexo;Status Civil;Nascimento;Endereço
        int result= fprintf(hospedes,"\n%d;%s;%s;%s;%s;%s;%s;%s;%s;%d;%s;%s;%s;%s;",     //escreve novo dado no arquivo
                novo.cod,novo.nome,novo.cpf,novo.telefone,novo.email,novo.sexo,novo.civil,novo.nasc,
                novo.end.rua,novo.end.num,novo.end.comp,novo.end.bairro,novo.end.cidade,novo.end.estado);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(hospedes);//fecha arquivo

        system("clear");

        printf("|===HÓSPEDE CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *hospedes= fopen(".//Bd//Hospedes.bin","ab");
    
    if(hospedes==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(hospede),1,hospedes); //escreve no arquivo
    fclose(hospedes); //fecha arquivo

    system("clear");
    printf("|===HÓSPEDE CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de hospedes da memoria para o arquivo
void atualizar_HospedeBD(hospede *bdHos,int lenHos){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        
        int i=0;
        FILE *hospedes= fopen(".//Bd//Hospedes.txt","w"); //recria arquivo

        if(hospedes==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(hospedes,"Código;Nome;CPF;Telefone;Email;Sexo;Status Civil;Nascimento;Endereço"); //escreve indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenHos;i++){   //percorre BD escrevendo dados no arquivo
            result= fprintf(hospedes,"\n%d;%s;%s;%s;%s;%s;%s;%s;%s;%d;%s;%s;%s;%s;",
                bdHos[i].cod,bdHos[i].nome,bdHos[i].cpf,bdHos[i].telefone,bdHos[i].email,bdHos[i].sexo,bdHos[i].civil,bdHos[i].nasc,
                bdHos[i].end.rua,bdHos[i].end.num,bdHos[i].end.comp,bdHos[i].end.bairro,bdHos[i].end.cidade,bdHos[i].end.estado);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(hospedes);//fecha arquivo
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *hospedes= fopen(".//Bd//Hospedes.bin","wb");  //recria arquivo do zero
    
    if(hospedes==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdHos,sizeof(hospede),lenHos,hospedes); //escreve no arquivo
    
    fclose(hospedes);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de categorias na mémoria
categoria *dados_Categorias(categoria *bdCat){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *categorias = fopen(".//Bd//Categorias.txt","r"); //leitura de arquivo

        if(categorias==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdCat=calloc(1,sizeof(categoria));   //vetor dinamico
        
        fgets(linha,500,categorias);
        
        while(!feof(categorias)){ //passa pelas linhas
            i++;
            bdCat=realloc(bdCat,i*sizeof(categoria)); //realoca vetor
            fgets(linha,500,categorias);
            
            token=strtok(linha,";");
            bdCat[i-1].cod=atoi(token);   //coleta dados da linha
            
            token=strtok(NULL,";");
            strcpy(bdCat[i-1].desc,token);
            
            token=strtok(NULL,";");
            bdCat[i-1].vlr=atof(token);
            
            token=strtok(NULL,";");                 //coleta dados da linha
            bdCat[i-1].adulto=atoi(token);
            
            token=strtok(NULL,";");
            bdCat[i-1].crianca=atoi(token);
            
        }
        fclose(categorias);//fecha arquivo
        
        bdCat=realloc(bdCat,(i+1)*sizeof(categoria));
        bdCat[i].cod=-1; //sinaliza fim
        return bdCat;  //retorna BD
    }
    
    FILE *categorias = fopen(".//Bd//Categorias.bin","rb");  //leitura do arquivo
    
    if(categorias==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(categorias,0,SEEK_END); //ponteiro no fim
    long tam=ftell(categorias)/sizeof(categoria);  //numero objetos
    fseek(categorias,0,SEEK_SET); //ponteiro inicio
        
    bdCat=calloc(tam+1,sizeof(categoria)); //aloca bd
        
    fread(bdCat,sizeof(categoria),tam,categorias); //lê arquivo
    fclose(categorias); //fecha
    bdCat[tam].cod=-1; //marca fim
    return bdCat;
}

//função para cadastrar nova categoria da memoria para o arquivo
void cadastrar_CategoriaBD(categoria novo){
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *categorias= fopen(".//Bd//Categorias.txt","a"); //escrita de arquivo

        if(categorias==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Desc;Valor;Adulto;Criança
        int result= fprintf(categorias,"\n%d;%s;%.2f;%d;%d"    //escreve novos dados
                                        ,novo.cod,novo.desc,novo.vlr,novo.adulto,novo.crianca);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(categorias); //fecha

        system("clear");

        printf("|===CATEGORIA CADASTRADA COM SUCESSO===|\n\n");
        return;
    }
    FILE *categorias= fopen(".//Bd//Categorias.bin","ab");
    
    if(categorias==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(categoria),1,categorias);  //escreve no arquivo
    fclose(categorias); //fecha arquivo

    system("clear");
    printf("|===CATEGORIA CADASTRADA COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de categorias da memoria para o arquivo
void atualizar_CategoriaBD(categoria *bdCat,int lenCat){
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *categorias= fopen(".//Bd//Categorias.txt","w"); //recria

        if(categorias==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(categorias,"Código;Desc;Valor;Adulto;Criança"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenCat;i++){ //escreve dados
            result= fprintf(categorias,"\n%d;%s;%.2f;%d;%d",
                bdCat[i].cod,bdCat[i].desc,bdCat[i].vlr,bdCat[i].adulto,bdCat[i].crianca);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(categorias); //fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *categorias= fopen(".//Bd//Categorias.bin","wb");  //recria arquivo do zero
    
    if(categorias==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdCat,sizeof(categoria),lenCat,categorias); //escreve no arquivo
    
    fclose(categorias);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de acomodações na mémoria
acomodacao *dados_Acomodacoes(acomodacao *bdAco){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *acomodacoes = fopen(".//Bd//Acomodacoes.txt","r"); //leitura

        if(acomodacoes==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdAco=calloc(1,sizeof(acomodacao)); //vetor dinamico
        
        fgets(linha,500,acomodacoes);
        
        while(!feof(acomodacoes)){ //passa pelas linhas
            i++;
            bdAco=realloc(bdAco,i*sizeof(acomodacao)); //realoca vetor
            fgets(linha,500,acomodacoes);
            
            token=strtok(linha,";");
            bdAco[i-1].cod=atoi(token);    //coleta dados
            
            token=strtok(NULL,";");
            strcpy(bdAco[i-1].desc,token);
            
            token=strtok(NULL,";");
            strcpy(bdAco[i-1].fac,token);
            
            token=strtok(NULL,";");
            bdAco[i-1].cat=atoi(token);
            
        }
        fclose(acomodacoes);//fecha
        
        bdAco=realloc(bdAco,(i+1)*sizeof(acomodacao));
        bdAco[i].cod=-1; //fim
        return bdAco; //retorna BD
    }
    
    FILE *acomodacoes = fopen(".//Bd//Acomodacoes.bin","rb");  //leitura do arquivo
    
    if(acomodacoes==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(acomodacoes,0,SEEK_END); //fim
    long tam=ftell(acomodacoes)/sizeof(acomodacao); //tamanho
    fseek(acomodacoes,0,SEEK_SET); //inicio
        
    bdAco=calloc(tam+1,sizeof(acomodacao)); //aloca
        
    fread(bdAco,sizeof(acomodacao),tam,acomodacoes); //lê arquivo
    fclose(acomodacoes); //fecha
    bdAco[tam].cod=-1; //marca fim
    return bdAco;
}

//função para cadastrar nova acomodação da memoria para o arquivo
void cadastrar_AcomodacaoBD(acomodacao novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *acomodacoes= fopen(".//Bd//Acomodacoes.txt","a"); //escrita

        if(acomodacoes==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Descrição;Facilidades;CódigoCategoria
        int result= fprintf(acomodacoes,"\n%d;%s;%s;%d",novo.cod,novo.desc,novo.fac,novo.cat); //escreve novo dado

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(acomodacoes); //fecha

        system("clear");

        printf("|===ACOMODAÇÃO CADASTRADA COM SUCESSO===|\n\n");
        return;
    }
    FILE *acomodacoes= fopen(".//Bd//Acomodacoes.bin","ab");
    
    if(acomodacoes==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(acomodacao),1,acomodacoes); //escreve no arquivo
    fclose(acomodacoes); //fecha arquivo

    system("clear");
    printf("|===ACOMODAÇÃO CADASTRADA COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de acomodações da memoria para o arquivo
void atualizar_AcomodacaoBD(acomodacao *bdAco,int lenAco){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *acomodacoes= fopen(".//Bd//Acomodacoes.txt","w"); //recria

        if(acomodacoes==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(acomodacoes,"Código;Descrição;Facilidades;CódigoCategoria"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenAco;i++){ //escreve dados
            result= fprintf(acomodacoes,"\n%d;%s;%s;%d",
                bdAco[i].cod,bdAco[i].desc,bdAco[i].fac,bdAco[i].cat);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(acomodacoes); //fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *acomodacoes= fopen(".//Bd//Acomodacoes.bin","wb");  //recria arquivo do zero
    
    if(acomodacoes==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdAco,sizeof(acomodacao),lenAco,acomodacoes); //escreve no arquivo
    
    fclose(acomodacoes);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de produtos na mémoria
produto *dados_Produtos(produto *bdPro){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *produtos = fopen(".//Bd//Produtos.txt","r"); //leitura

        if(produtos==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdPro=calloc(1,sizeof(produto)); //vetor dinamico
        
        fgets(linha,500,produtos);
        
        while(!feof(produtos)){
            i++;
            bdPro=realloc(bdPro,i*sizeof(produto)); //realoca
            fgets(linha,500,produtos);
            
            token=strtok(linha,";");
            bdPro[i-1].cod=atoi(token);  //coleta dados
            
            token=strtok(NULL,";");
            strcpy(bdPro[i-1].desc,token);
            
            token=strtok(NULL,";");
            bdPro[i-1].estmin=atoi(token);
            
            token=strtok(NULL,";");
            bdPro[i-1].est=atoi(token);
            
            token=strtok(NULL,";");
            bdPro[i-1].custo=atof(token);
            
            token=strtok(NULL,";");
            bdPro[i-1].venda=atof(token);
            
        }
        fclose(produtos);//fecha
        
        bdPro=realloc(bdPro,(i+1)*sizeof(produto));
        bdPro[i].cod=-1; //fim
        return bdPro; //retorna BD
    }
    FILE *produtos = fopen(".//Bd//Produtos.bin","rb");  //leitura do arquivo
    
    if(produtos==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(produtos,0,SEEK_END);  //fim
    long tam=ftell(produtos)/sizeof(produto); //tamanho
    fseek(produtos,0,SEEK_SET); //inicio
        
    bdPro=calloc(tam+1,sizeof(produto)); //aloca
        
    fread(bdPro,sizeof(produto),tam,produtos); //lê arquivo
    fclose(produtos);  //fecha
    bdPro[tam].cod=-1; //marca fim
    return bdPro;
}

//função para cadastrar novo produto da memoria para o arquivo
void cadastrar_ProdutoBD(produto novo){
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *produtos= fopen(".//Bd//Produtos.txt","a"); //escrita

        if(produtos==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Descrição;EstoqueMin;Estoque;Custo;Venda
        int result= fprintf(produtos,"\n%d;%s;%d;%d;%.2f;%.2f",   //escreve novo dado
                novo.cod,novo.desc,novo.estmin,novo.est,novo.custo,novo.venda);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(produtos); //fecha

        system("clear");

        printf("|===PRODUTO CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    FILE *produtos= fopen(".//Bd//Produtos.bin","ab");
    
    if(produtos==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(produto),1,produtos); //escreve no arquivo
    fclose(produtos); //fecha arquivo

    system("clear");
    printf("|===PRODUTO CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de produtos da memoria para o arquivo
void atualizar_ProdutoBD(produto *bdPro,int lenPro){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *produtos= fopen(".//Bd//Produtos.txt","w");

        if(produtos==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(produtos,"Código;Descrição;EstoqueMin;Estoque;Custo;Venda");

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenPro;i++){
            result= fprintf(produtos,"\n%d;%s;%d;%d;%.2f;%.2f",
                bdPro[i].cod,bdPro[i].desc,bdPro[i].estmin,bdPro[i].est,bdPro[i].custo,bdPro[i].venda);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(produtos);
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *produtos= fopen(".//Bd//Produtos.bin","wb");  //recria arquivo do zero
    
    if(produtos==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdPro,sizeof(produto),lenPro,produtos); //escreve no arquivo
    
    fclose(produtos);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de fornecedores na mémoria
fornecedor *dados_Fornecedores(fornecedor *bdFor){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *fornecedores = fopen(".//Bd//Fornecedores.txt","r"); //leitura

        if(fornecedores==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdFor=calloc(1,sizeof(fornecedor)); //vetor dinamico
        
        fgets(linha,500,fornecedores);
        
        while(!feof(fornecedores)){  //passa linhas
            i++;
            bdFor=realloc(bdFor,i*sizeof(fornecedor));  //realoca
            fgets(linha,500,fornecedores);
            
            token=strtok(linha,";");
            bdFor[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].nome,token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].razaoSocial,token);
            
            token=strtok(NULL,";");
            bdFor[i-1].inscEstadual=atoi(token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].cnpj,token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].telefone,token);
                
            token=strtok(NULL,";");                 //coleta dados
            strcpy(bdFor[i-1].email,token);

            token=strtok(NULL,";");
            strcpy(bdFor[i-1].end.rua,token);
            
            token=strtok(NULL,";");
            bdFor[i-1].end.num=atoi(token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].end.comp,token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].end.bairro,token);
            
            token=strtok(NULL,";");                 //coleta dados
            strcpy(bdFor[i-1].end.cidade,token);
            
            token=strtok(NULL,";");
            strcpy(bdFor[i-1].end.estado,token);
        }
        fclose(fornecedores);//fecha
        
        bdFor=realloc(bdFor,(i+1)*sizeof(fornecedor));
        bdFor[i].cod=-1;//fim
        return bdFor;//retorna BD
    }
    FILE *fornecedores = fopen(".//Bd//Fornecedores.bin","rb");  //leitura do arquivo
    
    if(fornecedores==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(fornecedores,0,SEEK_END); //fim
    long tam=ftell(fornecedores)/sizeof(fornecedor); //tamanho
    fseek(fornecedores,0,SEEK_SET); //inicio
        
    bdFor=calloc(tam+1,sizeof(fornecedor)); //aloca
        
    fread(bdFor,sizeof(fornecedor),tam,fornecedores); //lê arquivo
    fclose(fornecedores); //fecha
    bdFor[tam].cod=-1; //marca fim
    return bdFor;
}

//função para cadastrar novo fornecedor da memoria para o arquivo
void cadastrar_FornecedorBD(fornecedor novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *fornecedores= fopen(".//Bd//Fornecedores.txt","a"); //escrita

        if(fornecedores==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Nome;Razão Social;Inscrição Estadual;CNPJ;Telefone;Email;Endereço
        int result= fprintf(fornecedores,"\n%d;%s;%s;%d;%s;%s;%s;%s;%d;%s;%s;%s;%s;",  //escreve novo dado
                novo.cod,novo.nome,novo.razaoSocial,novo.inscEstadual,novo.cnpj,novo.telefone,novo.email,
                novo.end.rua,novo.end.num,novo.end.comp,novo.end.bairro,novo.end.cidade,novo.end.estado);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(fornecedores);//fecha

        system("clear");
        printf("|===FORNECEDOR CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *fornecedores= fopen(".//Bd//Fornecedores.bin","ab");
    
    if(fornecedores==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(fornecedor),1,fornecedores); //escreve no arquivo
    fclose(fornecedores); //fecha arquivo

    system("clear");
    printf("|===FORNECEDOR CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de fornecedores da memoria para o arquivo
void atualizar_FornecedorBD(fornecedor *bdFor,int lenFor){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *fornecedores= fopen(".//Bd//Fornecedores.txt","w");  //recria

        if(fornecedores==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(fornecedores,"Código;Nome;Razão Social;Inscrição Estadual;CNPJ;Telefone;Email;Endereço");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenFor;i++){  //escreve dados
           int result= fprintf(fornecedores,"\n%d;%s;%s;%d;%s;%s;%s;%s;%d;%s;%s;%s;%s;",
                bdFor[i].cod,bdFor[i].nome,bdFor[i].razaoSocial,bdFor[i].inscEstadual,bdFor[i].cnpj,bdFor[i].telefone,bdFor[i].email,
                bdFor[i].end.rua,bdFor[i].end.num,bdFor[i].end.comp,bdFor[i].end.bairro,bdFor[i].end.cidade,bdFor[i].end.estado);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(fornecedores);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *fornecedores= fopen(".//Bd//Fornecedores.bin","wb");  //recria arquivo do zero
    
    if(fornecedores==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdFor,sizeof(fornecedor),lenFor,fornecedores); //escreve no arquivo
    
    fclose(fornecedores);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de reservas na mémoria
reserva *dados_Reservas(reserva *bdRes){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
     
    if(arq!=NULL){
        fclose(arq);
        FILE *reservas = fopen(".//Bd//Reservas.txt","r"); //leitura

        if(reservas==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdRes=calloc(1,sizeof(reserva)); //vetor dinamico
        
        fgets(linha,500,reservas);
        
        while(!feof(reservas)){ //passa pelas linhas
            i++;
            bdRes=realloc(bdRes,i*sizeof(reserva)); //realoca vetor
            fgets(linha,500,reservas);
            
            token=strtok(linha,";");
            bdRes[i-1].cod=atoi(token);    //coleta dados
            
            token=strtok(NULL,";");
            bdRes[i-1].quarto=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].codHos=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.dia_i=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.mes_i=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.ano_i=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.dia_f=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.mes_f=atoi(token);
            
            token=strtok(NULL,";");
            bdRes[i-1].periodo.ano_f=atoi(token);
        }
        fclose(reservas);//fecha
        
        bdRes=realloc(bdRes,(i+1)*sizeof(reserva));
        bdRes[i].cod=-1; //fim
        return bdRes; //retorna BD
    }
    
    FILE *reservas = fopen(".//Bd//Reservas.bin","rb");  //leitura do arquivo
    
    if(reservas==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(reservas,0,SEEK_END);  //fim
    long tam=ftell(reservas)/sizeof(reserva);  //tamanho
    fseek(reservas,0,SEEK_SET);  //inicio
        
    bdRes=calloc(tam+1,sizeof(reserva)); //aloca
        
    fread(bdRes,sizeof(reserva),tam,reservas); //lê arquivo
    fclose(reservas); //fecha
    bdRes[tam].cod=-1; //marca fim
    return bdRes;
}

//função para cadastrar nova reserva da memoria para o arquivo
void cadastrar_ReservaBD(reserva novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *reservas= fopen(".//Bd//Reservas.txt","a"); //escrita

        if(reservas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Quarto;CódigoHospede;DataInicial;DataFinal
        int result= fprintf(reservas,"\n%d;%d;%d;%d;%d;%d;%d;%d;%d",novo.cod,novo.quarto,novo.codHos,novo.periodo.dia_i
        ,novo.periodo.mes_i,novo.periodo.ano_i,novo.periodo.dia_f,novo.periodo.mes_f,novo.periodo.ano_f); //escreve novo dado

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(reservas); //fecha

        system("clear");

        printf("|===RESERVA CADASTRADA COM SUCESSO===|\n\n");
        return;
    }
    FILE *reservas= fopen(".//Bd//Reservas.bin","ab");
    
    if(reservas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(reserva),1,reservas);  //escreve no arquivo
    fclose(reservas); //fecha arquivo

    system("clear");
    printf("|===RESERVA CADASTRADA COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de reservas da memoria para o arquivo
void atualizar_ReservaBD(reserva *bdRes,int lenRes){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *reservas= fopen(".//Bd//Reservas.txt","w"); //recria

        if(reservas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(reservas,"Código;Quarto;CódigoHospede;DataInicial;DataFinal"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenRes;i++){ //escreve dados
            result= fprintf(reservas,"\n%d;%d;%d;%d;%d;%d;%d;%d;%d",bdRes[i].cod,bdRes[i].quarto,bdRes[i].codHos,bdRes[i].periodo.dia_i
            ,bdRes[i].periodo.mes_i,bdRes[i].periodo.ano_i,bdRes[i].periodo.dia_f,bdRes[i].periodo.mes_f,bdRes[i].periodo.ano_f);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(reservas); //fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *reservas= fopen(".//Bd//Reservas.bin","wb");  //recria arquivo do zero
    
    if(reservas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdRes,sizeof(reserva),lenRes,reservas); //escreve no arquivo
    
    fclose(reservas);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de checkIn na mémoria
checkin *dados_CheckIn(checkin *bdCIn){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
     
    if(arq!=NULL){
        fclose(arq);
        FILE *checkIn = fopen(".//Bd//CheckIn.txt","r"); //leitura

        if(checkIn==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0,j;
        char linha[500], *token;
        
        bdCIn=calloc(1,sizeof(checkin)); //vetor dinamico
        
        fgets(linha,500,checkIn);
        
        while(!feof(checkIn)){ //passa pelas linhas
            i++;
            bdCIn=realloc(bdCIn,i*sizeof(checkin)); //realoca vetor
            fgets(linha,500,checkIn);
            
            token=strtok(linha,";");
            bdCIn[i-1].cod=atoi(token);    //coleta dados
            
            token=strtok(NULL,";");
            bdCIn[i-1].reserva=atoi(token);
            
            token=strtok(NULL,";");
            bdCIn[i-1].pagou=atoi(token);
            
            j=0;
            comanda *temp=calloc(1,sizeof(comanda)); //vetor dinamico para comandas
            
            token=strtok(NULL,";"); //lê proximo token, se NULL não há comandas
            while(token!=NULL){
                j++;
                temp=realloc(temp,j*sizeof(comanda));
                
                temp[j-1].cod=atoi(token); //armazena token lido no fim do ciclo, ou antes dele
                
                token=strtok(NULL,";");  
                temp[j-1].valor=atof(token);
                
                token=strtok(NULL,";");  //lê proximo token, se diferente de NULL, repete ciclo
            }
            
            temp=realloc(temp,(j+1)*sizeof(comanda));
            temp[j].cod=-1;
            
            bdCIn[i-1].prod=temp;
            
        }
        fclose(checkIn);//fecha
        
        bdCIn=realloc(bdCIn,(i+1)*sizeof(checkin));
        bdCIn[i].cod=-1; //fim
        return bdCIn; //retorna BD
    }
    
    FILE *checkIn = fopen(".//Bd//CheckIn.bin","rb");  //leitura do arquivo
    
    if(checkIn==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(checkIn,0,SEEK_END);  //fim
    long tam=ftell(checkIn)/sizeof(checkin);  //tamanho
    fseek(checkIn,0,SEEK_SET);  //inicio
        
    bdCIn=calloc(tam+1,sizeof(checkin)); //aloca
        
    fread(bdCIn,sizeof(checkin),tam,checkIn); //lê arquivo
    fclose(checkIn); //fecha
    bdCIn[tam].cod=-1; //marca fim
    
    FILE *comandas = fopen(".//Bd//Comandas.bin","rb");  //leitura do arquivo
    
    if(comandas==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(comandas,0,SEEK_END);  //fim
    tam=ftell(comandas)/sizeof(comanda);  //tamanho
    fseek(comandas,0,SEEK_SET);  //inicio
        
    comanda *bdCom=calloc(tam,sizeof(comanda)); //aloca
        
    fread(bdCom,sizeof(comanda),tam,comandas); //lê arquivo
    fclose(comandas); //fecha

    associa_Comandas(bdCIn,bdCom);
    
    return bdCIn;
}

//função para cadastrar novo checkIn da memoria para o arquivo
void cadastrar_CheckInBD(checkin novo){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *checkIn= fopen(".//Bd//CheckIn.txt","a"); //escrita

        if(checkIn==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CodReserva;Pagou;Comandas
        int result= fprintf(checkIn,"\n%d;%d;%d",novo.cod,novo.reserva,novo.pagou); //escreve novo dado

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        
        int lenCom=len_Com(novo.prod);
        
        for(int i=0;i<lenCom;i++){
            result= fprintf(checkIn,";%d;%.2f",novo.prod[i].cod,novo.prod[i].valor); //escreve novo dado

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        
        fclose(checkIn); //fecha


        printf("|===CHECKIN CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    FILE *checkIn= fopen(".//Bd//CheckIn.bin","ab");
    
    if(checkIn==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(checkin),1,checkIn);  //escreve no arquivo
    fclose(checkIn); //fecha arquivo
    
    FILE *comandas= fopen(".//Bd//Comandas.bin","ab");  //abre arquivo para vetores de comandas
                                                    
    if(comandas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    int lenCom=len_Com(novo.prod);
    fwrite(novo.prod,sizeof(comanda),lenCom+1,comandas);  //escreve no arquivo
    fclose(comandas); //fecha arquivo

    printf("|===CHECKIN CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de checkIn da memoria para o arquivo
void atualizar_CheckInBD(checkin *bdCIn,int lenCIn){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *checkIn= fopen(".//Bd//CheckIn.txt","w"); //recria

        if(checkIn==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(checkIn,"Código;CodReserva;Pagou;Comandas"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenCIn;i++){ //escreve dados
            result= fprintf(checkIn,"\n%d;%d;%d",bdCIn[i].cod,bdCIn[i].reserva,bdCIn[i].pagou); //escreve novo dado

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        
            int lenCom=len_Com(bdCIn[i].prod);
        
            for(int j=0;j<lenCom;j++){
                result= fprintf(checkIn,";%d;%.2f",bdCIn[i].prod[j].cod,bdCIn[i].prod[j].valor); //escreve novo dado

                if(result < 0){
                    printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                    return;
                }   
            }
        }

        fclose(checkIn); //fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *checkIn= fopen(".//Bd//CheckIn.bin","wb");  //recria arquivo do zero
    
    if(checkIn==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdCIn,sizeof(checkin),lenCIn,checkIn); //escreve no arquivo
    
    fclose(checkIn);//fecha arquivo
    
    FILE *comandas= fopen(".//Bd//Comandas.bin","wb");  //recria arquivo do zero
    
    if(comandas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    int lenCom;
    for(int i=0;i<lenCIn;i++){
        lenCom=len_Com(bdCIn[i].prod);
        fwrite(bdCIn[i].prod,sizeof(comanda),lenCom+1,comandas); //escreve no arquivo
    }
    
    fclose(comandas);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados do caixa na mémoria
void dados_Caixa(float *caixa){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *arqCaixa = fopen(".//Bd//Caixa.txt","r"); //abre para leitura
    
        if (arqCaixa==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }else{
            char linha[100], *token;

            fgets(linha,100,arqCaixa); 
            token=strtok(linha,";");
            *caixa=atof(token);      //separa dados da linha e aloca na memoria


            fclose(arqCaixa);//fecha arquivo

            return; 
        }
    }
    FILE *arqCaixa = fopen(".//Bd//Caixa.bin","rb"); //abre para leitura
    
    if (arqCaixa==NULL){
        printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
        exit(1);
    }
    
    fread(caixa,sizeof(float),1,arqCaixa);  //lê arquivo
    fclose(arqCaixa);
    return;
}

//função para atualizar caixa da memoria para o arquivo
void atualizar_CaixaBD(float caixa){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        FILE *arqCaixa= fopen(".//Bd//Caixa.txt","w"); //recria arquivo

        if(arqCaixa==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(arqCaixa,"%.2f;caixa",caixa);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(arqCaixa);//fecha arquivo

        system("clear");

        printf("|===CAIXA CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *arqCaixa= fopen(".//Bd//Caixa.bin","wb");
    
    if (arqCaixa==NULL){
        printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
        exit(1);
    }
    
    fwrite(&caixa,sizeof(float),1,arqCaixa);  //escreve no arquivo
    fclose(arqCaixa);
    system("clear");
    printf("|===CAIXA CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de movimentação do caixa na mémoria
movCaixa *dados_movCaixa(movCaixa *bdMovC){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *movimentoC = fopen(".//Bd//MovimentacaoCaixa.txt","r"); //leitura

        if(movimentoC==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdMovC=calloc(1,sizeof(movCaixa)); //vetor dinamico
        
        fgets(linha,500,movimentoC);
        
        while(!feof(movimentoC)){  //passa linhas
            i++;
            bdMovC=realloc(bdMovC,i*sizeof(movCaixa));  //realoca
            fgets(linha,500,movimentoC);
            
            token=strtok(linha,";");
            bdMovC[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            bdMovC[i-1].valor=atof(token);
            
            token=strtok(NULL,";");
            strcpy(bdMovC[i-1].tipo,token);
            
            token=strtok(NULL,";");
            strcpy(bdMovC[i-1].pag,token);
            
            token=strtok(NULL,";");
            bdMovC[i-1].dataTrans.dia_f=atoi(token);
            
            token=strtok(NULL,";");
            bdMovC[i-1].dataTrans.mes_f=atoi(token);
            
            token=strtok(NULL,";");
            bdMovC[i-1].dataTrans.ano_f=atoi(token);
            
            bdMovC[i-1].dataTrans.dia_i=NULL;
            bdMovC[i-1].dataTrans.mes_i=NULL;
            bdMovC[i-1].dataTrans.ano_i=NULL;
        }
        fclose(movimentoC);//fecha
        
        bdMovC=realloc(bdMovC,(i+1)*sizeof(movCaixa));
        bdMovC[i].cod=-1;//fim
        return bdMovC;//retorna BD
    }
    FILE *movimentoC = fopen(".//Bd//MovimentacaoCaixa.bin","rb");  //leitura do arquivo
    
    if(movimentoC==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(movimentoC,0,SEEK_END); //fim
    long tam=ftell(movimentoC)/sizeof(movCaixa); //tamanho
    fseek(movimentoC,0,SEEK_SET); //inicio
        
    bdMovC=calloc(tam+1,sizeof(movCaixa)); //aloca
        
    fread(bdMovC,sizeof(movCaixa),tam,movimentoC); //lê arquivo
    fclose(movimentoC); //fecha
    bdMovC[tam].cod=-1; //marca fim
    return bdMovC;
}

//função para cadastrar novo movimento da memoria para o arquivo
void cadastrar_movCaixaBD(movCaixa novo){
    
    movCaixa *bdMovC=dados_movCaixa(bdMovC);
    int lenMovC=len_MovC(bdMovC);
    
    novo.cod=lenMovC+1;
    
    free(bdMovC);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *movimentoC= fopen(".//Bd//MovimentacaoCaixa.txt","a"); //escrita

        if(movimentoC==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;Valor;Tipo;Data
        int result= fprintf(movimentoC,"\n%d;%.2f;%s;%s;%d;%d;%d",  //escreve novo dado
                novo.cod,novo.valor,novo.tipo,novo.pag,novo.dataTrans.dia_f,novo.dataTrans.mes_f,novo.dataTrans.ano_f);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(movimentoC);//fecha

        system("clear");
        printf("|===MOVIMENTO CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *movimentoC= fopen(".//Bd//MovimentacaoCaixa.bin","ab");
    
    if(movimentoC==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(movCaixa),1,movimentoC); //escreve no arquivo
    fclose(movimentoC); //fecha arquivo

    system("clear");
    printf("|===MOVIMENTO CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de movimento da memoria para o arquivo
void atualizar_movCaixaBD(movCaixa *bdMovC,int lenMovC){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *movimentoC= fopen(".//Bd//MovimentacaoCaixa.txt","w");  //recria

        if(movimentoC==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(movimentoC,"Código;Valor;Tipo;FormaDePagamento;Data");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenMovC;i++){  //escreve dados
           int result= fprintf(movimentoC,"\n%d;%.2f;%s;%s;%d;%d;%d",bdMovC[i].cod,bdMovC[i].valor,bdMovC[i].tipo
                    ,bdMovC[i].pag,bdMovC[i].dataTrans.dia_f,bdMovC[i].dataTrans.mes_f,bdMovC[i].dataTrans.ano_f);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(movimentoC);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *movimentoC= fopen(".//Bd//MovimentacaoCaixa.bin","wb");  //recria arquivo do zero
    
    if(movimentoC==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdMovC,sizeof(movCaixa),lenMovC,movimentoC); //escreve no arquivo
    
    fclose(movimentoC);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de movimentação de acomodação na mémoria
movAcomodacao *dados_movAcomodacao(movAcomodacao *bdMovA){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *movimentoA = fopen(".//Bd//MovimentacaoAcomodacao.txt","r"); //leitura

        if(movimentoA==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdMovA=calloc(1,sizeof(movAcomodacao)); //vetor dinamico
        
        fgets(linha,500,movimentoA);
        
        while(!feof(movimentoA)){  //passa linhas
            i++;
            bdMovA=realloc(bdMovA,i*sizeof(movAcomodacao));  //realoca
            fgets(linha,500,movimentoA);
            
            token=strtok(linha,";");
            bdMovA[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            bdMovA[i-1].codAco=atoi(token);
            
            token=strtok(NULL,";");
            bdMovA[i-1].numDia=atoi(token);
            
            token=strtok(NULL,";");
            bdMovA[i-1].valor=atof(token);          
        }
        fclose(movimentoA);//fecha
        
        bdMovA=realloc(bdMovA,(i+1)*sizeof(movAcomodacao));
        bdMovA[i].cod=-1;//fim
        return bdMovA;//retorna BD
    }
    FILE *movimentoA = fopen(".//Bd//MovimentacaoAcomodacao.bin","rb");  //leitura do arquivo
    
    if(movimentoA==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(movimentoA,0,SEEK_END); //fim
    long tam=ftell(movimentoA)/sizeof(movAcomodacao); //tamanho
    fseek(movimentoA,0,SEEK_SET); //inicio
        
    bdMovA=calloc(tam+1,sizeof(movAcomodacao)); //aloca
        
    fread(bdMovA,sizeof(movAcomodacao),tam,movimentoA); //lê arquivo
    fclose(movimentoA); //fecha
    bdMovA[tam].cod=-1; //marca fim
    return bdMovA;
}

//função para cadastrar novo movimento da memoria para o arquivo
void cadastrar_movAcomodacaoBD(movAcomodacao novo){
    
    movAcomodacao *bdMovA=dados_movAcomodacao(bdMovA);
    int lenMovA=len_MovA(bdMovA);
    
    novo.cod=lenMovA+1;
    
    free(bdMovA);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *movimentoA= fopen(".//Bd//MovimentacaoAcomodacao.txt","a"); //escrita

        if(movimentoA==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CódigoAcomodação;NúmeroDiarias;Valor
        int result= fprintf(movimentoA,"\n%d;%d;%d;%.2f",  //escreve novo dado
                novo.cod,novo.codAco,novo.numDia,novo.valor);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(movimentoA);//fecha

        system("clear");
        printf("|===MOVIMENTO CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *movimentoA= fopen(".//Bd//MovimentacaoAcomodacao.bin","ab");
    
    if(movimentoA==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(movAcomodacao),1,movimentoA); //escreve no arquivo
    fclose(movimentoA); //fecha arquivo

    system("clear");
    printf("|===MOVIMENTO CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de movimento da memoria para o arquivo
void atualizar_movAcomodacaoBD(movAcomodacao *bdMovA,int lenMovA){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *movimentoA= fopen(".//Bd//MovimentacaoAcomodacao.txt","w");  //recria

        if(movimentoA==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(movimentoA,"Código;CódigoAcomodação;NúmeroDiarias;Valor");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenMovA;i++){  //escreve dados
           int result= fprintf(movimentoA,"\n%d;%d;%d;%.2f",  //escreve novo dado
                bdMovA[i].cod,bdMovA[i].codAco,bdMovA[i].numDia,bdMovA[i].valor);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(movimentoA);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *movimentoA= fopen(".//Bd//MovimentacaoAcomodacao.bin","wb");  //recria arquivo do zero
    
    if(movimentoA==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdMovA,sizeof(movAcomodacao),lenMovA,movimentoA); //escreve no arquivo
    
    fclose(movimentoA);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de contas a receber na mémoria
movCartao *dados_ContasReceber(movCartao *bdCRec){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *receber = fopen(".//Bd//ContasReceber.txt","r"); //leitura

        if(receber==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdCRec=calloc(1,sizeof(movCartao)); //vetor dinamico
        
        fgets(linha,500,receber);
        
        while(!feof(receber)){  //passa linhas
            i++;
            bdCRec=realloc(bdCRec,i*sizeof(movCartao));  //realoca
            fgets(linha,500,receber);
            
            token=strtok(linha,";");
            bdCRec[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            bdCRec[i-1].codChave=atoi(token);
            
            token=strtok(NULL,";");
            bdCRec[i-1].parc=atoi(token);
            
            token=strtok(NULL,";");
            bdCRec[i-1].valor=atof(token);
            
            token=strtok(NULL,";");
            bdCRec[i-1].vencimento.dia_f=atoi(token);
            
            token=strtok(NULL,";");
            bdCRec[i-1].vencimento.mes_f=atoi(token);
            
            token=strtok(NULL,";");
            bdCRec[i-1].vencimento.ano_f=atoi(token);
            
            bdCRec[i-1].vencimento.dia_i=NULL;
            bdCRec[i-1].vencimento.mes_i=NULL;
            bdCRec[i-1].vencimento.ano_i=NULL;
        }
        fclose(receber);//fecha
        
        bdCRec=realloc(bdCRec,(i+1)*sizeof(movCartao));
        bdCRec[i].cod=-1;//fim
        return bdCRec;//retorna BD
    }
    FILE *receber = fopen(".//Bd//ContasReceber.bin","rb");  //leitura do arquivo
    
    if(receber==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(receber,0,SEEK_END); //fim
    long tam=ftell(receber)/sizeof(movCartao); //tamanho
    fseek(receber,0,SEEK_SET); //inicio
        
    bdCRec=calloc(tam+1,sizeof(movCartao)); //aloca
        
    fread(bdCRec,sizeof(movCartao),tam,receber); //lê arquivo
    fclose(receber); //fecha
    bdCRec[tam].cod=-1; //marca fim
    return bdCRec;
}

//função para cadastrar novo contas a receber da memoria para o arquivo
void cadastrar_ContasReceberBD(movCartao novo){
    
    movCartao *bdCRec=dados_ContasReceber(bdCRec);
    int lenCRec=len_Conta(bdCRec);
    
    if(lenCRec!=0){
        novo.cod=bdCRec[lenCRec-1].cod+1;
    }else{
        novo.cod=1;
    }
    
    free(bdCRec);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *receber= fopen(".//Bd//ContasReceber.txt","a"); //escrita

        if(receber==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CódigoHospede;Parcela;Valor;Data
        int result= fprintf(receber,"\n%d;%d;%d;%.2f;%d;%d;%d",  //escreve novo dado
                novo.cod,novo.codChave,novo.parc,novo.valor
                ,novo.vencimento.dia_f,novo.vencimento.mes_f,novo.vencimento.ano_f);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(receber);//fecha

        system("clear");
        printf("|===CONTA CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *receber= fopen(".//Bd//ContasReceber.bin","ab");
    
    if(receber==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(movCartao),1,receber); //escreve no arquivo
    fclose(receber); //fecha arquivo

    system("clear");
    printf("|===CONTA CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de contas a receber da memoria para o arquivo
void atualizar_ContasReceberBD(movCartao *bdCRec,int lenCRec){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *receber= fopen(".//Bd//ContasReceber.txt","w");  //recria

        if(receber==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(receber,"Código;CódigoHóspede;Parcela;Valor;Data");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenCRec;i++){  //escreve dados
           int result= fprintf(receber,"\n%d;%d;%d;%.2f;%d;%d;%d",bdCRec[i].cod,bdCRec[i].codChave,bdCRec[i].parc
           ,bdCRec[i].valor,bdCRec[i].vencimento.dia_f,bdCRec[i].vencimento.mes_f,bdCRec[i].vencimento.ano_f); //escreve dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(receber);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *receber= fopen(".//Bd//ContasReceber.bin","wb");  //recria arquivo do zero
    
    if(receber==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdCRec,sizeof(movCartao),lenCRec,receber); //escreve no arquivo
    
    fclose(receber);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de vendas na mémoria
venda *dados_Vendas(venda *bdVen){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *vendas = fopen(".//Bd//Vendas.txt","r"); //leitura

        if(vendas==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdVen=calloc(1,sizeof(venda)); //vetor dinamico
        
        fgets(linha,500,vendas);
        
        while(!feof(vendas)){  //passa linhas
            i++;
            bdVen=realloc(bdVen,i*sizeof(venda));  //realoca
            fgets(linha,500,vendas);
            
            token=strtok(linha,";");
            bdVen[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            bdVen[i-1].codPro=atoi(token);
            
            token=strtok(NULL,";");
            strcpy(bdVen[i-1].pag,token);
            
            token=strtok(NULL,";");
            bdVen[i-1].valor=atof(token);
            
        }
        fclose(vendas);//fecha
        
        bdVen=realloc(bdVen,(i+1)*sizeof(venda));
        bdVen[i].cod=-1;//fim
        return bdVen;//retorna BD
    }
    FILE *vendas = fopen(".//Bd//Vendas.bin","rb");  //leitura do arquivo
    
    if(vendas==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(vendas,0,SEEK_END); //fim
    long tam=ftell(vendas)/sizeof(venda); //tamanho
    fseek(vendas,0,SEEK_SET); //inicio
        
    bdVen=calloc(tam+1,sizeof(venda)); //aloca
        
    fread(bdVen,sizeof(venda),tam,vendas); //lê arquivo
    fclose(vendas); //fecha
    bdVen[tam].cod=-1; //marca fim
    return bdVen;
}

//função para cadastrar novo venda da memoria para o arquivo
void cadastrar_VendasBD(venda novo){
    
    venda *bdVen=dados_Vendas(bdVen);
    int lenVen=len_Ven(bdVen);
    
    novo.cod=lenVen+1;
    
    free(bdVen);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *vendas= fopen(".//Bd//Vendas.txt","a"); //escrita

        if(vendas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CódigoProduto;Pagamento;Valor
        int result= fprintf(vendas,"\n%d;%d;%s;%.2f",  //escreve novo dado
                novo.cod,novo.codPro,novo.pag,novo.valor);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(vendas);//fecha

        system("clear");
        printf("|===VENDA CADASTRADA COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *vendas= fopen(".//Bd//Vendas.bin","ab");
    
    if(vendas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(venda),1,vendas); //escreve no arquivo
    fclose(vendas); //fecha arquivo

    system("clear");
    printf("|===VENDA CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de venda da memoria para o arquivo
void atualizar_VendasBD(venda *bdVen,int lenVen){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *vendas= fopen(".//Bd//Vendas.txt","w");  //recria

        if(vendas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(vendas,"Código;CódigoProduto;FormaDePagamento;Valor");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenVen;i++){  //escreve dados
           int result= fprintf(vendas,"\n%d;%d;%s;%.2f",  //escreve novo dado
                bdVen[i].cod,bdVen[i].codPro,bdVen[i].pag,bdVen[i].valor); //escreve dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(vendas);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *vendas= fopen(".//Bd//Vendas.bin","wb");  //recria arquivo do zero
    
    if(vendas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdVen,sizeof(venda),lenVen,vendas); //escreve no arquivo
    
    fclose(vendas);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de contas a pagar na mémoria
movCartao *dados_ContasPagar(movCartao *bdCPag){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *pagar = fopen(".//Bd//ContasPagar.txt","r"); //leitura

        if(pagar==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0;
        char linha[500], *token;
        
        bdCPag=calloc(1,sizeof(movCartao)); //vetor dinamico
        
        fgets(linha,500,pagar);
        
        while(!feof(pagar)){  //passa linhas
            i++;
            bdCPag=realloc(bdCPag,i*sizeof(movCartao));  //realoca
            fgets(linha,500,pagar);
            
            token=strtok(linha,";");
            bdCPag[i-1].cod=atoi(token);   //coleta dados
            
            token=strtok(NULL,";");
            bdCPag[i-1].codChave=atoi(token); 
            
            token=strtok(NULL,";");
            bdCPag[i-1].parc=atoi(token);
            
            token=strtok(NULL,";");
            bdCPag[i-1].valor=atof(token);
            
            token=strtok(NULL,";");
            bdCPag[i-1].vencimento.dia_f=atoi(token);
            
            token=strtok(NULL,";");
            bdCPag[i-1].vencimento.mes_f=atoi(token);
            
            token=strtok(NULL,";");
            bdCPag[i-1].vencimento.ano_f=atoi(token);
            
            bdCPag[i-1].vencimento.dia_i=NULL;
            bdCPag[i-1].vencimento.mes_i=NULL;
            bdCPag[i-1].vencimento.ano_i=NULL;
        }
        fclose(pagar);//fecha
        
        bdCPag=realloc(bdCPag,(i+1)*sizeof(movCartao));
        bdCPag[i].cod=-1;//fim
        return bdCPag;//retorna BD
    }
    FILE *pagar = fopen(".//Bd//ContasPagar.bin","rb");  //leitura do arquivo
    
    if(pagar==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(pagar,0,SEEK_END); //fim
    long tam=ftell(pagar)/sizeof(movCartao); //tamanho
    fseek(pagar,0,SEEK_SET); //inicio
        
    bdCPag=calloc(tam+1,sizeof(movCartao)); //aloca
        
    fread(bdCPag,sizeof(movCartao),tam,pagar); //lê arquivo
    fclose(pagar); //fecha
    bdCPag[tam].cod=-1; //marca fim
    return bdCPag;
}

//função para cadastrar novo contas a pagar da memoria para o arquivo
void cadastrar_ContasPagarBD(movCartao novo){
    
    movCartao *bdCPag=dados_ContasPagar(bdCPag);
    int lenCPag=len_Conta(bdCPag);
    
    if(lenCPag!=0){
        novo.cod=bdCPag[lenCPag-1].cod+1;
    }else{
        novo.cod=1;
    }
    
    free(bdCPag);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *pagar= fopen(".//Bd//ContasPagar.txt","a"); //escrita

        if(pagar==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CódigoFornecedor;Parcela;Valor;Data
        int result= fprintf(pagar,"\n%d;%d;%d;%.2f;%d;%d;%d",  //escreve novo dado
                novo.cod,novo.codChave,novo.parc,novo.valor,novo.vencimento.dia_f,novo.vencimento.mes_f,novo.vencimento.ano_f);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        fclose(pagar);//fecha

        system("clear");
        printf("|===CONTA CADASTRADO COM SUCESSO===|\n\n");
        return;
    }
    
    FILE *pagar= fopen(".//Bd//ContasPagar.bin","ab");
    
    if(pagar==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(movCartao),1,pagar); //escreve no arquivo
    fclose(pagar); //fecha arquivo

    system("clear");
    printf("|===CONTA CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de contas a pagar da memoria para o arquivo
void atualizar_ContasPagarBD(movCartao *bdCPag,int lenCPag){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *pagar= fopen(".//Bd//ContasPagar.txt","w");  //recria

        if(pagar==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(pagar,"Código;CódigoFornecedor;Parcela;Valor;Data");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenCPag;i++){  //escreve dados
           int result= fprintf(pagar,"\n%d;%d;%d;%.2f;%d;%d;%d",bdCPag[i].cod,bdCPag[i].codChave,bdCPag[i].parc,bdCPag[i].valor
                ,bdCPag[i].vencimento.dia_f,bdCPag[i].vencimento.mes_f,bdCPag[i].vencimento.ano_f); //escreve dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }

        fclose(pagar);//fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *pagar= fopen(".//Bd//ContasPagar.bin","wb");  //recria arquivo do zero
    
    if(pagar==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdCPag,sizeof(movCartao),lenCPag,pagar); //escreve no arquivo
    
    fclose(pagar);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para carregar o banco de dados de nota entrada na mémoria
notaEntrada *dados_NotasEntrada(notaEntrada *bdNotas){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
     
    if(arq!=NULL){
        fclose(arq);
        FILE *notas = fopen(".//Bd//NotasEntrada.txt","r"); //leitura

        if(notas==NULL){
            printf("!===ERRO NA ABERTURA DO ARQUIVO===!");
            exit(1);
        }

        int i=0,j;
        char linha[500], *token;
        
        bdNotas=calloc(1,sizeof(notaEntrada)); //vetor dinamico
        
        fgets(linha,500,notas);
        
        while(!feof(notas)){ //passa pelas linhas
            i++;
            bdNotas=realloc(bdNotas,i*sizeof(notaEntrada)); //realoca vetor
            fgets(linha,500,notas);
            
            token=strtok(linha,";");
            bdNotas[i-1].cod=atoi(token);    //coleta dados
            
            token=strtok(NULL,";");
            bdNotas[i-1].codFor=atoi(token);
            
            token=strtok(NULL,";");
            bdNotas[i-1].vFrete=atof(token);
            
            token=strtok(NULL,";");
            bdNotas[i-1].vImp=atof(token);
            
            token=strtok(NULL,";");
            bdNotas[i-1].vTotal=atof(token);
            
            j=0;
            compra *temp=calloc(1,sizeof(compra)); //vetor dinamico para comandas
            
            token=strtok(NULL,";"); //lê proximo token, se NULL não há comandas
            while(token!=NULL){
                j++;
                temp=realloc(temp,j*sizeof(compra));
                
                temp[j-1].cod=atoi(token); //armazena token lido no fim do ciclo, ou antes dele
                
                token=strtok(NULL,";");  
                temp[j-1].qtd=atoi(token);
                
                token=strtok(NULL,";");  
                temp[j-1].vUnid=atof(token);
                
                token=strtok(NULL,";");  //lê proximo token, se diferente de NULL, repete ciclo
            }
            
            temp=realloc(temp,(j+1)*sizeof(compra));
            temp[j].cod=-1;
            
            bdNotas[i-1].prod=temp;
            
        }
        fclose(notas);//fecha
        
        bdNotas=realloc(bdNotas,(i+1)*sizeof(notaEntrada));
        bdNotas[i].cod=-1; //fim
        return bdNotas; //retorna BD
    }
    
    FILE *notas = fopen(".//Bd//NotasEntrada.bin","rb");  //leitura do arquivo
    
    if(notas==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(notas,0,SEEK_END);  //fim
    long tam=ftell(notas)/sizeof(notaEntrada);  //tamanho
    fseek(notas,0,SEEK_SET);  //inicio
        
    bdNotas=calloc(tam+1,sizeof(notaEntrada)); //aloca
        
    fread(bdNotas,sizeof(notaEntrada),tam,notas); //lê arquivo
    fclose(notas); //fecha
    bdNotas[tam].cod=-1; //marca fim
    
    FILE *compras = fopen(".//Bd//Compras.bin","rb");  //leitura do arquivo
    
    if(compras==NULL){
        printf("!==ERRO AO ABRIR ARQUIVO==!\n\n");
        exit(1);
    }
    
    fseek(compras,0,SEEK_END);  //fim
    tam=ftell(compras)/sizeof(compra);  //tamanho
    fseek(compras,0,SEEK_SET);  //inicio
        
    compra *bdCom=calloc(tam,sizeof(compra)); //aloca
        
    fread(bdCom,sizeof(compra),tam,compras); //lê arquivo
    fclose(compras); //fecha

    associa_Compras(bdNotas,bdCom);
    
    return bdNotas;
}

//função para cadastrar nova nota da memoria para o arquivo
void cadastrar_NotaEntradaBD(notaEntrada novo){
    
    notaEntrada *bdNotas=dados_NotasEntrada(bdNotas);
    int lenNotas=len_Notas(bdNotas);
    
    novo.cod=lenNotas+1;
    
    free(bdNotas);
    
    FILE *arq=fopen(".//Bd//Texto.txt","r");  //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        FILE *notas= fopen(".//Bd//NotasEntrada.txt","a"); //escrita

        if(notas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        //Código;CódigoFornecedor;Frete;Imposto;Total;Compras
        int result= fprintf(notas,"\n%d;%d;%.2f;%.2f;%.2f",novo.cod,novo.codFor,novo.vFrete,novo.vImp,novo.vTotal); //escreve novo dado

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
        
        int lenComp=len_Comp(novo.prod);
        
        for(int i=0;i<lenComp;i++){
            result= fprintf(notas,";%d;%d;%.2f",novo.prod[i].cod,novo.prod[i].qtd,novo.prod[i].vUnid); //escreve novo dado

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        
        fclose(notas); //fecha


        printf("|===NOTA CADASTRADA COM SUCESSO===|\n\n");
        return;
    }
    FILE *notas= fopen(".//Bd//NotasEntrada.bin","ab");
    
    if(notas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(&novo,sizeof(notaEntrada),1,notas);  //escreve no arquivo
    fclose(notas); //fecha arquivo
    
    FILE *compras= fopen(".//Bd//Compras.bin","ab");  //abre arquivo para vetores de comandas
                                                    
    if(compras==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    int lenComp=len_Comp(novo.prod);
    fwrite(novo.prod,sizeof(compra),lenComp+1,compras);  //escreve no arquivo
    fclose(compras); //fecha arquivo

    printf("|===CHECKIN CADASTRADO COM SUCESSO===|\n\n");
    return;
}

//função para atualizar dados de notas da memoria para o arquivo
void atualizar_NotasEntradaBD(notaEntrada *bdNotas,int lenNotas){
    
    FILE *arq=fopen(".//Bd//Texto.txt","r"); //verifica tipo de arquivo
    
    if(arq!=NULL){
        fclose(arq);
        int i=0;
        FILE *notas= fopen(".//Bd//NotasEntrada.txt","w"); //recria

        if(notas==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        int result= fprintf(notas,"Código;CódigoFornecedor;Frete;Imposto;Total;Compras"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenNotas;i++){ //escreve dados
            result= fprintf(notas,"\n%d;%d;%.2f;%.2f;%.2f",bdNotas[i].cod,bdNotas[i].codFor
                    ,bdNotas[i].vFrete,bdNotas[i].vImp,bdNotas[i].vTotal); //escreve novo dado

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        
            int lenComp=len_Comp(bdNotas[i].prod);
        
            for(int j=0;j<lenComp;j++){
                result= fprintf(notas,";%d;%d;%.2f",bdNotas[i].prod[j].cod
                        ,bdNotas[i].prod[j].qtd,bdNotas[i].prod[j].vUnid); //escreve novo dado

                if(result < 0){
                    printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                    return;
                }   
            }
        }

        fclose(notas); //fecha
        system("clear");
        printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
        return;
    }
    FILE *notas= fopen(".//Bd//NotasEntrada.bin","wb");  //recria arquivo do zero
    
    if(notas==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    fwrite(bdNotas,sizeof(notaEntrada),lenNotas,notas); //escreve no arquivo
    
    fclose(notas);//fecha arquivo
    
    FILE *compras= fopen(".//Bd//Compras.bin","wb");  //recria arquivo do zero
    
    if(compras==NULL){
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    int lenComp;
    for(int i=0;i<lenNotas;i++){
        lenComp=len_Comp(bdNotas[i].prod);
        fwrite(bdNotas[i].prod,sizeof(compra),lenComp+1,compras); //escreve no arquivo
    }
    
    fclose(compras);//fecha arquivo
    system("clear");
    printf("|===OPERAÇÃO CONCLUIDA COM SUCESSO===|\n\n");
    return;
}

//função para criar um arquivo para relatorio
FILE *cria_ArquivoRelatorio(FILE *arq,char *nomeArq){
    
    if(strcmp(nomeArq,"")==0){  //se caminho do arquivo não passado, cria arquivo de forma automatica
        int i=1;
        while(i!=0){    
            char nome[35];
            char num[10];

            strcpy(nomeArq,".//Relatorios//Relatorio");     //cria diretorio do arquivo
            sprintf(num,"%d",i);

            strcat(nomeArq,num);
            strcat(nomeArq,".txt");                 //while para achar numero disponivel
                                                    //para o relatorio
            arq=fopen(nomeArq,"r");
            if(arq == NULL){    //ex: se Relatorio14.txt == NULL ent nome disponivel
                arq=fopen(nomeArq,"w"); //cria arquivo

                if(arq==NULL){
                    printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                    return NULL;
                }

                printf("|===NOME DO ARQUIVO GERADO: Relatorio%d.txt===|\n\n",i);
                return arq;     //retorna ponteiro para o arquivo
            }else{
                close(arq); 
                i++;
            }
        }
    }else{ //se caminho do arquivo foi passado apenas cria o arquivo
        arq=fopen(nomeArq,"w");
        if(arq==NULL){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return NULL;
        }
        return arq;
    }
    
}

//função para escrever relatorio de hospedes no arquivo
void relatorio_Hospedes(FILE *arq, hospede *relatorio){
    
    int lenHos=len_Hos(relatorio);
    
    int result = fprintf(arq, "Código,Nome,CPF,Telefone,Email,Sexo,Status Civil,Nascimento,Rua,Número,Complemento,Bairro,Cidade,Estado"); //escreve indice

    if (result < 0) {
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }

    for (int i = 0; i < lenHos; i++) { //percorre BD escrevendo dados no arquivo
        result = fprintf(arq, "\n%d,%s,%s,%s,%s,%s,%s,%s,%s,%d,%s,%s,%s,%s;",
                relatorio[i].cod,relatorio[i].nome,relatorio[i].cpf,relatorio[i].telefone,relatorio[i].email,relatorio[i].sexo,relatorio[i].civil,relatorio[i].nasc,
                relatorio[i].end.rua,relatorio[i].end.num,relatorio[i].end.comp,relatorio[i].end.bairro,relatorio[i].end.cidade,relatorio[i].end.estado);

        if (result < 0) {
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
    }

    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
    
}

//função para escrever relatorio de acomodações no arquivo
void relatorio_Acomodacoes(FILE *arq, acomodacao *relatorio){
    int lenAco=len_Aco(relatorio);
    
    int result= fprintf(arq,"Código,Descrição,Facilidades,CódigoCategoria"); //indice

    if (result < 0) {
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }

    for (int i = 0; i < lenAco; i++) { //escreve dados
        result = fprintf(arq, "\n%d,%s,%s,%d",
                relatorio[i].cod, relatorio[i].desc, relatorio[i].fac, relatorio[i].cat);

        if (result < 0) {
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
    }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de reservas no arquivo
void relatorio_Reservas(FILE *arq, reserva *relatorio){
    int lenRes=len_Res(relatorio);
    
    int result= fprintf(arq,"Código,Quarto,CódigoHospede,DataInicial,DataFinal"); //indice

    if (result < 0) {
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }
    
    for(int i=0;i<lenRes;i++){ //escreve dados
        result= fprintf(arq,"\n%d,%d,%d,%d/%d/%d,%d/%d/%d",relatorio[i].cod,relatorio[i].quarto
                ,relatorio[i].codHos,relatorio[i].periodo.dia_i,relatorio[i].periodo.mes_i,relatorio[i].periodo.ano_i
                ,relatorio[i].periodo.dia_f,relatorio[i].periodo.mes_f,relatorio[i].periodo.ano_f);

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
    }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de movimento de acomodações no arquivo
void relatorio_movAcomodacoes(FILE *arq, movAcomodacao *relatorio){
    int lenMovA=len_MovA(relatorio);
    
    int result= fprintf(arq,"Código,Código Acomodação,Número Diarias,Valor");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(int i=0;i<lenMovA;i++){  //escreve dados
           int result= fprintf(arq,"\n%d,%d,%d,%.2f",  //escreve novo dado
                relatorio[i].cod,relatorio[i].codAco,relatorio[i].numDia,relatorio[i].valor);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de produtos no arquivo
void relatorio_Produtos(FILE *arq, produto *relatorio){
    int lenPro=len_Pro(relatorio);
    
    int result= fprintf(arq,"Código,Descrição,EstoqueMin,Estoque,Custo,Venda");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(int i=0;i<lenPro;i++){  //escreve dados
            result= fprintf(arq,"\n%d,%s,%d,%d,%.2f,%.2f",
                relatorio[i].cod,relatorio[i].desc,relatorio[i].estmin
                ,relatorio[i].est,relatorio[i].custo,relatorio[i].venda);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de vendas no arquivo
void relatorio_Vendas(FILE *arq, venda *relatorio){
    int lenVen=len_Ven(relatorio);
    
    int result= fprintf(arq,"Código,Código do Produto,Forma de Pagamento,Valor");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(int i=0;i<lenVen;i++){//escreve dados
            result= fprintf(arq,"\n%d,%d,%s,%.2f",relatorio[i].cod
                ,relatorio[i].codPro,relatorio[i].pag,relatorio[i].valor);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de Contas a Receber no arquivo
void relatorio_ContasReceber(FILE *arq, movCartao *relatorio){
    int lenCRec=len_Conta(relatorio);
    
    int result= fprintf(arq,"Código,Código do Hóspede,Parcela,Valor,Data");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(int i=0;i<lenCRec;i++){//escreve dados
            result= fprintf(arq,"\n%d,%d,%d,%.2f,%d/%d/%d",relatorio[i].cod,relatorio[i].codChave
                ,relatorio[i].parc,relatorio[i].valor,relatorio[i].vencimento.dia_f
                ,relatorio[i].vencimento.mes_f,relatorio[i].vencimento.ano_f);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de Contas a Pagar no arquivo
void relatorio_ContasPagar(FILE *arq, movCartao *relatorio){
    int lenCPag=len_Conta(relatorio);
    
    int result= fprintf(arq,"Código,Código do Fornecedor,Parcela,Valor,Data");//indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(int i=0;i<lenCPag;i++){//escreve dados
            result= fprintf(arq,"\n%d,%d,%d,%.2f,%d/%d/%d",relatorio[i].cod,relatorio[i].codChave
                ,relatorio[i].parc,relatorio[i].valor,relatorio[i].vencimento.dia_f
                ,relatorio[i].vencimento.mes_f,relatorio[i].vencimento.ano_f);

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}

//função para escrever relatorio de movimento do caixa no arquivo
void relatorio_movCaixa(FILE *arq, movCaixa *relatorio){
    int lenMovC=len_MovC(relatorio);
    

    int result = fprintf(arq, "Código,Valor,Tipo de Transação,FormaDePagamento,Data"); //indice

    if (result < 0) {
        printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
        return;
    }

    for (int i = 0; i < lenMovC; i++) { //escreve dados
        int result = fprintf(arq, "\n%d,%.2f,%s,%s,%d/%d/%d", relatorio[i].cod, relatorio[i].valor, relatorio[i].tipo
                , relatorio[i].pag, relatorio[i].dataTrans.dia_f, relatorio[i].dataTrans.mes_f, relatorio[i].dataTrans.ano_f);

        if (result < 0) {
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }
    }
    
    
    fclose(arq); //fecha arquivo

    printf("|===RELATÓRIO CRIADO COM SUCESSO===|\n\n");
    return;
}