#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LEGAJO_LEN 8+1

/*Tarea:
corregir funcion carga_catedra, print_catedra, free_catedra(porque catedra ahora tiene cursos, no alumnos)
*/
typedef struct
{
	char * nombre;
	char * apellido;
	char legajo [LEGAJO_LEN];
}alumno_t;

typedef struct 
{
	char * nombre_curso;
	alumno_t * alumnos;
	char cant_alumnos;

}curso_t;

typedef struct
{
	curso_t * nombre_curso;
	char cant_cursos;
	char * asignatura;
}catedra_t;

typedef struct
{
	catedra_t *catedras;
	char cant_catedras;
	char *nombre_carrera;
}carrera_t;


void cargar_alumno (alumno_t * alumno);
void print_alumno (alumno_t * alumno);
void free_alumno (alumno_t * alumno);

void cargar_catedra (catedra_t * catedra);
void print_catedra (catedra_t * catedra);
void free_catedra (catedra_t * catedra);

void cargar_carrera (carrera_t *carrera);
void print_carrera (carrera_t *carrera);
void free_carrera (carrera_t *carrera);

void cargar_curso (curso_t * curso);
void print_curso (curso_t * curso);
void free_curso (curso_t * curso);

int main ()
{
	
	carrera_t electronica;
	cargar_carrera (&electronica);
	print_carrera (&electronica);
	free_carrera (&electronica);
	

	return 0;
}

void cargar_alumno (alumno_t * alumno)
{
	char string [100];

	printf ("ingrese el legajo: \n");
	scanf ("%s", alumno->legajo);

	printf ("Ingrese el nommbre:\n");
	scanf ("%s", string);
	alumno->nombre = (char *) malloc ((strlen(string)+1) * sizeof(char));
	strcpy (alumno->nombre, string);
	
	printf ("Ingrese el apellido: \n");
	scanf ("%s", string);
	alumno->apellido = (char *) malloc ((strlen(string)+1) * sizeof (char));
	strcpy (alumno->apellido, string);
}

void cargar_catedra (catedra_t * catedra)
{
	char string [100];

	printf ("Ingrese materia: \n");
	scanf ("%s", string);
	catedra->asignatura = (char *) malloc ((strlen(string)+1) * sizeof (char));
	strcpy (catedra->asignatura, string);

	printf ("Ingrese cantidad de cursos: \n");
	scanf ("%hhd", &catedra->cant_cursos);
	catedra->nombre_curso = (curso_t *) malloc ((catedra->cant_cursos) * sizeof (curso_t));

	for (int i = 0;i < (catedra->cant_cursos);i++)
	{	
		cargar_alumno (&catedra->nombre_curso[i]);
	}
}

void cargar_carrera (carrera_t *carrera)
{
	char string [100];
	
	printf ("Ingrese carrera: \n");
	scanf ("%s", string);
	carrera->nombre_carrera = (char *) malloc ((strlen(string)+1) * sizeof (char));
	strcpy (carrera->nombre_carrera, string);
	
	printf("Ingrese cantidad de catedras de la carrera\n");
	scanf("%hhd", &carrera->cant_catedras);
	
	carrera->catedras = (catedra_t *) malloc ((carrera->cant_catedras) * sizeof (catedra_t));

	
	for (int i = 0; i < (carrera->cant_catedras); i++){
		cargar_catedra (&carrera->catedras[i]);
	}
}

void cargar_curso (curso_t * curso)
{
	char string [100];

	printf ("Ingrese el nombre del curso: \n");
	scanf ("%d", string);
	curso->nombre_curso = (char *) malloc ((strlen(string)+1) * sizeof(char));
	strcpy (curso->nombre_curso,string);

	printf ("Ingrese la cantidad de alumnos: \n");
	scanf ("%hhd", &cruso->cant_alumnos);
	curso->alumnos = (alumno_t *) malloc ((curso->cant_alumnos) * sizeof (alumnos_t));
	
	for (int i = 0;i < (curso->cant_alumnos);i++)
	{
		cargar_alumno (&curso->alumnos[i]);
	}
}

void print_alumno (alumno_t * alumno)
{
	printf ("Nombre: %s\n", alumno->nombre);
	printf ("Apellido: %s\n", alumno->apellido);
	printf ("Legajo: %s\n", alumno->legajo);
}

void print_catedra (catedra_t * catedra)
{
	printf ("Asignatura: %s\n", catedra->asignatura);
	for (int i = 0;i < (catedra->cant_cursos);i++)
	{
		printf ("Curso: \n");
		print_alumno (&catedra->nombre_curso[i]);
	}
}

void print_carrera (carrera_t *carrera)
{
	printf("Carrera: %s\n", carrera->nombre_carrera);
	for (int i = 0; i < (carrera->cant_catedras) ; i++){
		printf("Catedra[%d]: \n",i);
		print_catedra (&carrera->catedras[i]);
	}
}

void print_curso (curso_t * curso)
{
	printf ("Curso: %s \n", curso->nombre_curso);
	for (int i = 0;i < (curso->cant_alumnos);i++)
	{
		print_alumno (&curso->alumnos[i]);
	}
}

void free_alumno (alumno_t * alumno)
{
	free (alumno->nombre);
	free (alumno->apellido);
}

void free_catedra (catedra_t * catedra)
{
	free (catedra->asignatura);
	for (int i = 0;i < (catedra->cant_cursos);i++)
	{
		free_alumno (&catedra->nombre_curso[i]);
	}
	free (catedra->nombre_curso);
}

void free_carrera (carrera_t *carrera)
{
	for (int i = 0 ; i < (carrera->cant_catedras); i++){
		
		free_catedra (&carrera->catedras[i]);
	}
	free (carrera->catedras);
	
	free (carrera->nombre_carrera);
}

void free_curso (curso_t * curso)
{
	for (int i = 0;i < (curso->cant_alumnos);i++)
	{
		free_alumno (&curso->alumnos[i]);
	}
	free (curso->nombre_curso);
}