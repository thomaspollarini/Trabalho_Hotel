/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 *
 */


#include "bancoDados.h"

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

        FILE *reservas=fopen(".//Bd//Reservas.txt","r");    //cria arquivo de dados para fornecedores
        if(reservas==NULL){
            reservas=fopen(".//Bd//Reservas.txt","w");

            if(reservas==NULL){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }

            int result= fprintf(reservas,"Código;Quarto;DataInicial;DataFinal"); //formatação dos dados

            if(result < 0){
                printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
                return;
            }
        }
        fclose(reservas);
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
    
    FILE *reservas=fopen(".//Bd//Reservas.bin","rb");    //cria arquivo de dados para fornecedores
    if(reservas==NULL){
        reservas=fopen(".//Bd//Reservas.bin","wb");
    }
    fclose(reservas);
    
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
                printf("Erro na escrita\n");
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
        bdOpe[1].cod=-1; //sinaliza fim do banco de dados
        return bdOpe; //retorna banco de dados de operadores
        
    }else{
        fseek(user,0,SEEK_END);  //move pontenteiro para fim do arquivo
        long tam=ftell(user)/sizeof(operador);  //calcula numero de objetos no arquivo
        fseek(user,0,SEEK_SET);  //retorna ponteiro para inicio
        
        bdOpe=calloc(tam,sizeof(operador));  //inicializa bd
        
        fread(bdOpe,sizeof(operador),tam,user);  //lê arquivo
        fclose(user); //fecha arquivo
        bdOpe[tam].cod=-1;  //marca de fim
        return bdOpe;
    }
}

//função para cadastrar novo operador da memoria para o arquivo
void cadastrar_OperadorBD(operador novo){
    
    FILE *arq=fopen(".//Texto.txt","r");  //verifica tipo de arquivo
    
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
                                  "%d;Hora checkin\n%d;Hora checkout\n%f;Margem lucro\n"
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
        
    bdHos=calloc(tam,sizeof(hospede));  //aloca bd
        
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
        
    bdCat=calloc(tam,sizeof(categoria)); //aloca bd
        
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
        
    bdAco=calloc(tam,sizeof(acomodacao)); //aloca
        
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
        
    bdPro=calloc(tam,sizeof(produto)); //aloca
        
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
        
    bdFor=calloc(tam,sizeof(fornecedor)); //aloca
        
    fread(bdFor,sizeof(fornecedor),tam,fornecedores); //lê arquivo
    fclose(fornecedores); //fecha
    bdFor[tam].cod=-1; //marca fim
    return bdFor;
}

//função para cadastrar novo produto da memoria para o arquivo
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
        
    bdRes=calloc(tam,sizeof(reserva)); //aloca
        
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
        //Código;Quarto;DataInicial;DataFinal
        int result= fprintf(reservas,"\n%d;%d;%d;%d;%d;%d;%d;%d",novo.cod,novo.quarto,novo.periodo.dia_i
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

        int result= fprintf(reservas,"Código;Quarto;DataInicial;DataFinal"); //indice

        if(result < 0){
            printf("!==ERRO AO SALVAR ARQUIVO==!\n\n");
            return;
        }

        for(i=0;i<lenRes;i++){ //escreve dados
            result= fprintf(reservas,"\n%d;%d;%d;%d;%d;%d;%d;%d",bdRes[i].cod,bdRes[i].quarto,bdRes[i].periodo.dia_i
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