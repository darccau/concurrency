#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>


struct matrice {
  int dimension;
  long long ** matrice;
};

class Matrice_multiplication {
  private:
    int m_dimension;
    struct matrice * m_matrice_A;
    struct matrice * m_matrice_B;
    struct matrice * m_matrice_C;
    std::stringstream m_matrice_A_path;
    std::stringstream m_matrice_B_path;
    std::stringstream m_matrice_C_path;

    std::stringstream read_matrice(std::string file_path);
    struct matrice * memory_allocation(struct matrice * matrice);
    void fill_matrice(std::stringstream matrice_blueprint, struct matrice * matrice);
    void show_matrice(struct matrice * matrice);
    void parallel_multiplication(int rank);
    void serial_multiplication();
    void output_matrice();
    void timmer();

  public:
    Matrice_multiplication(int matrices_dimension, std::string execution_type);

};

Matrice_multiplication::Matrice_multiplication(int matrices_dimension, std::string execution_type) {
  m_dimension = matrices_dimension;

  m_matrice_A_path << "./matrices/A" << m_dimension << "x" << m_dimension << ".txt";
  m_matrice_B_path << "./matrices/B" << m_dimension << "x" << m_dimension << ".txt";
  m_matrice_C_path << "./matrices/C" << m_dimension << "x" << m_dimension << ".txt";

  m_matrice_A = memory_allocation(m_matrice_A);
  m_matrice_B = memory_allocation(m_matrice_B);
  m_matrice_C = memory_allocation(m_matrice_C);

  fill_matrice(read_matrice(m_matrice_A_path.str()), m_matrice_A);
  fill_matrice(read_matrice(m_matrice_B_path.str()), m_matrice_B);

  m_matrice_C->dimension = matrices_dimension;

  if (execution_type == "S") {
    serial_multiplication();
    exit(0x0);
  }

  else if (execution_type == "C") {
    int thread;
    std::thread thread_handler[m_dimension];

    auto start = std::chrono::high_resolution_clock::now();

    for (thread = 0x0; thread < m_dimension; thread++) {
      thread_handler[thread] = std::thread(&Matrice_multiplication::parallel_multiplication, this, thread);
    }

    for (thread = 0x0; thread < m_dimension; thread++) {
      thread_handler[thread].join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << "Execution time - " << duration << std::endl;

    exit(0x0);
 }

}


/* void Matrice_multiplication::timmer() { */
/*   auto start = std::chrono::high_resolution_clock::now(); */
/*   parallel_multiplication(); */
/*   auto end = std::chrono::high_resolution_clock::now(); */
/*  */
/*  */
/*   auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start); */
/*   std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl; */
/* } */

void Matrice_multiplication::output_matrice() {
  int i;
  int j;

  std::ofstream write_matrice;
  std::stringstream data;
  std::stringstream output_matrice;

  output_matrice << "result_matrice_" << m_dimension << "x" << m_dimension << ".txt";

  write_matrice.open(output_matrice.str());

  for (i = 0x0; i <  m_dimension; i++) {
    for (j = 0x0; j < m_dimension; j++) {
      data << m_matrice_C->matrice[i][j] << " ";
    }
    data << std::endl;
  }

  write_matrice << data.str();

  write_matrice.close();
}

std::stringstream Matrice_multiplication::read_matrice(std::string file_path) {
  std::ifstream matrice_reader;
  std::string matrice_line;
  std::stringstream matrice_blueprint;

  matrice_reader.open(file_path);

  if (matrice_reader.is_open()) {
    while (matrice_reader) {
      std::getline(matrice_reader, matrice_line);
      matrice_blueprint << matrice_line << std::endl;
    }
  }

  matrice_reader.close();

  return matrice_blueprint;
}


void Matrice_multiplication::parallel_multiplication(int rank) {

  int i;
  int j;
  int k;

  int start;
  int end;

  start = rank;
  end = start + 0x1;

  for (i = start; i < end; i++) {
    for (j = 0x0; j < m_dimension; j++) {
      long long sum = 0x0;
      for (k = 0x0; k < m_dimension; k++) {
        sum += m_matrice_A->matrice[i][k] * m_matrice_B->matrice[k][j];
      }
      m_matrice_C->matrice[i][j] = sum;
    }
  }

}

void Matrice_multiplication::fill_matrice(std::stringstream matrice_blueprint, struct matrice * matrice) {
  int i;
  int j;

  matrice_blueprint >> matrice->dimension;
  matrice_blueprint >> matrice->dimension;

   for (i = 0x0; i < matrice->dimension; i++) {
     for (j = 0x0; j < matrice->dimension; j++) {
       matrice_blueprint >> matrice->matrice[i][j];
     }
   }
}

struct matrice * Matrice_multiplication::memory_allocation(struct matrice * matrice) {
   int i;

   matrice = new struct matrice;

   matrice->matrice = new long long * [m_dimension];

   for (i = 0x0; i < m_dimension; i++) {
     matrice->matrice[i] = new long long [m_dimension];
   }

  return matrice;
 }


void Matrice_multiplication::show_matrice(struct matrice * matrice) {
  int i;
  int j;

  for (i = 0x0; i < matrice->dimension; i++) {
    for (j = 0x0; j < matrice->dimension; j++) {
      std::cout << "[" << matrice->matrice[i][j] << "]";
    }
    std::cout << std::endl;
  }
}


void Matrice_multiplication::serial_multiplication() {
	int i;
	int j;
	int k;


  for (i = 0x0; i < m_dimension; i++) {
    for (j = 0x0; j < m_dimension; j++) {
      long long sum = 0;
      for (k = 0x0; k < m_dimension; k++) {
        sum += m_matrice_A->matrice[i][k] * m_matrice_B->matrice[k][j];
      }
      m_matrice_C->matrice[i][j] = sum;
    }
  }

}

void parse_user_input(int argc, int matrices_dimension, std::string execution_type) {
  if (argc != 0x3) {
    std::cout << "Insufficient command line parametters" << std::endl;
    exit(0x1);
  }

  if ((execution_type != "S") && (execution_type != "C")) {
    std::cout << "Execution type is diferent from [C] or [S]" << std::endl;
    exit(0x1);
  }

  if (((matrices_dimension * matrices_dimension) % 0x2) != 0x0) {
    std::cout << " Dimension is not power by 2" << std::endl;
    exit(0x1);
  }
}

void sample(int num, int n) {
  std::cout << "thread - " << num  << " " << n << std::endl;
}

int main(int argc, char const ** argv) {


  int matrices_dimension = atoi(argv[0x1]);
  std::string execution_type = argv[0x2];

  /* parse_user_input(argc, matrices_dimension, execution_type); */

  Matrice_multiplication factory = Matrice_multiplication(matrices_dimension, execution_type);

	return 0x0;
}
