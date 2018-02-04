package ff;
import java.awt.event.*;


public class MenuExit implements ActionListener{
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		try{
			Thread.sleep(500);
		}
		catch(Exception ee){
			System.err.println("exception in MenuExit");
		}
		System.exit(0);
	}



}
