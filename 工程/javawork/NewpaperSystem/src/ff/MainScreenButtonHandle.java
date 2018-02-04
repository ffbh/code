package ff;


import java.awt.event.*;

import javax.swing.*;


public class MainScreenButtonHandle implements MouseListener {
	static Typing typing = new Typing();
	static Subscribe subscribe = new Subscribe();
	static Search search = new Search();
	static Count count = new Count();
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		int x = e.getXOnScreen();
		int y = e.getYOnScreen();
		if((JButton)e.getSource() == MainScreen.but[0])
			typing.show(x, y);
		else if((JButton)e.getSource() == MainScreen.but[1])
			subscribe.show(x, y);
		else if((JButton)e.getSource() == MainScreen.but[2])
			search.show(x,y);
		else
			count.show(x,y);
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		MainScreen.jw.setVisible(false);
		int x = e.getXOnScreen();
		int y = e.getYOnScreen();
		MainScreen.jw.setBounds(x, y,350, 20);
		int index = -1;
		for(int i=0;i<4;++i){
			if((JButton)e.getSource() == MainScreen.but[i]){
				index = i;
				break;
			}
		}
		if(index >= 0 && index < 4)
			MainScreen.jtf.setText(MainScreen.mess[index]);
		MainScreen.jw.setVisible(true);
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		MainScreen.jw.setVisible(false);
		
	}

}
