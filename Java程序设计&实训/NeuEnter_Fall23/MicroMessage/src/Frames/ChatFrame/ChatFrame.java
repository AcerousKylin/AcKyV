package Frames.ChatFrame;

import Frames.FrameUtils.ScreenUtils;
import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class ChatFrame extends JFrame{
    private Container contentPane = this.getContentPane();

    private JPanel panelLeft = new JPanel();
    private JPanel panelRight = new JPanel();

    protected JTextArea areaMessages = new JTextArea();
    protected JTextArea areaInput = new JTextArea();
    protected JLabel labelAvatar = new JLabel();
    protected JButton buttonSend = new JButton();

    public ChatFrame(String nameFriend)
    {
        contentPane.setLayout(new BorderLayout());

        constructPanelLeft();
        constructPanelRight();

        this.setTitle(nameFriend);
        this.setLocationByPlatform(false);
        this.setSize(new Dimension(900, 540));
        this.setResizable(false);
        this.setLocation(ScreenUtils.getScreenSize().width/2 - this.getSize().width/2, ScreenUtils.getScreenSize().height/2 - this.getSize().height/2);
        this.setAutoRequestFocus(false);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
    }

    private void constructPanelLeft()
    {
        areaMessages.setPreferredSize(new Dimension(560, 375));
        areaMessages.setEditable(false);
        areaMessages.setBackground(new Color(200, 200, 200, 200));
        areaInput.setPreferredSize(new Dimension(560, 120));
        
        panelLeft.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 15));
        panelLeft.setPreferredSize(new Dimension(580, 540));
        panelLeft.setBackground(debugMethod());

        panelLeft.add(new JScrollPane(areaMessages));
        panelLeft.add(new JScrollPane(areaInput));
        contentPane.add(panelLeft, BorderLayout.WEST);
    }

    private void constructPanelRight()
    {
        ImageIcon avatar = new ImageIcon("images/default_avatar.jpg");
        labelAvatar = new JLabel(avatar);
        buttonSend.setText("Send");

        panelRight.setPreferredSize(new Dimension(160, 540));
        panelRight.setLayout(new FlowLayout(FlowLayout.CENTER, 50, 120));
        panelRight.add(labelAvatar, 0);
        panelRight.add(buttonSend, 1);
        panelRight.setBackground(debugMethod());

        contentPane.add(panelRight, BorderLayout.EAST);
    }

    private Color debugMethod()
    {
        Random clrRdm = new Random();
        Color attribute = new Color(clrRdm.nextInt(255), clrRdm.nextInt(255), clrRdm.nextInt(255), clrRdm.nextInt(255));
        return attribute;
    }
}
