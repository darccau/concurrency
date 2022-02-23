import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class FixedThreadPool {

  public static final int threads = 4;

  public static class CalculateEulerNumber implements Callable<Double> {
    public int value;

    public CalculateEulerNumber(int value) {
      this.value = value;
    }

    @Override
    public Double call() {
      return this.calculate(this.value);
    }

    public double calculate(int value) {
      System.out.println("Current Thread: " + +Thread.activeCount());
      int factorialResult = 1;
      for (int i = 2; i <= value; i++) {
        factorialResult *= i;
      }
      return 1.0 / factorialResult;
    }
  }


  public static void main(String[] args) {
    double sum = 0;
    int series = Integer.parseInt(args[0]);

    ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);
    List<Future<Double>> values = new ArrayList<Future<Double>>();

    for (int i = 0; i < series; i++) {
      Callable<Double> task = new CalculateEulerNumber(i);
      Future<Double> value = executor.submit(task);
      values.add(value);
    }

    try {
      for (Future<Double> value : values) {
        sum += value.get();
      }
    } catch(ExecutionException | InterruptedException err) {
      err.printStackTrace();
    }

    System.out.println("Result: " + sum);

    executor.shutdown();
  }
}
