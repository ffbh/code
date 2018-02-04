package ff;
import java.awt.event.*;

import javax.swing.*;

public class LabelHandle implements MouseListener {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		if(e.getButton()==MouseEvent.BUTTON3){int x = e.getXOnScreen();
			int y = e.getYOnScreen();
			java.awt.Point p = new java.awt.Point();
			SwingUtilities.convertPointToScreen(p,Main.game.but[0][0]);
			x -= p.x;/////
			y -= p.y;///////
			x/=Main.game.Block_Size;
			y/=Main.game.Block_Size;
			Main.game.mark[x][y] = false;
			Main.game.but[x][y].setVisible(true);
			Main.game.jb[x][y].setVisible(false);
			Main.game.warn[x][y].setVisible(false);
			Main.game.restnum++;
			FourButton.messsage.setText(Main.game.restnum.toString());
		}
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
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

}
