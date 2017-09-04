/* Rotates a Square Matrix by 90 degrees clockwise without creating a new matrix 
 * Complexity : Linear
 */

#include <stdio.h>
#define MAX 100
 
typedef struct square_matrix 
{
	int size;
	int mat[MAX][MAX];
}
square_matrix;

// function prototypes 
void swap(int *x, int *y);
void rotate_layer(square_matrix *s, int row_index, int square_length);
void get_matrix_elements(square_matrix *s);
void display_matrix(const square_matrix *s);
void rotate_matrix(square_matrix *s);

int main()
{
	square_matrix s;
	printf("Enter the size of the matrix: ");
	scanf("%d", &s.size);
	get_matrix_elements(&s);

	display_matrix(&s);
	rotate_matrix(&s);
	display_matrix(&s); 
}


/* rotate a N X N Matrix by 90 degreed */
void rotate_matrix(square_matrix *s)
{
	int rotates = (s->size / 2);  // taking implicit truncation into consideration
	for (int i = 0; i < rotates; i++)
		rotate_layer(s, i, s->size - i - 1);
	
}


/* Swaps the original value of the two integers passed */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


/* displays the square matrix */
void display_matrix(const square_matrix *s)
{
	printf("\nMatrix: \n\n");
	for(int i = 0; i < (s->size); i++)
	{
		for(int j = 0; j < (s->size); j++)
			printf("%3d", (s->mat)[i][j]);
		printf("\n");
	}	
}


/* gets the elements of a square matrix as inputs from user */
void get_matrix_elements(square_matrix *s)
{
	for(int i = 0; i < (s->size); i++)
	{
		for(int j = 0; j < (s->size); j++)
		{
			printf("Index : [%d][%d]", i, j);
			scanf("%d", &(s->mat)[i][j]); 
		}
	}
}

/* rotates only the outer layer of the square matrix s by 90 degrees clockwise 
   base_index  is the row_index of the top    left corner of the square matrix
   max_index   is the row_index of the bottom left corner of the square matrix
   the matrix is presumed to be 0 indexed.  
*/
void rotate_layer(square_matrix *s, int base_index, int max_index)
{
	int swaps = max_index - base_index;
	if (swaps == 0) 
		return;   // implies a 1X1 matrix. 
	for (int i = 0; i < swaps; i++)
	{
		swap(&s->mat[base_index][base_index + i], &s->mat[max_index - i][base_index]);			
		swap(&s->mat[max_index - i][base_index] , &s->mat[max_index][max_index - i]);
		swap(&s->mat[max_index][max_index - i]  , &s->mat[base_index + i][max_index]);
	}	
}


