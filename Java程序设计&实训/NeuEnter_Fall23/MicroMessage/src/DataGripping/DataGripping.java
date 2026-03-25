package DataGripping;

import java.sql.*;
import com.mysql.cj.jdbc.MysqlDataSource;
import javax.sql.DataSource;

public class DataGripping {
    private static final String testURL = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf-8 && useSSL=false&serverTimezone=UTC && allowPublicKeyRetrieval=true";
    private static final String userURL = "jdbc:mysql://127.0.0.1:3306/user?characterEncoding=utf-8 && useSSL=false&serverTimezone=UTC && allowPublicKeyRetrieval=true";
    private static final String groupURL = "jdbc:mysql://127.0.0.1:3306/group?characterEncoding=utf-8 && useSSL=false&serverTimezone=UTC && allowPublicKeyRetrieval=true";
    private static final String USER_NAME = "root";
    private static final String PASSWORD = "2003*0619";
    
    private DataSource dataSource = new MysqlDataSource();
    private Connection connection;

    public DataGripping(String schema)
    {
        switch (schema)
        {
            case "test":
                ((MysqlDataSource)this.dataSource).setURL(testURL);
                System.out.println("DataGripping.~: Use schema test now.");
                break;
            case "user":
                ((MysqlDataSource)this.dataSource).setURL(userURL);
                System.out.println("DataGripping.~: Use schema user now.");
                break;
            case "group":
                ((MysqlDataSource)this.dataSource).setURL(groupURL);
                System.out.println("DataGripping.~: Use schema group now.");
                break;
            default:
                System.out.println("DataGripping.~: Schema isn't exist, connection building failed.");
        }
        
        ((MysqlDataSource)this.dataSource).setUser(USER_NAME);
        ((MysqlDataSource)this.dataSource).setPassword(PASSWORD);
        try{
            this.connection = this.dataSource.getConnection();
            System.out.println("DataGripping.~: Schema connection is now available.");
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public Connection getConnection()
    {
        return this.connection;
    }

    public void close() throws SQLException
    {
        System.out.println("DateGripping.~: Schema connection is about to disconnect.");
        connection.close();
    }

    // public void closeAll(Connection connection, PreparedStatement statement, ResultSet resultSet)
    // {
    //     if (resultSet != null)
    //     {
    //         try {
    //             resultSet.close();
    //         } catch (SQLException e) {
    //             e.printStackTrace();
    //         }
    //     }
        
    //     if (statement != null)
    //     {
    //         try {
    //             statement.close();
    //         } catch (SQLException e) {
    //             e.printStackTrace();
    //         }
    //     }

    //     if (connection != null)
    //     {
    //         try {
    //             connection.close();
    //         } catch (SQLException e) {
    //             e.printStackTrace();
    //         }
    //     }
    // }
}
