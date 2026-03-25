package Tables;

import java.util.Random;
// import java.util.Date;

public class UserInfo extends Table{

    {   super.tableName = "user_info";  }
    protected long id=0;
    protected String name="", password="", nickname, gender, intro;
    protected String avatar, birthday, createTime, updateTime;
    protected int status;
    
    public void setID(long id)                  {   this.id = id;   }
    public void setName(String name)            {   this.name = name;   }
    public void setPassword(String password)    {   this.password= password;    }
    public void setNickname(String nickname)    {   this.nickname = nickname;   }
    public void setGender(String gender)        {   this.gender = gender;   } 
    public void setIntro(String intro)          {   this.intro = intro; }
    public void setAvatar(String avatar)        {   this.avatar = avatar;   }
    public void setBirthday(String birthday)    {   this.birthday = birthday;   }
    public void setCreateTime(String createTime){   this.createTime = createTime;   }
    public void setUpdateTime(String updateTime){   this.updateTime = updateTime;   }
    public void setStatus(int status)           {   this.status = status;   }

    public long getID()             {   return this.id;   }
    public String getName()         {   return this.name;   }
    public String getPassword()     {   return this.password;    }
    public String getNickname()     {   return this.nickname;  }
    public String getGender()       {   return this.gender;   }
    public String getIntro()        {   return this.intro; }
    public String getAvatar()       {   return this.avatar;   }
    public String getBirthday()     {   return this.birthday;   }
    public String getCreateTime()   {   return this.createTime;   }
    public String getUpdateTime()   {   return this.updateTime;   }
    public int getStatus()          {   return this.status;   }
    
    public UserInfo()
    {
        this.tableName = "user_info";
    }
    
    @Override
    public String toString()    {   return id + ", " + name + ", " + password + ", " + nickname + ", " + gender + ", " + avatar + ", " + birthday + ", " + intro  + ", " + status + ", " + createTime + ", " + updateTime; }

    public void genValue()
    {
        char[] tempChar = new char[10];
        Random numGen = new Random();   Random strGen = new Random();

        setID(numGen.nextLong(999999999)+1 );
        
        for (int i=0; i<10; i++)
        {
            if (strGen.nextInt(1) == 0)
                tempChar[i] = (char) ( 'a' + (strGen.nextInt(25)) );
            else
                tempChar[i] = (char) ( 'A' + (strGen.nextInt(25)) );
        }
        setName("\"" + tempChar.toString() + "\"");

        setPassword("\"1234567879\"");
        setNickname("\"Anderson\"");
        setGender( (numGen.nextInt(1) == 0)?"\"男\"":"\"女\"" );
        setIntro("\"dead\"");
        setAvatar("\"default\"");
        setBirthday("\"2000-01-01\"");
        setCreateTime("\"2000-01-01 12:00:00\"");
        setUpdateTime("\"2023-09-01 12:00:00\"");
        setStatus(numGen.nextInt(1));
    }

    public void testValue()
    {
        Random numGen = new Random();
        setID(numGen.nextLong(999999999)+1 );
    }
}
