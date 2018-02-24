import java.io.BufferedInputStream;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Observable;
import java.util.Queue;


public class ChatModel extends Observable{

    Queue<Message> messagesDeque = new LinkedList<Message>();
   
    void push(Message message) {
        synchronized (this) {
            messagesDeque.add(message);
            setChanged();
            notifyObservers();
        }
    }
    
    Message getMessage() {
        synchronized (this) {
            if(messagesDeque.size() != 0)
                return messagesDeque.remove();
            else
                return null;
        }
    }
    
    
}
