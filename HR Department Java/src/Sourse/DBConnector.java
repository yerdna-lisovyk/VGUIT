package Sourse;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class DBConnector {
    public static String url = "jdbc:mysql://localhost:3306/Store";
    public static String username = "root";
    public static String password = "";
    public static Connection conn;
    public static Statement statement;

    static {
        try {
            conn = DriverManager.getConnection(url, username,password);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            throw new RuntimeException();
        }
    }

    static {
        try {
            statement = conn.createStatement();

        } catch (SQLException throwables) {
            throwables.printStackTrace();
            throw new RuntimeException();
        }
    }
}
