package hw2.xml;
/**
 * MessageParser.java
 *
 * Validates messages for HW2 (2023).
 *
 * @author David Apostal
 */
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.InputStream;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.transform.Source;
import javax.xml.transform.dom.DOMSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;
import javax.xml.transform.stream.StreamSource;
import javax.xml.XMLConstants;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

/**
 * Validates and parses messages. This class uses an XML schema
 * to test a message for validity. If the message is valid, the
 * command and data can be retrieved via accessor methods.
 */
public class MessageParser {
    /**
     * The schema file name. The parser validates the structure of an
     * XML string against this schema.
     */
    public static final String SCHEMA_FILE = "message.xsd";

    private String myCmd;
    private String myData;

    /**
     * Constructs a MessageParser object.
     *
     * @param xmlString the string to be validated and parsed.
     * @throws MessageException an exception thrown by a helper library
     */
    public MessageParser(String xmlString) throws
            NullPointerException, MessageException {
        if (xmlString == null) {
            throw new NullPointerException(
                    "xmlString  must be non-null");
        }

        try {
            byte[] xmlBytes = xmlString.getBytes();
            InputStream is = new ByteArrayInputStream(xmlBytes);

            DocumentBuilderFactory dbf =
                    DocumentBuilderFactory.newInstance();
            DocumentBuilder db = dbf.newDocumentBuilder();
            Document doc = db.parse(is);

            SchemaFactory factory = SchemaFactory.newInstance(
                    XMLConstants.W3C_XML_SCHEMA_NS_URI);
            Source schemaFile = new StreamSource(new File(SCHEMA_FILE));
            Schema schema = factory.newSchema(schemaFile);

            Validator validator = schema.newValidator();
            validator.validate(new DOMSource(doc));

            Element root = doc.getDocumentElement();
            Node cmdNode = root.getFirstChild();
            myCmd = getText(cmdNode);

            Node dataNode = root.getLastChild();
            myData = getText(dataNode);
        } catch (Exception e) {
            throw new MessageException(e.getMessage());
        }
    }

    /**
     * Gets the cmd text from the XML message.
     *
     * @return the text from the cmd element.
     */
    public String getCmd() {
        return myCmd;
    }

    /**
     * Gets the data text from the XML message.
     *
     * @return the text from the data element.
     */
    public String getData() {
        return myData;
    }

    /**
     * Gets the text from an element.
     *
     * @return the text from a element. Returns empty string if
     * element is null.
     */
    private String getText(Node node) {
        String text = "";
        Node textNode = node.getFirstChild();
        if (textNode == null) {
            text = "";
        } else {
            text = textNode.getNodeValue();
        }

        return text;
    }

    /**
     * Tests the validator and accessors.
     *
     * @param args a string to be validated
     */
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("java MessageParser <xml string to test>");
            System.exit(1);
        }

        String xmlString = args[0];
        System.out.println(xmlString);

        try {
        MessageParser mp = new MessageParser(xmlString);
        System.out.println("cmd: " + mp.getCmd());
        System.out.println("data: " + mp.getData());
      } catch (MessageException me) {
          System.err.println(me.getMessage());
      }
    }
}
