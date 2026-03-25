package Frames.ChatFrame;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.*;
import java.text.SimpleDateFormat;

public class Server {
    private Socket socket;
    private String nameFriend;

    public final static int PORT =  21012;
    
    {
        try {
            ServerSocket serverSocket = new ServerSocket(PORT);

            while (true)
            {
                socket = serverSocket.accept();
                serverSocket.close();
                new ServerReader(socket).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class ServerReader extends Thread
    {
        private Socket socket;

        public ServerReader(Socket socket)
        {
            this.socket = socket;
        }

        @Override
        public void run()
        {
            DataInputStream inputDS = null;
            try {
                inputDS = new DataInputStream(socket.getInputStream());

                while (true)
                {
                    String message = inputDS.readUTF();
                    
                    System.out.println(nameFriend + " ----> " + message);
                    writeMessage(inputDS);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void writeMessage(DataInputStream inputDS) throws Exception
    {
        String message = null;
        StringBuilder fullMessage = new StringBuilder();
        SimpleDateFormat dateSD = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss EEE");
        fullMessage.append(nameFriend).append("  ").append(dateSD.format(System.currentTimeMillis())).append("\r\n");
        fullMessage.append("  ").append(message).append("\r\n");
        sendMessage(fullMessage.toString());
    }

    private void sendMessage(String message) throws Exception
    {
        DataOutputStream outputDS = new DataOutputStream(socket.getOutputStream());
        outputDS.writeUTF(message);
        outputDS.flush();
    }
}
