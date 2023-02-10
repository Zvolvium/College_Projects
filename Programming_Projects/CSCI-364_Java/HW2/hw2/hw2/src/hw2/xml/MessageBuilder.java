package hw2.xml;
/**
 * MessageBuilder.java
 *
 * Creates and modifies XML-formatted MOM message strings.
 *
 * @author David Apostal
 */

import java.io.StringWriter;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.TransformerException;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 * Creates well-formed XML string message. The messages conform
 * to the format for HW2.
 *
 */
public class MessageBuilder {
    /** The root tag for the XML messages exchanged with MOM server */
    public static final String ROOT_TAG = "message";
    /** The tag for the first child element of 'message' */
    public static final String CMD_TAG = "cmd";
    /** The tag for the second child element of 'message' */
    public static final String DATA_TAG = "data";

    private DocumentBuilder db;

    private String myCmd;
    private String myData;

    /**
     * Creates a MessageBuilder object.
     *
     * @throws MessageException an exception thrown by a helper library
     */
    public MessageBuilder() throws MessageException {
        try {
          DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
          db = dbf.newDocumentBuilder();
      } catch (Exception e) {
        throw new MessageException(e.getMessage());
      }
    }

    /**
     * Sets the command element of the message..
     *
     * @param cmd the command string
     */
    public void setCmd(String cmd) {
        myCmd = cmd;
    }

    /**
     * Sets the data element of the message.
     *
     * @param data the data string
     */
    public void setData(String data) {
        myData = data;
    }

    /**
     * Creates a Document object
     *
     */
    private Document buildDocument() {
        Document doc = db.newDocument();
        Element root = doc.createElement(ROOT_TAG);
        Element cmd = doc.createElement(CMD_TAG);
        Element data = doc.createElement(DATA_TAG);

        cmd.appendChild(doc.createTextNode(myCmd));
        data.appendChild(doc.createTextNode(myData));

        root.appendChild(cmd);
        root.appendChild(data);
        doc.appendChild(root);

        return doc;
    }

    public String toString() {
        Document doc = buildDocument();

        TransformerFactory tf = TransformerFactory.newInstance();
        String output = "";

        try {
            Transformer transformer = tf.newTransformer();
            transformer.setOutputProperty(
                    OutputKeys.OMIT_XML_DECLARATION, "yes");

            StringWriter writer = new StringWriter();
            transformer.transform(
                    new DOMSource(doc), new StreamResult(writer));
            output = writer.getBuffer().toString();
        } catch (TransformerException te) {
            System.err.println(te.getMessage());
        }

        return output;
    }

    /**
     * Tests the class.
     *
     * @param args ignored
     */
    public static void main(String[] args) {
        try {
            MessageBuilder message = new MessageBuilder();
            message.setCmd("read");
            System.out.println(message.toString());
            message.setData("here we are");
            System.out.println(message.toString());
        } catch (MessageException me) {
            System.err.println(me.getMessage());
        }
    }
}
