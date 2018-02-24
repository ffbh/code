package ff;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JLabel;
import javax.swing.JOptionPane;


public class FourButton {
	static JLabel time = new JLabel("00:00",JLabel.CENTER);
	static JLabel messsage = new JLabel("0",JLabel.CENTER);
	static JLabel exit = new JLabel("退出",JLabel.CENTER);
	static JLabel chest = new JLabel("提示"); 
	static HintModule hintModule ;
	static void Init(){
		time.setBackground(new Color(169,190,240));
		time.setOpaque(true);
		time.setForeground(Color.black);
		time.setVisible(true);
		time.setFont(new java.awt.Font("宋体", 1, 20));
		time.setBounds(Main.game.Map_Size*Main.game.Block_Size,0*Main.game.Block_Size,3*Main.game.Block_Size,3*Main.game.Block_Size);
		Main.frame.add(time);
		
		chest.setBackground(new Color(169,190,240));
		chest.setOpaque(true);
		chest.setForeground(Color.blue);
		chest.setVisible(true);
		chest.setFont(new java.awt.Font("宋体", 1, 25));
		chest.setBounds(Main.game.Map_Size*Main.game.Block_Size,8*Main.game.Block_Size,3*Main.game.Block_Size,3*Main.game.Block_Size);
		chest.addMouseListener(new MouseListener() {
			
			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				hintModule = new HintModule(Main.game.table, Main.game.vis, Main.game.Map_Size);
				hintModule.changecolor();
			}
		});
		Main.frame.add(chest);
		
		exit.setBackground(new Color(169,190,240));
		exit.setOpaque(true);
		exit.setForeground(Color.red);
		exit.setVisible(true);
		exit.setFont(new java.awt.Font("宋体", 1, 25));
		exit.setBounds(Main.game.Map_Size*Main.game.Block_Size,12*Main.game.Block_Size,3*Main.game.Block_Size,3*Main.game.Block_Size);
		exit.addMouseListener(new MouseListener() {
			
			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				Main.frame.dispose();
				Main.mainactivity.setVisible(true);
			}
		});
		Main.frame.add(exit);
		
		messsage.setBackground(new Color(169,190,240));
		messsage.setOpaque(true);
		messsage.setText(Main.game.restnum.toString());
		messsage.setForeground(Color.gray);
		messsage.setVisible(true);
		messsage.setBounds(Main.game.Map_Size*Main.game.Block_Size,4*Main.game.Block_Size,3*Main.game.Block_Size,3*Main.game.Block_Size);
		messsage.setFont(new java.awt.Font("Dialog", 1, 50));
		Main.frame.add(messsage);
		
	}
	
	
}
