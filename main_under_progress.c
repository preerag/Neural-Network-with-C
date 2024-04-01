#include <stdio.h>
#include <stdlib.h>
int *matrix(int rows, int columns)
{
    int *mat;
    mat = (int *)malloc(sizeof(int) * rows * columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            mat[(i * columns) + j] = rand() % (20);
        }
    }
    mat[4] = 4;
    return mat;
}

int *dot_product(int *mat1, int rows1, int columns1, int *mat2, int rows2, int columns2)
{
    if (columns1 != rows2)
    {
        printf("Incompatible Matrixes\n");
        return 0;
    }
    else
    {
        int *dot_mat;
        dot_mat = (int *)malloc(sizeof(int) * rows1 * columns2);
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                dot_mat[(i * columns2) + j] = 0;
            }
        }
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                for (int k = 0; k < columns1; k++)
                {
                    dot_mat[(i * columns2) + j] = dot_mat[(i * columns2) + j] + (mat1[(i * columns1) + k] * mat2[k]);
                }
            }
        }
        return dot_mat;
    }
}

int *mat_sum(int *mat1, int rows1, int columns1, int *mat2, int rows2, int columns2)
{
    if (rows1 != rows2 && columns1 != columns2)
    {
        printf("Matrices incompatible for Addition\n");
        return 0;
    }
    else
    {
        int *sum_mat;
        sum_mat = (int *)malloc(sizeof(int) * rows1 * columns1);
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns1; j++)
            {
                sum_mat[(i * columns1) + j] = mat1[(i * columns1) + j] + mat2[(i * columns1) + j];
            }
        }
        return sum_mat;
    }
}

int cost(int *mat1,int rows1,int columns1,int *mat2,int rows2,int columns2)
{
    if(rows1 != rows2 && columns1 != columns2)
    {
        printf("Incompatible matrices\n");
        return 0;
    }
    else
    {
        int cost = 0;
        for(int i = 0;i<rows1;i++)
        {
            for(j = 0;j<columns1;j++)
            {
                cost = cost + ((mat1[(i*columns1)+j]-mat2[(i*columns1)+j])*(mat1[(i*columns1)+j]-mat2[(i*columns1)+j]));
            }
        }
        return cost;
    }
}
int main()
{
    int rows1 = 10;
    int columns1 = 10;
    int rows2 = 10;
    int columns2 = 1;
    int *mat_x, *mat_y, *dot_mat_out,*bias_mat,*sum_mat;
    mat_x = matrix(rows1, columns1);
    mat_y = matrix(rows2, columns2);
    bias_mat = matrix(rows2,columns2);
    printf("Mat_x\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            printf("%d\t", mat_x[(i * columns1) + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Mat_y\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            printf("%d\t", mat_y[(i * columns2) + j]);
        }
        printf("\n");
    }
    printf("\n");
    dot_mat_out = dot_product(&mat_x[0], rows1, columns1, &mat_y[0], rows2, columns2);
    if (dot_mat_out != NULL)
    {
        printf("Dot_Mat\n");

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("%d\t", dot_mat_out[(i * columns2) + j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("Bias_mat\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            printf("%d\t", bias_mat[(i * columns2) + j]);
        }
        printf("\n");
    }
    printf("\n");
    sum_mat = mat_sum(&dot_mat_out[0], rows1, columns2, &bias_mat[0], rows2, columns2);
    if (sum_mat != NULL)
    {
        printf("Sum_Mat\n");

        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("%d\t", sum_mat[(i * columns2) + j]);
            }
            printf("\n");
        }
    }
    return 0;
}
