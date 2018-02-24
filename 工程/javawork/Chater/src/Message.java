import javax.swing.JTextPane;
import javax.swing.text.SimpleAttributeSet;


public abstract class Message {
    String[] messages;
    String time;
    SimpleAttributeSet attrSet;
    public abstract void insert(JTextPane jtf);
}
