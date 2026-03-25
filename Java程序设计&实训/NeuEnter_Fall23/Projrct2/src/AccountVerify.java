import java.io.*;
import java.util.*;
import java.lang.Thread;

public class AccountVerify extends Thread{
     
    private Map<String, String> mapInfo = new HashMap<>();
    File fileInfo;
    

    public AccountVerify ()
    {
        String[] tempInfo = new String[2];
        try {
        fileInfo = new File("data/user_info.txt");

        FileInputStream fileInputStream = new FileInputStream(fileInfo);
        Scanner input = new Scanner(fileInputStream, "utf-8");

        while (input.hasNextLine())
        {
            String line = input.nextLine();

            tempInfo = line.split("\\|");
            System.out.println("Account input: " + tempInfo[0].toString().trim() + "|" + tempInfo[1].toString().trim());
            mapInfo.put(tempInfo[0].toString().trim(), tempInfo[1].toString().trim());
        }
        input.close();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    public int loginCheck(String account, String password)
    {
        boolean vAccount=false, vPassword=false;
        String tempAccount="";
        for (String a : mapInfo.keySet())
        {
            if (a.equals(account))
            {
                vAccount = true;
                tempAccount = a;
                break;
            }
        }

        if (vAccount)
        {
            System.out.println("Find user account: " + tempAccount);
            if (password.equals(mapInfo.get(tempAccount)))
                vPassword = true;
        }
        else
            return -1;
        
        if (vPassword)
            return 1;
        else
            return 0;
    }

    public boolean signinCheck(String account)
    {
        for (String a : mapInfo.keySet())
        {
            if (a.equals(account))
            {
                System.out.println("Exist account is " + account + ".");
                return false;
            }
        }
        return true;
    }

    public void signin(String account, String password)
    {
        String signinInfo = account + " | " + password;
        try {
            FileOutputStream fileOutputStream = new FileOutputStream(fileInfo, true);
            fileOutputStream.write("\n".getBytes());
            fileOutputStream.write(signinInfo.getBytes());
            fileOutputStream.close();
            System.out.println("Account signed in for " + account + "with password +" + ".");
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }
}
