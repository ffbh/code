package ff;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class MyJWindow extends JFrame{
	private static final long serialVersionUID = 1L;
	JButton jb = new JButton("X");
	public MyJWindow(Color color){
		this.setUndecorated(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setVisible(false);
		this.getContentPane().setBackground(color);
		this.setLayout(null);
		jb.setBounds(330, 0, 20, 20);
		jb.setBorder(null);
		jb.setForeground(Color.black);
		jb.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				MyJWindow.this.dispose();
			}
		});
		this.add(jb);
		
	}
	
}










