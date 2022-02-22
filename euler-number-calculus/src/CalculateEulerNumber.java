public class CalculateEulerNumber {
  public int value;

  public CalculateEulerNumber(int value) {
    this.value = value;
  }

  public Double run() {
    return this.calculate(this.value);
  }

  public double calculate(int value) {
    int factorialResult = 1;
    for (int i = 2; i <= value; i++) {
      factorialResult *= i;
    }
    return 1.0 / factorialResult;
  }

  public static void main(String[] args) {
    int series = Integer.parseInt(args[0]);
    CalculateEulerNumber calculate = new CalculateEulerNumber(series);
    System.out.println(calculate.run());
  }
}
