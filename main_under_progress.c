#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float *matrix(int rows, int columns)
{
    float *mat;
    mat = (float *)malloc(sizeof(float) * rows * columns);
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

float *dot_product(float *mat1, int rows1, int columns1, float *mat2, int rows2, int columns2)
{
    if (columns1 != rows2)
    {
        printf("Incompatible Matrixes\n");
        return 0;
    }
    else
    {
        float *dot_mat;
        dot_mat = (float *)malloc(sizeof(float) * rows1 * columns2);
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

float *mat_sum(float *mat1, int rows1, int columns1, float *mat2, int rows2, int columns2)
{
    if (rows1 != rows2 && columns1 != columns2)
    {
        printf("Matrices incompatible for Addition\n");
        return 0;
    }
    else
    {
        float *sum_mat;
        sum_mat = (float *)malloc(sizeof(float) * rows1 * columns1);
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

float cost(float *mat1, int rows1, int columns1, float *mat2, int rows2, int columns2)
{
    if (rows1 != rows2 && columns1 != columns2)
    {
        printf("Incompatible matrices\n");
        return 0;
    }
    else
    {
        float cost = 0;
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns1; j++)
            {
                cost = cost + ((mat1[(i * columns1) + j] - mat2[(i * columns1) + j]) * (mat1[(i * columns1) + j] - mat2[(i * columns1) + j]));
            }
        }
        return cost;
    }
}

//------------------------------Activation Functions-------------------------------------------
float RELU(float *data_in)
{
    if(*data_in <= 0)
    {
        return 0;
    }
    else
    {
        return *data_in;
    }
    
}
/*
float SoftMax(float *data_in)
{
}
*/
float Sigmoid(float *data_in)
{
    return (1/(1+pow(2.7182818,*data_in)));
}
//---------------------------------------------------------------------------------------------
int main()
{
    int rows1 = 10;
    int columns1 = 10;
    int rows2 = 10;
    int columns2 = 1;
    float *weights_mat, *input_mat, *dot_mat_out, *bias_mat, *sum_mat;
    weights_mat = matrix(rows1, columns1);
    input_mat = matrix(rows2, columns2);
    bias_mat = matrix(rows2, columns2);
    printf("Mat_x\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            printf("%f\t", weights_mat[(i * columns1) + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Mat_y\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            printf("%f\t", input_mat[(i * columns2) + j]);
        }
        printf("\n");
    }
    printf("\n");
    dot_mat_out = dot_product(&weights_mat[0], rows1, columns1, &input_mat[0], rows2, columns2);
    if (dot_mat_out != NULL)
    {
        printf("Dot_Mat\n");

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("%f\t", dot_mat_out[(i * columns2) + j]);
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
            printf("%f\t", bias_mat[(i * columns2) + j]);
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
                printf("%f\t", sum_mat[(i * columns2) + j]);
            }
            printf("\n");
        }
    }
    return 0;
}
