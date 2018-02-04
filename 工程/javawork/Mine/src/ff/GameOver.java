package ff;

import javax.swing.JOptionPane;


public class GameOver implements Runnable {
	private static Integer threadId = 0;
	long starttime;
	int id;
	TimerModule timerModule = new TimerModule(FourButton.time);
	public GameOver() {
		// TODO Auto-generated constructor stub
		starttime = System.currentTimeMillis()/1000;
		synchronized (threadId) {
			id = ++threadId;
        }
		
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			synchronized (threadId) {
				if(id != threadId)
					break;
	        }
			long nowtime = System.currentTimeMillis();
			nowtime /= 1000;
			timerModule.setTime(nowtime - starttime);
			if(Main.game.rest_vis_num==1){
				JOptionPane.showMessageDialog(Main.frame, "游戏用时:"+timerModule.getText(nowtime-starttime));  
				break;
			}
			else if(ButtonHandler.shutdown){
				JOptionPane.showMessageDialog(Main.frame, "游戏结束");  
				break;
			}
			else 
				Thread.yield();
		}
	}
}
