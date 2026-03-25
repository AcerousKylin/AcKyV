package Frames.LoginFrame;

import javax.swing.*;
import java.awt.*;

public class MessagePopup extends JFrame{

    private Container contentPane = this.getContentPane();

    public MessagePopup(String message)
    {
        if (message == "Account")
            this.setTitle("Account Not Exists!");

    }
}
