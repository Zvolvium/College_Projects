package hw2.xml;

/**
 * MessageException.java
 *
 * An exception for message-related processing.
 *
 * @author David Apostal
 */

/**
 * A wrapper class for exceptions related to building and parsing XML.
 */
public class MessageException extends RuntimeException {
    /**
     * Constructs a MessageException object.
     */
    public MessageException() {
        super();
    }

    /**
     * Constructs a MessageException object with a message.
     *
     * @param message the detail message
     */
    public MessageException(String message) {
        super(message);
    }

    /**
     * Constructs a MessageException object with a detail message and cause.
     *
     * @param message the detail message
     * @param cause the cause of the exception
     */
    public MessageException(String message, Throwable cause) {
        super(message, cause);
    }
}
