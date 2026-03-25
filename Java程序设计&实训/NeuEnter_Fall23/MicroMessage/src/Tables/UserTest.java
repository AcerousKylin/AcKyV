package Tables;

import java.util.Random;
// import java.util.Date;

public class UserTest {

    private static String tableName = "user_test";
    protected long id=0;
    protected String testName="", birthday, createTime;
    protected int status=-1;
    
    public void setID(long id)                  {   this.id = id;   }
    public void setName(String name)            {   this.testName = name;   }
    public void setBirthday(String birthday)    {   this.birthday = birthday;   }
    public void setCreateTime(String createTime){   this.createTime = createTime;   }
    public void setStatus(int status)           {   this.status = status;   }

    public long getID()             {   return this.id;   }
    public String getName()         {   return this.testName;   }
    public String getBirthday()     {   return this.birthday;   }
    public String getCreateTime()   {   return this.createTime;   }
    public int getStatus()          {   return this.status;   }

    @Override
    public String toString()    {   return id + ", " + testName + ", " + birthday  + ", " + status + ", " + createTime; }

    public static String getTableName() {   return tableName;   }
    
    public String sqlInsert()
    {
        return "INSERT INTO " + tableName + " VALUE(" + this.toString() + ");";
    }

    public void genValue()
    {
        Random numGen = new Random();
        
        setID(numGen.nextLong(999999999)+1 );
        setName("\"name_" +  Long.toString(id) + "\"");
        setBirthday("\"2000-01-01\"");
        setStatus(numGen.nextInt(1));
        setCreateTime("\"2012-01-01 12:00:00\"");
    }

    public void testValue()
    {
        Random numGen = new Random();
        setID(numGen.nextLong(999999999)+1 );
    }
}

    // public void setInsertValues(PreparedStatement preparedStatement) throws SQLException
    // {
    //     if (id == 0)
    //         System.out.println("The PK of table haven't been inserted!");
    //     if (testName=="" || birthday=="" || createTime=="")
    //         System.out.println("Something of being generated for table user_info exists null value.");
    //     preparedStatement.setString(1, tableName);
    //     preparedStatement.setString(2, id + ", " + testName + ", " + birthday  + ", " + status + ", " + createTime); 
    //     System.out.println(preparedStatement.toString());
    //         // return "VALUE(" + id + ",\"" + name + "\",\"" + password + "\",\"" + nickname + "\",\"" + gender + "\",\"" + avatar + "\",\"" + birthday + "\",\"" + intro + "\"," + status + "," + createTime + "," + updateTime +");";
    // }