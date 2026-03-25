package NeuEnter_Fall23.Aug_30;

import java.io.*;

public class PracticeIO {
    public static void main(String[] args)
    {
        try
        {
            FileInputStream inputFile = new FileInputStream("input.txt");
            BufferedInputStream inputStream = new BufferedInputStream(inputFile);

            String inputData="";
            inputStream.read(inputData.getBytes());
            inputStream.close();
            inputFile.close();

            FileOutputStream outputFile = new FileOutputStream("output.txt");
            BufferedOutputStream outputStream = new BufferedOutputStream(outputFile);

            // String outputData="";
            outputStream.write(inputData.getBytes());
            outputStream.flush();
            outputStream.close();
            inputStream.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
