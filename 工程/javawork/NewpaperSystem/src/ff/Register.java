package ff;


import java.sql.*;

public class Register {
	int IsNoRepeated(String name,String password){
		String sqlcode = "select password from RECORD "+
				" where name = "+ "'"+ name + "'";
		ResultSet rs = null;
		try {
			rs = Main.stm.executeQuery(sqlcode);
			if(!rs.next())
				return -1;
			else if(rs.getString(1).equals(password))
				return 1;
			else
				return 0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return -2;
	}
	

}
