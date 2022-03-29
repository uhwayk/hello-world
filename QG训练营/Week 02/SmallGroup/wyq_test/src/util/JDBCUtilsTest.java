package util;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class JDBCUtilsTest {

    public static void main(String[] args) {
        List<UserBean> list = findAll();
        System.out.println("list = " + list);
    }

    //定义一个方法，查询user表的数据将其封装为对象，然后装载集合，返回。
    public static List<UserBean> findAll(){
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;
        List<UserBean> list = null;
        try {
            conn = JdbcUtils.getConnection();
            //定义sql
            String sql = "SELECT * FROM usr";
            //获取执行sql的对象
            st = conn.createStatement();
            //执行sql
            rs = st.executeQuery(sql);
            UserBean bean = null;
            list = new ArrayList<UserBean>();
            while (rs.next()){
                int id = rs.getInt("id");
                String username = rs.getString("username");
                String password = rs.getString("password");
                bean = new UserBean(id,username,password);
                list.add(bean);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(rs,st,conn);
        }
        return list;
    }
}
