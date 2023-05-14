/**
 * PrimeChecker.java
 *
 * This class tests whether or not an input value is a prime number.
 */
package api;

/**
 * A not particularly efficient way to test if an integer is prime.
 *
 * @author david apostal
 */
public class PrimeChecker extends Worker {
	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	private int value;
	private boolean prime = true;

	/**
	 * @param id
	 */
	public PrimeChecker(int id, int val) {
		super(id);
		value = val;
	}

	/* (non-Javadoc)
	 * @see hw3.Worker#doWork()
	 */
	@Override
	public void doWork() {
		for (int i = 2; i < value; i++) {
			if (value % i == 0) {
				prime = false;
				break;
			}
		}
	}

	public String getWorkResults() {
		return "" + prime;
	}

	/**
	 * Test harness.
	 * @param args There are no arguments.
	 */
	public static void main(String[] args) {
		int num = Integer.parseInt(args[0]);
		int taskId = 1;
		PrimeChecker pc = new PrimeChecker(taskId, num);
		pc.doWork();
		System.out.println(num + " is prime. " +  pc.getWorkResults());
	}
}
