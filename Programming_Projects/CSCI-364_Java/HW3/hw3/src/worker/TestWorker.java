/**
 * TestWorker.java
 *
 * This is class needs to be completed for HW3.
 *
 */
package worker;

import javax.jms.Connection;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageConsumer;
import javax.jms.MessageProducer;
import javax.jms.ObjectMessage;
import javax.jms.Session;
import javax.jms.TextMessage;

import org.apache.activemq.ActiveMQConnectionFactory;

import api.BrokerConfig;
import api.PrimeChecker;

/**
 *
 */
public class TestWorker {

	/**
	 * @param args ignored
	 */
	public static void main(String[] args) {
		ActiveMQConnectionFactory factory = new ActiveMQConnectionFactory(
				BrokerConfig.DEFAULT_BROKER);

		Connection connection = null;
		try {
			connection = factory.createConnection();
			Session session = connection.createSession(
					false, Session.AUTO_ACKNOWLEDGE);
			Destination dataQueue = session.createQueue(BrokerConfig.DATA_QUEUE);
			Destination workerQueue = session.createQueue(BrokerConfig.WORKER_QUEUE);
			MessageProducer producer = session.createProducer(workerQueue);
			MessageConsumer consumer = session.createConsumer(dataQueue);

			connection.start();

			while (true) {
				// receive message from data queue
				Message message = consumer.receive();

				// depending on the type of Message (do not assume it is a TextMessage)
				// if TextMessage object contains "done", then break
				// retrieve the task id and values from TextMessage
				// instantiate an appropriate Worker subclass object
				// call doWork
				// create an ObjectMessage object
				// send ObjectMessage to worker queue

			connection.close();
		} catch (JMSException e) {
			e.printStackTrace();
		}

	}
}
