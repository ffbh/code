package ff;

import javax.swing.JLabel;

public class TimerModule {
	private JLabel jLabel;
	public TimerModule(JLabel _jLabel){
		jLabel = _jLabel;
	}
	void setTime(long time){
		Long minute = time / 60;
		Long second = time % 60;
		jLabel.setText(String.format("%02d:%02d",minute,second));
	}
	String getText(long time){
		Long minute = time / 60;
		Long second = time % 60;
		return String.format("%02d:%02d",minute,second);
	}
}
