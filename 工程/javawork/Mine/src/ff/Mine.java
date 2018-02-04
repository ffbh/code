package ff;

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.*;


public class Mine {

	static final String[] _pace = {"icon\\0.png","icon\\1.jpg","icon\\2.jpg","icon\\3.jpg",
		"icon\\4.jpg","icon\\5.jpg","icon\\6.jpg","icon\\7.jpg","icon\\8.jpg","icon\\9.jpg"};
	final static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	Vector<Point> vp = new Vector<Point>();
	int Map_Size= 20;
	int Block_Size = 20;
	int Mine_Num  = 40;
	int X = 400;
	int Y = 150;
	boolean[][] map;
	int[][] table;
	boolean[][] vis;
	boolean[][] mark ;
	ImageIcon[][] imco;
	ImageIcon[][] imco2;
	JLabel[][] warn ;
	Integer restnum;
	int rest_vis_num;
	JLabel[][] jb ;
	JButton[][] but ;
	Color color = Color.black;
	void ResetButColor(){
		for(int i=0;i<Map_Size;++i)
			for(int j=0;j<Map_Size;++j)
				but[i][j].setBackground(color);
	}
	
	
	public Mine(int line,int num){
		Map_Size = line;
		Mine_Num = num;
		Main.frame.setBounds(400, 	150, (line+3)*Block_Size,(line)*Block_Size);//////////////////
		table =  new int[Map_Size][Map_Size];
		map = new boolean[Map_Size][Map_Size];
		vis = new boolean[Map_Size][Map_Size];
		mark = new boolean[Map_Size][Map_Size];
	}
	private boolean IN(int x,int y){
		return x>=0&&x<Map_Size&&y>=0&&y<Map_Size;
	}
	void Debug_show_map(){
		for(int i=0;i<Map_Size;++i){
			for(int j=0;j<Map_Size;++j)
				if(table[i][j]!=-1)
					System.out.print(table[i][j]);
				else 
					System.out.print('*');
			System.out.println();	
		}
	}
	
	void Debug_File_Input()throws Exception{
		Scanner in = new Scanner(new File("C:\\temp.txt"));
		Map_Size = 5;
		for(int i=0;i<Map_Size;++i){
			String s = in.nextLine();
			for(int j=0;j<s.length();++j)
				if(s.charAt(j) == '0')
					map[i][j] = false;
				else 
					map[i][j] = true;
		}
		cal_table();
		Debug_show_map();
		in.close();
		
	}
	
	void bfs(Point S){
		vp.clear();
		Queue<Point> qp = new LinkedList<Point>();
		qp.add(S);
		vis[S.x][S.y] = true;
		while(qp.size()!=0){
			Point now = qp.remove();
			vp.add(now);
			if(table[now.x][now.y]!=0)
				continue;
			for(int i=0;i<8;++i){
				Point next = new Point();
				next.x = now.x + dirs[i][0];
				next.y = now.y + dirs[i][1];			
				if(IN(next.x, next.y)&&!vis[next.x][next.y]){
					vis[next.x][next.y] = true;
					qp.add(next);
				}
			}
		}
	}
	
	void cal_table(){
		Random random = new Random();
		for(int i=0;i<Mine_Num;++i){
			int rx = random.nextInt(Map_Size);//随机生成想，y
			int ry = random.nextInt(Map_Size);
			while(map[rx][ry]){//判断改位置是否已放置地雷
				if(ry<Map_Size-1)//若不是最后一列，则下一个
					ry++;
				else if(rx<Map_Size-1){//判断是否最后一行
					rx++;
					ry=0;
				}
				else //最后一列，最后一行，则回到0,0位置
					rx=ry=0;
			}
			map[rx][ry]=true;//设置雷
		}
		for(int i=0;i<Map_Size;++i){//统计每个位置周围有几个雷，-1代表该位置是雷
			for(int j=0;j<Map_Size;++j){
				if(!map[i][j]){
					int num = 0;
					for(int k=0;k<8;++k){
						int nx = i + dirs[k][0];
						int ny = j + dirs[k][1];
						if(IN(nx, ny)&&map[nx][ny])
							num++;
					}
					table[i][j] = num;
				}
				else
					table[i][j] = -1;
			}
		}
		
	}
	
	void Init(){
		for(int i=0;i<Map_Size;++i){
			Arrays.fill(map[i], false);
			Arrays.fill(vis[i],false);
			Arrays.fill(mark[i], false);
		}
		restnum = Mine_Num;
		rest_vis_num = Map_Size*Map_Size-Mine_Num + 1;
		but = new JButton[Map_Size][Map_Size];
		for(int i=0;i<Map_Size;i++)
			for(int j=0;j<Map_Size;j++){
				but[i][j] = new JButton();
				but[i][j].setBounds(i*Block_Size,j*Block_Size,Block_Size,Block_Size);
				but[i][j].setBackground(color);
				but[i][j].addMouseListener(new ButtonHandler());
				Main.frame.add(but[i][j]);
			}
		
		imco = new ImageIcon[Map_Size][Map_Size];
		imco2 = new ImageIcon[Map_Size][Map_Size];
		jb = new JLabel[Map_Size][Map_Size];
		warn = new JLabel[Map_Size][Map_Size];
		for(int i=0;i<Map_Size;++i){
			for(int j=0;j<Map_Size;++j){
				int k = (table[i][j]==-1)?9:table[i][j];
				imco[i][j] = new ImageIcon(_pace[k]);
				imco[i][j].setImage(imco[i][j].getImage().getScaledInstance(Block_Size,Block_Size,Image.SCALE_DEFAULT)); 
				jb[i][j] = new JLabel(imco[i][j]);
				jb[i][j].setBounds(i*Block_Size,j*Block_Size,Block_Size,Block_Size);
				jb[i][j].setVisible(false);
				Main.frame.add(jb[i][j]);
				imco2[i][j] = new ImageIcon("icon\\10.jpg");
				imco2[i][j].setImage(imco2[i][j].getImage().getScaledInstance(Block_Size,Block_Size,Image.SCALE_DEFAULT)); 
				warn[i][j] = new JLabel(imco2[i][j]);
				warn[i][j].setBounds(i*Block_Size,j*Block_Size,Block_Size,Block_Size);
				warn[i][j].setVisible(false);
				warn[i][j].addMouseListener(new LabelHandle());
				Main.frame.add(warn[i][j]);
			}
		}
		
	}
	
	

}



















