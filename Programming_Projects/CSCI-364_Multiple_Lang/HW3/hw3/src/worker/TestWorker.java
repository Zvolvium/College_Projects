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
import api.Worker;

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
				Message message = consumer.onMessage();

				if (message.contains("done")){ break; }

				String []values;
				String text = message.getText();
				values = text.strip().split(" ");
				int taskID = Integer.valueOf(values[0]);
				int val = Integer.valueOf(values[1]);
				
				PrimeChecker work = new PrimeChecker(taskID, val);

				work.doWork();

				TextMessage text = session.createTextMessage();
				text.setText(""+work.getTaskId()+" "+work.getWorkResults());

				producer.send(text);
			}
			connection.close();
		}
		catch (JMSException e) {
			e.printStackTrace();
		}

	}
}
