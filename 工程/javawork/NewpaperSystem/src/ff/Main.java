package ff;

import java.awt.Color;
import java.sql.*;

import javax.swing.*;




public class Main {
		private static String url = "jdbc:sqlserver://localhost:1433;DatabaseName=NewpaperSystem";
		private static String pname = "sa";
		private static String pword = "123456";
		static String username;
		static Connection cn;
		static Statement stm;
		static LoginActivity start = new LoginActivity();
		public static void main(String[] args) {
			start.Init();
		try {	
			LoginActivity.jb.setText("���ڼ���SQLServerDriver������");
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver"); 
			LoginActivity.jb.setText("SQLServerDriver���سɹ�");
			LoginActivity.jb.setText("��������sql server...");
			cn = DriverManager.getConnection(url,pname,pword );
			LoginActivity.jb.setText("���");
			stm = cn.createStatement();
		
			
			
			
			
			
	//		stm.close();
	//		cn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			LoginActivity.jb.setForeground(Color.red);
			LoginActivity.jb.setText("SQLException");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			LoginActivity.jb.setForeground(Color.red);
			LoginActivity.jb.setText("ClassNotFoundException");
		} 
		
		
	}

}