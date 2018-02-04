package ff;
import java.awt.Color;
import java.util.Arrays;


public class HintModule {
	Color[] change;
	int[][] table;
	boolean[][] vis;
	int size;
	double[][] p;
	final static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	public HintModule(int[][] t,boolean[][] v,int _size) {
		// TODO Auto-generated constructor stub
		table = t;
		vis = v;
		size = _size;
		p = new double[size][size];
		change = new Color[11];
		for(int i=0;i<11;++i)
			change[i] = new Color(i*19,0,255-i*19);
	}
	private boolean IN(int x,int y){
		return x>=0&&x<size&&y>=0&&y<size;
	}
	
	void show(){
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j)
				if(!vis[i][j])
					System.out.print(p[i][j]+" ");
				else {
					System.out.print(0.0+" ");
				}
			System.out.println();
		}
		System.out.println();
	}
	
	void chest(){
		int a,b;
		for(int i=0;i<size;++i)//初始化
			Arrays.fill(p[i], 0);
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j)
				if(vis[i][j]&&table[i][j] != 0){//首先计算已经翻开并且周围有累的位置
					a = b = 0;//a为周围未访问的格子数量，b记录的是周围已经显示的雷的数量
					int nextx,nexty;
					for(int k=0;k<8;++k){
						nextx = i+dirs[k][0];
						nexty = j+dirs[k][1];
						if(IN(nextx, nexty)){
							if(!vis[nextx][nexty])
								a++;
							else if(table[nextx][nexty]==-1)
								b++;
						}
					}
					b = table[i][j] - b;//总雷数-已显示的雷数量 = 隐藏的雷数量
					p[i][j] = Double.valueOf(b)/Double.valueOf(a);//周围未访问格子是雷的概率
				}
		}
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j)
				if(!vis[i][j]){//每个未访问格子是地雷的gailv = max(周围8个已访问的格子雷的概率）
					double x = 0;
					int nextx,nexty;
					for(int k=0;k<8;++k){
						nextx = i+dirs[k][0];
						nexty = j+dirs[k][1];
						if(IN(nextx, nexty)&&vis[nextx][nexty]&&x<p[nextx][nexty]){
							x = p[nextx][nexty];
						}
					}
					p[i][j] = x; 
				}
	}
	
	}
	void changecolor(){
		chest();
		ButtonHandler.change = true;
		for(int i=0;i<size;++i)
			for(int j=0;j<size;++j)
				if(p[i][j]!=0){
					int index =(int)(p[i][j]*10);
					Main.game.but[i][j].setBackground(change[index]);
				}
	}
}







