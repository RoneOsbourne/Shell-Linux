/*
Informações técnicas

Um comando é entrado e se a string for não-nula, mantem-se o comando no histórico de comandos.
Parsing:  o parsing é o ato de "quebrar" os comandos em palavras/strings individuais.
Devemos checar se o usuário executou um comando built-in.
Executamos os comandos fazendo um fork e chamando o comando execvp
Imprimir o nome do diretório (pasta) atual e solicitar para a próxima entrada
O prompt pode ser um ou mais ">", ou outro de sua escolha.

Dica, você pode, para manter o histórico dos comandos, recuperar o histórico dos comandos utilizando 
as "setinhas" e suportando o "autocompletar" usando a tecla tab, utilizar a biblioteca readline:

sudo apt install libreadline-dev

Outras dicas:

Para imprimir o nome do diretório atual você pode usar o comando getcwd.
Para obter o nome do usuário que está logado no momento, você pode usar getenv("USER")
O parse dos comandos pode ser feito com strsep. Se sua string for vazia (tamanho 0), ignore-a.
Depois de fazer o parse, veja se o comando é um comando built-in. Se for, execute-o. Se não, execute 
como um comando de sistema. Para verificar se é um comando builtin, armazene-os em um vetor de 
ponteiros para char e compare esse comando com todos os comandos do vetor, utilizando strcmp. 
Observe que o comando "cd" não funciona nativamente utilizando o comando execvp, então "cd" será 
um comando builtin, e será executado com o atalho para a chamada de sistema chdir(nome_do_diretorio).
Para executar um comando do sistema, você deve usar o fork, criando um processo filho e 
dentro do fork chamar o comando execvp, que executará o comando e aguardará até que ele termine.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#define CLEAR() printf("\033[H\033[J")


int main(){
  
    char *comando[];
    char *linha;
	char *diretorio;
	char s[100];  
      
    do{
        linha = readline(" <o> ");
        add_history(linha);
        strcpy(comando, linha);

        if(strcmp(comando, "hello") == 0){
            printf("Ola - %s - seja Bem Vindo a Minha Shell-Linux\n", getenv("USER"));

        }else if(strcmp(comando, "help") == 0){
        	system ("clear");
            printf("-------------------SHELL LINUX = BY RONALDO FRANCE-------------------\n");
            printf("Breves instru��es para uso dos comando:\n");
            printf("1 - Digite 'hello' para sauda��o inicial\n");
            printf("2 - Digite 'help' para auxilio\n");
            printf("3 - Digite 'exit' para sair do programa");
            printf("4 - Digite o comando 'cd' para navegar entre os diretorios\n");
            printf("\n\n-------------------OBRIGADO E TENHA UMA OTIMA EXPERIENCIA-------------------\n\n");
        /*}else if(strcmp(comando, "hello" && "help" && "exit") == 1){
            printf("\t ---------------- COMANDO INVALIDO ----------------\n");*/
        
    	}else if(strcmp(comando, "exit") == 0){
    		system("clear");
    		printf("Saindo da Aplica��o\n");
    		exit (0);
    	
    	}else if(strcmp(comando, "cd") == 0){
    		char *diretorio = (comando + 4);
    		chdir(s);
		}else{
			system (comando);
		}
    		
    		
		}
    	
    }while(strcmp(comando, "exit") != 0);
    

    
