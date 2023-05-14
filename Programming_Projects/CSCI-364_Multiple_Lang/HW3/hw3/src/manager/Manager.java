/**
 * Manager.java
 *
 * This class needs to be completed for HW3.
 * 
 */
package manager;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;

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
 * @author david
 *
 */
public class Manager {

	/**
	 * @param args ignored
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.out.println("args.length = " + args.length);
			System.out.println("java manager.Manager [file]");
			System.exit(1);
		}

		String filename = args[0];
		System.out.println("filename: " + filename);
		FileReader fileReader = null;
		try {
			fileReader = new FileReader(filename);
		} catch (FileNotFoundException fnfe) {
			System.err.println("Error: " + filename + " not found.");
			System.err.println("Usage: java Server <jokefile> <seed>");
			System.exit(1);
		}

		ActiveMQConnectionFactory factory = new ActiveMQConnectionFactory(
				BrokerConfig.DEFAULT_BROKER);
		// make client trust deserializing objects in package 'api'
		factory.setTrustedPackages(
				new ArrayList<String>(Arrays.asList("api")));

		Connection connection = null;
		try {
			connection = factory.createConnection();
			Session session = connection.createSession(
					false, Session.AUTO_ACKNOWLEDGE);
			Destination dataQueue = session.createQueue(BrokerConfig.DATA_QUEUE);
			Destination workerQueue = session.createQueue(BrokerConfig.WORKER_QUEUE);
			MessageProducer producer = session.createProducer(dataQueue);
			MessageConsumer consumer = session.createConsumer(workerQueue);

			connection.start();

			try {
				BufferedReader bufferedReader = new BufferedReader(fileReader);

				// while not end of file
				// 		read a line from input filename
				// 		create a TextMessage object based on that line
				// 		send the TextMessage object to the data queue
				// 		read the response from the worker queue
				// 		determine the type of Worker objects
				// 		call getWorkResults
				// 		print task id and results to console

			} catch (Exception e) {
				e.printStackTrace();
			}
			TextMessage textMessage = session.createTextMessage("done");
			producer.send(textMessage);

			connection.close();
		} catch (JMSException e) {
			e.printStackTrace();
		}
	}
}
