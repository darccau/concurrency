#include <iostream>
#include <fstream>
#include <sstream>
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
    std::stringstream read_matrice_description(std::string file_path);
    std::vector<struct matrice> matrices;
    void create_matrice(std::stringstream matrice_blueprint);
    void fill_matrice(struct matrice * matrice, int seed, int max_number_on_matrice);
    void show_matrice(struct matrice * matrice);
};

Matrice_factory::Matrice_factory() {

}

std::stringstream Matrice_factory::read_matrice_description(std::string file_path) {
  std::ifstream matrice_description_reader;
  std::string matrice_description_line;
  std::stringstream matrice_description;

  matrice_description_reader.open(file_path);

  if (matrice_description_reader.is_open()) {
    while (matrice_description_reader) {
      std::getline(matrice_description_reader, matrice_description_line);
      matrice_description << matrice_description_line << std::endl;
    }
  }

  matrice_description_reader.close();

  return matrice_description;
}

void Matrice_factory::create_matrice(std::stringstream matrice_blueprint) {
  int i;
  struct matrice * matrice;

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

void parse_user_input(int argc, int matrices_dimension, std::string execution_type) {
  if (argc != 0x3) {
    std::cout << "Insufficient command line parametters" << std::endl;
    exit(0x1);
  }

  if ((execution_type != "S") && (execution_type != "C")) {
    std::cout << "Execution type diferent of [C] or [S]" << std::endl;
    exit(0x1);
  }

  if (((matrices_dimension * matrices_dimension) % 0x2) != 0x0) {
    std::cout << " Dimension is not power by 2" << std::endl;
    exit(0x1);
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


  int matrices_dimension = atoi(argv[0x1]);
  std::string execution_type = argv[0x2];


  parse_user_input(argc, matrices_dimension, execution_type);

  Matrice_factory factory = Matrice_factory();
  /* factory.create_matrice(&matrix1); */
  /* factory.fill_matrice(&matrix1, 0x223, 30); */


  /* factory.matrices.push_back(matrix1); */

  /* factory.show_matrice(&factory.matrices[0]); */
  factory.read_matrice_description("./matrices/A4x4.txt");

  std::cout << execution_type << std::endl;

  /* matrix_multiplication(factory.matrices); */

	return 0x0;
}
