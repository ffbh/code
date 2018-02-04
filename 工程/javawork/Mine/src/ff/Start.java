package ff;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;


public class Start implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		ButtonHandler.shutdown = false;
		ButtonHandler.change = false;
		Main.frame = new JFrame();
		Main.frame.setUndecorated(true);
		Main.frame.setVisible(false);
		Main.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Main.frame.setLayout(null);
		Main.frame.getContentPane().setBackground(new Color(169,169,169));
		Main.game = new Mine(Main.Mine_Map_size,Main.Mine_num);
		Main.game.cal_table();	
		Main.game.Init();
		FourButton.Init();
		Main.thread = new Thread(new GameOver());
		Main.thread.setDaemon(true);
		Main.thread.start();
		Main.frame.setVisible(true);
		Main.mainactivity.setVisible(false);
	

	}

}
