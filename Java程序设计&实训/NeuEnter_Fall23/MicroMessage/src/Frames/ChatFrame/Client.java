package Frames.ChatFrame;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataOutputStream;
import java.net.Socket;

import javax.swing.JButton;

public class Client extends ChatFrame implements ActionListener{
    private Socket socket;
    private String nameFriend;

    public Client(String nameFriend)
    {
        super(nameFriend);
        this.nameFriend = nameFriend;
        super.buttonSend.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        JButton buttonSend = (JButton) e.getSource();
        String message = super.areaMessages.getText().toString();
        if (!message.trim().equals(""))
        {
            try {
                DataOutputStream outputDS = new DataOutputStream(socket.getOutputStream());
                outputDS.writeUTF(message);
                outputDS.writeUTF(nameFriend);
                outputDS.flush();
            } catch (Exception DSe) {
                DSe.printStackTrace();
            }
        }
        super.areaMessages.setText(null);
    }

}
