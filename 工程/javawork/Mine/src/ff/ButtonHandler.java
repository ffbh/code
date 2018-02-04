package ff;
import java.awt.event.*;

import javax.swing.*;

public class ButtonHandler  implements MouseListener {
	public static Boolean shutdown = false;
	public static Boolean change = false;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		if(shutdown)
			return ;
		
		int x = e.getXOnScreen();
		int y = e.getYOnScreen();
		java.awt.Point p = new java.awt.Point();
		SwingUtilities.convertPointToScreen(p,Main.game.but[0][0]);
		x -= p.x;/////
		y -= p.y;///////
		x/=Main.game.Block_Size;
		y/=Main.game.Block_Size;
		if(e.getButton()==MouseEvent.BUTTON1){
			if(change){
				Main.game.ResetButColor();
				change = false;
			}
			if(Main.game.table[x][y]>=1){
				Main.game.vis[x][y] = true;
				Main.game.but[x][y].setVisible(false);
				Main.game.jb[x][y].setVisible(true);
				Main.game.warn[x][y].setVisible(false);
				Main.game.rest_vis_num--;
			} else if (Main.game.table[x][y] == 0) {
				Main.game.bfs(new Point(x, y));
				Main.game.rest_vis_num -= Main.game.vp.size();
				for (int i = 0; i < Main.game.vp.size(); ++i) {
					Point p1 = Main.game.vp.get(i);
					Main.game.but[p1.x][p1.y].setVisible(false);
					Main.game.jb[p1.x][p1.y].setVisible(true);
					Main.game.warn[p1.x][p1.y].setVisible(false);
					if (Main.game.mark[p1.x][p1.y])
						Main.game.restnum++;
				}
				FourButton.messsage.setText(Main.game.restnum.toString());
			} else {
				for (int i = 0; i <Main.game.Map_Size; ++i)
					for (int j = 0; j < Main.game.Map_Size; ++j)
						if (Main.game.table[i][j] == -1) {
							Main.game.but[i][j].setVisible(false);
							Main.game.jb[i][j].setVisible(true);
							Main.game.warn[i][j].setVisible(false);
						}
				shutdown = true;
			}
		} else if (e.getButton() == MouseEvent.BUTTON3) {
			if (Main.game.restnum == 0)
				return;
			Main.game.restnum--;
			FourButton.messsage.setText(Main.game.restnum.toString());
			Main.game.but[x][y].setVisible(false);
			Main.game.jb[x][y].setVisible(false);
			Main.game.warn[x][y].setVisible(true);
			Main.game.mark[x][y] = true;
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
