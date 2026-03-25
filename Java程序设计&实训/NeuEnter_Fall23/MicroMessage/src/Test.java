import java.sql.*;
import DataGripping.*;
import Frames.ChatFrame.ChatFrame;
import Frames.ChatFrame.Client;
import Frames.LoginFrame.LoginFrame;
import Tables.*;

public class Test {

    public void runChatFrameDebug()
    {
        Client client = new Client("AcerousKylin");
        // chatFrame.dispose();
    }
    
    public void runLoginFrameDebug()
    {
        LoginFrame loginFrame = new LoginFrame();
        // loginFrame.dispose();
    }

    public void runSQLDebug(String schema)
    {
        UserInfo user1 = new UserInfo();
        user1.genValue();
        try {
            PreStatement genStatement = new PreStatement(schema);
            genStatement.getRawStatement().executeUpdate(user1.sqlInsert());
            System.out.println("Test.runDebug: A sql was finished.");
            genStatement.close();
        } catch (SQLException sqle) {
            sqle.printStackTrace();
        }
    }

    public void truncateTable(String schema, String table)
    {
        try {
            PreStatement genStatement = new PreStatement(schema);
            genStatement.getRawStatement().executeUpdate("TRUNCATE " + table + ";");
            System.out.println("Test.truncate: Target table was truncated.");
            genStatement.close();
        } catch (SQLException sqle) {
            sqle.printStackTrace();
        }
    }
}
