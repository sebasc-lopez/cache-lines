#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>


const int a = 2, b = 2;

void generarArreglo(double **matriz, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matriz[i][j] = rand() % 5 + 1;
        }
    }
}

/*void imprimirArreglo(int **matriz, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}*/

double **crearMatriz(int row, int col)
{
    double **matrix = malloc(row * sizeof(double *));
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = malloc(row * sizeof(double *));
    }
    return matrix;
}

double **multiplicar(double **m1, double **m2, int rows, int cols)
{
    if (cols != rows)
        return NULL;

    double ** ret = crearMatriz(rows, cols);

    int i, j, k;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            for (k = 0; k < cols; k++)
            {
                ret[i][j] += m1[j][k] * m2[i][k];
            }
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    srand(time(0));

    int rows, cols;
    rows = strtol(argv[1], NULL, 10);
    cols = strtol(argv[1], NULL, 10);
    double **matriz1 = malloc(rows * sizeof(double *));
    double **matriz2 = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i)
        matriz2[i] = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i)
        matriz1[i] = malloc(rows * sizeof(double *));
    generarArreglo(matriz1, rows, cols);
    //imprimirArreglo(matriz1, rows, cols);
    generarArreglo(matriz2, rows, cols);
    //imprimirArreglo(matriz2, rows, cols);
    struct timeval inicio;
    struct timeval fin;
    double milisegundosFinal;
    long segundos, milisegundos;
    gettimeofday(&inicio, 0);

    double **res = multiplicar(matriz1, matriz2, rows, cols);

    gettimeofday(&fin, 0);

    segundos = fin.tv_sec - inicio.tv_sec;
    milisegundos = fin.tv_usec - inicio.tv_usec;
    milisegundosFinal = ((segundos)*1000 + milisegundos / 1000.0);

    printf("Tiempo de ejecucion:\t");
    printf("%.16g milisegundos\n", milisegundosFinal);

    FILE *archivo;
    archivo = fopen("secuencial.txt", "a");
    fprintf(archivo, "%d\n", rows);
    fprintf(archivo, "%.16g\n", milisegundosFinal);
    //imprimirArreglo(res, rows, cols);
    return 0;
}