#include <stdio.h>

typedef struct alu{
	int idAluno; // id da aluno
	char nome[100]; // nome do aluno
	char sexo; // sexo do aluno
} Aluno;

typedef struct disc{
	int idDisciplina; // id da disicplina
	int idProfessor; // id do professor responsável
	char nome[100]; // nome da disciplina
	int vagas = 40; // total de vagas da disciplina
	int qtdAlunos = 0; //guarda a quantidade de alunos matriculados
	int idAlunosMatriculados[vagas]; /* guarda o id dos alunos matriculados. */
} Disciplina;


void alunosNaoMatriculados(Aluno listaAluno, Disciplina listaDisciplinas, int vet[]);

int main(){

	Aluno listaAluno[100];
	Disciplina listaDisciplinas[5];
    int menosDeTres[100]; // LISTA DE ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS

    alunosNaoMatriculados(listaAluno, listaDisciplina, menosDeTres);
	
}

void alunosNaoMatriculados(Aluno listaAluno, Disciplina listaDisciplinas, int vet[]){
    
    int i, j, k;
    
    for (i = 0; i < 100; i ++){ // ALUNO
        
        int cont = 0;
        
        for (j = 0; j < 100; j++){ // DISCIPLINA
            
            for (k = 0; k < listaDisciplina[j].qdtAlunos; k++)
                
                if (listaAluno[i].idAluno == listaDisciplina[j].idAlunosMatriculados[k])
                cont++;
        }
        
        if (cont < 4)
            vet[i] = listaAluno[i].idAluno;
        else
            vet[i] = -1;
    }
    
    return vet;
}




