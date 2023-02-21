/**
 * BrokerConfig.java
 *
 * This class contains some constants that may be needed by classes in the
 * manager and worker packages.
 *
 * @author David Apostal
 */
package api;

/**
 * Some constants needed by the Manager and Worker objects. This is a
 * noninstantiable utility class.
 * <p>
 * Note that this is not a Singleton object. There should never be any
 * instance of this class. 
 *
 * @see manager.Manager
 * @see worker.Worker
 */
public class BrokerConfig {
	/** the broker string for Apache ActiveMQ. */
	public static final String DEFAULT_BROKER = "tcp://localhost:61616";
	/** the name of the Manager-to-Worker queue */
	public static final String DATA_QUEUE = "hw3.queue.Data";
	/** the name of the Worker-to-Manager queue */
	public static final String WORKER_QUEUE = "hw3.queue.Worker";

  /**
	 * This private, parameterless default constructor is here to ensure that
	 * the Java compiler (javac) does not provide a public constructor.
	 */
	private BrokerConfig() {
		// empty
	}
}
