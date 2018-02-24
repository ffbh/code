package jim;

import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DropTarget;
import java.awt.dnd.DropTargetAdapter;
import java.awt.dnd.DropTargetDropEvent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOError;
import java.io.IOException;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;
import javax.swing.*;

import zjz.LR;
import zjz.LRTable;

public class Main extends JFrame implements ActionListener {
    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    JTextField t1,t2,t3;
    JTextPane inputPane = new JTextPane();
    String syntax="";
    String message="1.文法格式：\n[A-Z]->[a-zA-Z]*\n\"->\"左边应为单个非终结符\n\"->\"右边边应为终结符与非终结符的任意组合,但不能为空\n每句文法独占一行\n2.你可以手动输入相关信息\n"
    		+ "也可以从Menu中选择open打开txt文件读取相关信息\n或直接将txt文件拖人窗口"
    		+ "\n3.txt文本中格式应为：\n第一行:文法开始符\n第二行:文法终结符集合\n第三行:文法非终结符集合\n后面为若干行文法"
    		+ "\n4.需要分析的语句可以在点击菜单中的\"Input Syntax\"后输入";
	
    public void Init() {
    	
    	JMenuBar jmb=new JMenuBar();
    	setJMenuBar(jmb);
        // 菜单 "Operation"添加到菜单栏
        JMenu operationMenu = new JMenu("Menu");
        operationMenu.setMnemonic('O');
        jmb.add(operationMenu);

        JMenuItem jmiOpen,jmiClose,jmiHelp,jmiSyntax;
        operationMenu.add(jmiOpen= new JMenuItem("Open file", 'O'));
        operationMenu.add(jmiHelp= new JMenuItem("Help", 'H'));
        operationMenu.add(jmiClose = new JMenuItem("Close", 'C'));

        jmiOpen.setAccelerator(
        	      KeyStroke.getKeyStroke(KeyEvent.VK_O, ActionEvent.CTRL_MASK));
        jmiOpen.addActionListener(this);
        jmiClose.addActionListener(this);
        jmiHelp.addActionListener(this);

        
        setVisible(true);
        setSize(400	, 450);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel mainJPanel=new JPanel();
        mainJPanel.setLayout(new GridLayout(2, 2, 50, 50));
        JPanel inputPanel=new JPanel();
        final JLabel l1=new JLabel("文法开始符"),
                l2=new JLabel("文法终结符"),
                l3=new JLabel("文法非终结符");
        l1.setFont(new Font("粗体", Font.BOLD, 18));
        l2.setFont(new Font("粗体", Font.BOLD, 18));
        l3.setFont(new Font("粗体", Font.BOLD, 18));
        

        inputPane.setForeground(Color.WHITE);
        inputPane.setFont(new Font("粗体", Font.PLAIN, 20));
        JScrollPane scroll1=new JScrollPane(inputPane);
        scroll1.setVerticalScrollBarPolicy( 
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS); 
        scroll1.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        inputPane.setBackground(Color.black);
        
        inputPanel.setLayout(new GridLayout(3,2,20,20));
        inputPanel.add(l1);
        inputPanel.add(t1=new JTextField(30));
        inputPanel.add(l2);
        l2.setForeground(Color.RED);
        inputPanel.add(t2=new JTextField(30));
        inputPanel.add(l3);
        l3.setForeground(Color.BLUE);
        inputPanel.add(t3=new JTextField(30));
        
       
        
        JButton jButton=new JButton("start");
        jButton.setForeground(Color.red);
        jButton.setFont(new Font("粗体", Font.PLAIN, 20));
        JPanel buttonPanel=new JPanel();
        buttonPanel.add(jButton);
        jButton.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO Auto-generated method stub
                LRTable lrTable= new LRTable();
                String string = t1.getText();
                lrTable.start = string.charAt(0);
                string = t2.getText();
                lrTable.setfinality(string);
                string = t3.getText();
                lrTable.setunfinality(string);  
              
                lrTable.arrayList.add("0->"+lrTable.start);
                String inputString = inputPane.getText();
                String[] all = inputString.split("\n+");
            //    System.out.println(all.length);
                for(int i=0;i<all.length;++i){
                //	System.out.println(all[i]);
                	all[i] = all[i].trim();
                	if(all[i].length() != 0)
                		lrTable.arrayList.add(all[i]);
                }
                LR.lr(lrTable);
                ShowJTable.Count = 0;
                new ShowJTable(lrTable.CaleTableDefine(), "LR表");
                new ShowJTable(lrTable.getAnalyTable(),"LR分析表");
                new ShowJTable(lrTable.getTableLink(), "LR关系表");

                syntax=JOptionPane.showInputDialog("请输入需要分析的语句");

                new ShowJTable(lrTable.SyntaxAnaly(syntax), "语句分析");
                
            }
        });
       
        
        setLayout(new BorderLayout(20,20));
        getContentPane().add(mainJPanel,BorderLayout.CENTER);
        getContentPane().add(buttonPanel,BorderLayout.SOUTH);
        getContentPane().add(new JPanel(),BorderLayout.WEST);
        getContentPane().add(new JPanel(),BorderLayout.NORTH);
        getContentPane().add(new JPanel(),BorderLayout.EAST);

        
        mainJPanel.add(inputPanel);

        mainJPanel.add(scroll1);
  
        
        
        new DropTarget(this, DnDConstants.ACTION_COPY_OR_MOVE, new DropTargetAdapter()
        {
            @SuppressWarnings("unchecked")
            @Override
            public void drop(DropTargetDropEvent dtde)//重写适配器的drop方法
            {
                try
                {
                    if (dtde.isDataFlavorSupported(DataFlavor.javaFileListFlavor))//如果拖入的文件格式受支持
                    {
                        dtde.acceptDrop(DnDConstants.ACTION_COPY_OR_MOVE);//接收拖拽来的数据
                        List<File> list = (List<File>) (dtde.getTransferable().getTransferData(DataFlavor.javaFileListFlavor));
                        File file = list.get(0);
                        dtde.dropComplete(true);//指示拖拽操作已完成
                        readFile(file);
                    }
                    else
                    {
                        dtde.rejectDrop();//否则拒绝拖拽来的数据
                    }
                }
                catch (NoSuchElementException noe) {
                    System.out.println("文件输入格式错误");
                    System.out.println("正确的输入格式是:第一行开始符,第二行终结符集合,第三行非终结符集合，下面若干行LR文法");
                    noe.printStackTrace();
                }
                catch (Exception e)
                { 
                    e.printStackTrace();
                }
            }
        });
        
        validate();
        
        JOptionPane.showMessageDialog(null,message , "提示消息",JOptionPane.PLAIN_MESSAGE);
    }
    void readFile(File file) throws FileNotFoundException{
    		Scanner scanner = new Scanner(file);
            
            String string = scanner.nextLine();
            t1.setText(string);
            string = scanner.nextLine();
            t2.setText(string);
            string = scanner.nextLine();
            t3.setText(string);
          
            String expressions = "";
            while(scanner.hasNext()){
                string = scanner.nextLine();
                expressions +=string+"\n";
            }
            inputPane.setText(expressions);
            scanner.close(); 
    	
    }
    public void actionPerformed(ActionEvent e) {
    	String actionCommand = e.getActionCommand();
    	if (e.getSource() instanceof JMenuItem) {
    	      // Handle menu item events
    	      if ("Open file".equals(actionCommand))
    	      {
    	    	  open();
    	      }else if("Help".equals(actionCommand)){
    	    	  JOptionPane.showMessageDialog(null,message , "提示消息",JOptionPane.PLAIN_MESSAGE);
    	      }
    	      else if ("Close".equals(actionCommand))
    	        System.exit(0);
    	    }
    }
    JFileChooser jFileChooser=new JFileChooser(new File("."));
    void open(){
		if(jFileChooser.showOpenDialog(this)==JFileChooser.APPROVE_OPTION){
			File file=jFileChooser.getSelectedFile();
			try{
				
				readFile(file);
				
			}catch(IOException ex){
				JOptionPane.showMessageDialog(null,"Error opening"+file.getName() , "提示消息",JOptionPane.WARNING_MESSAGE);
				
			}
		}
	}
	public static void main(String[] args)  {
		// TODO Auto-generated method stub
		new Main().Init();
	}

    
	
}