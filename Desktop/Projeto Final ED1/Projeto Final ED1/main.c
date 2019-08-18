#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
	char* retornaExtensao(int indiceArgumento){
		int aux = strlen(argv[indiceArgumento])-1;
		int u=aux-3;
		int k=0;
		static char ext[5];
		for(u; u<=aux;u++){
			ext[k] = argv[indiceArgumento][u];
			k++;
		}
		return ext;
	}

    int countlines (FILE *fin)
    {
        int  nlines  = 0;
        char line[BUFFSIZE];

        while(fgets(line, BUFFSIZE, fin) != NULL) {
            nlines++;
        }

        return nlines;
    }

int getColumn(FILE* fp)
{
    char buff[BUFSIZ]={0};
    int count=0;
    char *p;

    if(NULL==fgets(buff, BUFSIZ, fp))
        return -1;
    rewind(fp);
    for(p=buff;NULL!=strtok(p, " \t\n");p=NULL)
        ++count;
    return count;
}

	if (strcmp(argv[1],"-open")==0){
		char ext[5];
		if((strcmp(retornaExtensao(2), ".txt")==0) && argc == 3){
			printf("\n");

			FILE *fp, *file, *file2;
			char path[100] = "C:\\Users\\Matheus\\Desktop\\";
			strcat(path, argv[2]);
			fp = fopen(path, "r");
			file = fopen(path, "r");
			file2 = fopen(path, "r");

			int countLines = countlines(file);
			int countColumns = getColumn(file2);

			fclose(file);
            fclose(file2);

            int i, j;
			int** mat = malloc(1000000*sizeof(int*));

            for(i=0;i<1000000;++i){
                mat[i]=malloc(50*sizeof(int));
            }
			for(i=0; i<countLines; i++){
                for(j=0; j<countColumns; j++){
                    if(!fscanf(fp, "%d", &mat[i][j])){
                        break;
                    }
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
			}
			fclose(fp);
		}
		else if(strcmp(retornaExtensao(2), ".imm")==0){
			printf("\nOpcao .imm");
		}
		else{
			printf("\nOpcao invalida");
		}
	}
	else if (strcmp(argv[1], "-convert")==0){
		printf("CONVERT");
		if((strcmp(retornaExtensao(2),".txt")!=0)||(strcmp(retornaExtensao(3),".imm")!=0)){
			printf("\nINVALID REQUEST");
		} else{
			printf("\nVALID REQUEST");
		}
	}
	else if (strcmp(argv[1], "-segment")==0){
		printf("\nsegment");
		if(strcmp(argv[2],"thr")==0){
			if((strcmp(retornaExtensao(3),".imm")!=0)||(strcmp(retornaExtensao(4),".imm")!=0)){
				printf("\nINVALID REQUEST THR");
			} else{
				printf("\nVALID REQUEST THR");
			}
		} else{
			printf("INVALID OPTIONS FOR SEGMENT");
		}
	}
	else if (strcmp(argv[1], "-cc")==0){
		printf("\ncc");
		if(strcmp(argv[3],"outfile")==0){
			printf("\nVALID REQUEST CC OUTFILE");
		}
		if((strcmp(retornaExtensao(2),".imm")!=0)){
			printf("\nINVALID REQUEST CC");
		}
	}
	else if (strcmp(argv[1], "-lab")==0){
		printf("\nlab");
		if((strcmp(retornaExtensao(2),".txt")!=0)||(strcmp(retornaExtensao(3),".txt")!=0)){
			printf("\nINVALID REQUEST LAB");
		} else{
			printf("\nVALID REQUEST LAB");
		}
	}
	else{
		printf("\nComando nao reconhecido");
	}

	return 0;
}

