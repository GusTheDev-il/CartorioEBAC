#include <stdio.h>	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de esp�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel pelas strings

int adicao()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digete o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo para adicionar virgula
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o nome: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a"); //atualiza o arquivo para adicionar o nome
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o sobrenome: "); 
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a"); //atualiza o arquivo para adicionar o sobrenome
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o cargo: "); //atualiza o arquivo para adicionar o cargo
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int pesquisa()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
    char cpf[40]; //variavel CPF
    char conteudo[200]; //variavel conteudo
    
    printf("Pesquisar CPF: "); //local onde o usuario vai digitar o cpf
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //consulta o arquivo cpf e l� o que estiver dentro
    
    if(file == NULL) //caso o cpf n�o existir
    {
    	printf("Arquivo n�o encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //vai ler e trazer as informa��es presentes em um arquivo
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int delet() //variavel pra deletar um determinado CPF salvo no arquivo
{	
  char cpf[40]; //variavel que salva o CPF e repassa pro usu�rio
  
  printf("Deletar CPF cadastrado: "); 
  scanf("%s",cpf);
  
  remove(cpf); //remove o arquivo relacionado ao CPF escolhido
  
  FILE *file;
  file = fopen(cpf, "r"); //abri o arquivo e l� ele 
  
  if("file == NULL") //se o arquivo n�o for encontrado, ele diz que o CPF j� foi deletado
  {
  	printf("CPF Deletado!\n");
  	system("pause");
}
  
}

int main()
{
	int opcao=0; //Vari�veis do programa
	int repeticao=1;
    char senha[]="a";
    int comparacao;
    
    printf("### Cart�rio EBAC ###\n\n"); //Inicio do menu
    printf("Digite a senha com o login de adminstrador: ");
    scanf("%s",senha);
    
    comparacao = strcmp(senha, "admin");
    
    if(comparacao == 0)
    {  
    	
     system ("cls");
    
     for(repeticao=1;repeticao=1;) //aplicando a repeti��o do programa 
     {
      	
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); //linguagem do programa

	
	  
	   printf("Escolha a op��o desejada \n\n");
  	   printf("\t1 - Pesquisar nomes\n");
	   printf("\t2 - Adicionar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Fechar Sistema\n");
	   printf("Selecione a op��o: "); //fim do menu
	
      scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
      system("cls"); //Dando fluidez para o programa
     
     switch(opcao) //Fun��o das variaveis 
     {
    	
        case 1:
        pesquisa();	
     	break;
	
    	case 2:
     	adicao();
     	break;
	
    	case 3:
    	delet();
    	break;	
	
    	case 4:
    	printf("Obrigado por acessar o cart�rio EBAC :)\n");
     	return 0;
    	break;	
	 
    	default:
     	printf("Op��o invalida!\n");
    	system("pause");
	     break;
     } //fim da repeti��o do programa
    }
 } 
 
    else
	  printf("senha incorreta!"); 
}
