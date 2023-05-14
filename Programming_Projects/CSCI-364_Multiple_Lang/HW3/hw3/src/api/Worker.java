/**
 * Worker.java
 *
 * A subclass for PrimeChecker, and other HW3 tasks.
 *
 * @author David Apostal
 */
package api;

import java.io.Serializable;

/**
 * @author david apostal
 *
 */
public abstract class Worker implements Serializable {
	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	private int taskId;

	/**
	 * @param the task id for the work task
	 */
	public Worker(int id) {
		taskId = id;
	}

	public int getTaskId() {
		return taskId;
	}

	public abstract void doWork();

	public abstract String getWorkResults();
}
