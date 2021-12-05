#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#define SEED 0xff

struct matrice {
  int row_length;
  int column_length;
  int ** matrice;
};

class Matrice_factory {
  private:

  public:
    Matrice_factory();
    void read_matrix();
    std::vector<struct matrice> matrices;
    void memory_allocation (struct matrice * matrice);
    void fill_matrice(struct matrice * matrice, int seed, int max_number_on_matrice);
    void show_matrice(struct matrice * matrice);
};

Matrice_factory::Matrice_factory() {

}

/* void Matrice_factory::read_matrix(std::string matrice_path) { */
/*   std::fstream read_matrice; */
/*   read_matrice.open(matrice_path); */
/*  */
/*   if (!read_matrice) { */
/*     std::cout << "File was not found" << std::endl; */
/*   } */
/*  */
/*   read_matrice.close(); */
/* } */

void Matrice_factory::memory_allocation(struct matrice * matrice) {
  int i;

   matrice->matrice = new int * [matrice->row_length];

  for (i = 0x0; i < matrice->row_length; i++) {
    matrice->matrice[i] = new int [matrice->row_length];
  }
}

void Matrice_factory::fill_matrice(struct matrice * matrice, int seed,
                                         int max_number_on_matrice) {
  int i;
  int j;

  srand(seed);

  for (i = 0x0; i < matrice->row_length; i++) {
    for (j = 0x0; j < matrice->column_length; j++) {
       matrice->matrice[i][j] = rand() % max_number_on_matrice;
    }
  }
}

void Matrice_factory::show_matrice(struct matrice * matrice) {
  int i;
  int j;

  for (i = 0x0; i < matrice->row_length; i++) {
    for (j = 0x0; j < matrice->column_length; j++) {
      std::cout << "[" << matrice->matrice[i][j] << "]";
    }
    std::cout << std::endl;
  }

}

/*
void matrix_multiplication(std::vector<struct matrice> matrices) {
  int i;
  int j;
  int k;

  int m = matrices.matrice[0]->row_length
  int n = matrices.matrice[0]->row_length
  int p = matrices.matrice[0]->row_length

  for (i = 0x0; i < m; i++) {
    for (j = 0x0; j < n; j++) {
      for (k = 0x0; k < p; k++) {
        matrix3[i][j] += matrix1[k][j] * matrix2[i][k];
      }
    }
  }
}
*/

int main(int argc, char const ** argv) {

  struct timeval start;
  struct timeval stop;

  /* sample matrix */
  struct matrice matrix1;
  matrix1.row_length = 0x5;
  matrix1.column_length = 0x3;

  struct matrice matrix2;
  matrix2.row_length = 0x2;
  matrix2.column_length = 0x2;


  /* int length = strtol(argv[0x1], NULL, 0xa); */

  /* factory.matrices.push_back(matrix2); */

  Matrice_factory factory = Matrice_factory();
  factory.memory_allocation(&matrix1);
  factory.fill_matrice(&matrix1, 0x223, 30);
  /* factory.show_matrice(&matrix1); */

  factory.memory_allocation(&matrix1);
  factory.fill_matrice(&matrix1, 3, 30);

  factory.matrices.push_back(matrix1);
  factory.matrices.push_back(matrix2);
  /* factory.show_matrice(factory.matrices[0]); */

  factory.show_matrice(&factory.matrices[0]);

  matrix_multiplication(factory.matrices);

	return 0x0;
}
