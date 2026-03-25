package DataGripping;

import java.sql.*;
import java.util.*;

public class PreStatement extends DataGripping{
    
    private String sql;
    private Statement rawStatement;
    private PreparedStatement preStatement;
    private CallableStatement calStatement;
    private final Map<String, Boolean> active = new HashMap<>();
    {
        active.put("raw", false);
        active.put("pre", false);
        active.put("cal", false);
    }

    public PreStatement(String schema, String sql) throws SQLException
    {
        super(schema);
        this.sql = sql;
        System.out.println("DataGripping.PreStatement: Initializing schema with a sql.");
    }

    public PreStatement(String schema)
    {
        super(schema);
        System.out.println("DataGripping.PreStatement: Initializing schema without a sql.");
    }

    public Statement getRawStatement() throws SQLException
    {
        active.replace("raw", false, true);
        this.rawStatement = super.getConnection().createStatement();
        return rawStatement;    
    }

    public PreparedStatement getPreStatement() throws SQLException
    {   
        active.replace("pre", false, true);
        this.preStatement = super.getConnection().prepareStatement(sql);
        return preStatement;
    }

    public Statement getCalStatement() throws SQLException
    {
        active.replace("cal", false, true);
        this.calStatement = super.getConnection().prepareCall(sql);
        return calStatement;
    }

    public void close() throws SQLException
    {
        System.out.println("DataGripping.PreStatement: All statement will be released soon. Triggering schema connection to close too.");
        if (active.get("raw"))
            this.rawStatement.close();
        if (active.get("pre"))
            this.preStatement.close();
        if (active.get("cal"))
            this.calStatement.close();
        super.close();
    }
}
