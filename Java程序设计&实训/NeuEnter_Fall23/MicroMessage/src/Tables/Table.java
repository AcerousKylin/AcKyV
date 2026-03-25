package Tables;

public class Table {
    protected String tableName = "";

    @Override
    public String toString()    {   return "";  }

    public String getTableName()    {   return tableName;   }

    public String sqlTruncate() {   return "TRUNCATE " + tableName + ";";   }

    protected String sqlDrop()  {   return "DROP " + tableName + ";";   }

    public String sqlInsert()   {   return "INSERT INTO " + tableName + " VALUE(" + this.toString() + ");"; }
}
