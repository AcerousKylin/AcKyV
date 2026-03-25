package Frames.LoginFrame;

import DataGripping.*;
import Frames.FrameUtils.LinkLabel;
import Frames.FrameUtils.ScreenUtils;
import Frames.FrameUtils.ComponentUtils;
import Frames.MainFrame.MainFrame;

import javax.swing.*;
import java.sql.*;
import java.util.Random;
import java.awt.*;
import java.awt.event.*;

public class LoginFrame extends JFrame{
    
    protected Container topPane = getContentPane();

    // BorderLayout panels in Center and South
    private JPanel panelCenter = new JPanel(new FlowLayout(FlowLayout.CENTER, 0, 10));
    private JPanel panelSouth = new JPanel(new FlowLayout(FlowLayout.CENTER, 150, 0));
    private JPanel panelWest = new JPanel();

    private Color attribute1 = new Color(10, 60, 110, 125);
    private Color attribute2 = new Color(110, 10, 60, 125);
    private Color attribute3 = new Color(60, 110, 10, 125);

    private MouseAdapter signupMouseAdapter = new MouseAdapter() // r3v = retrieve
    {
        @Override
        public void mouseClicked(MouseEvent e)
        {
            
        }
    };

    private MouseAdapter r3vMouseAdapter = new MouseAdapter() // r3v = retrieve
    {
        @Override
        public void mouseClicked(MouseEvent e)
        {
            
        }
    };

    private MouseAdapter serviceMouseAdapter = new MouseAdapter()
    {
        @Override
        public void mouseClicked(MouseEvent e)
        {

        }
    };

    public LoginFrame()
    {
        // BorderLayout panels constructing
        constructPanelInput();
        constructSouth();
        // debugButton();

        Random colorRdm = new Random();
        switch (colorRdm.nextInt(2))
        {
            case 0:
                panelCenter.setBackground(attribute1);
                panelSouth.setBackground(attribute2);
                panelWest.setBackground(attribute3);
                break;
            case 1:
                panelCenter.setBackground(attribute2);
                panelSouth.setBackground(attribute3);
                panelWest.setBackground(attribute1);
                break;
            case 2:
                panelCenter.setBackground(attribute3);
                panelSouth.setBackground(attribute1);
                panelWest.setBackground(attribute2);
        }

        // Basic configuration and construction with frame and content pane
        this.setResizable(false);
        this.setTitle("MicroMessages");
        this.setSize(500, 300);
        this.setLocationByPlatform(false);
        this.setLocation(ScreenUtils.getScreenSize().width/2 - this.getSize().width/2, ScreenUtils.getScreenSize().height/2 - this.getSize().height/2);
        
        
        topPane.setLayout(new BorderLayout());
        topPane.add(panelCenter, BorderLayout.CENTER);
        topPane.add(panelSouth, BorderLayout.SOUTH);
        this.setAutoRequestFocus(false);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
    }

    private void constructPanelInput()
    {
        // Components of centre panel

        // Center avatar
        JLabel labelAvatar;
        ImageIcon avatar = new ImageIcon("images/default_avatar.jpg");
        labelAvatar = new JLabel(avatar);

        // Textfield of Account
        JTextField textfieldAccount = new JTextField("", 20);
        textfieldAccount.requestFocus();
        ComponentUtils.preShownListenerApply(textfieldAccount, "Account");
        JLabel labelAccount = new JLabel("Account: ");

        // Password Field of ... like that
        JPasswordField textfieldPwd = new JPasswordField("", 20);
        JLabel labelPwd = new JLabel("Password: ");

        // Field panels construct and combine
        JPanel panelField = new JPanel(new FlowLayout(FlowLayout.RIGHT, 15, 15));
        panelField.add(textfieldAccount, 0);
        panelField.add(textfieldPwd, 1);
        panelField.setPreferredSize(new Dimension(225, 100));
        panelField.setOpaque(false);

        JPanel panelLabel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 0, 18));
        panelLabel.add(labelAccount, 0);
        panelLabel.add(labelPwd, 1);
        panelLabel.setPreferredSize(new Dimension(75, 100));
        panelLabel.setOpaque(false);

        JPanel panelInput = new JPanel(new FlowLayout(FlowLayout.CENTER, 0, 15));
        panelInput.add(panelLabel, 0);
        panelInput.add(panelField, 1);
        panelInput.setPreferredSize(new Dimension(400, 100));
        panelInput.setOpaque(false);

        // final construct for fields and labels
        panelCenter.add(labelAvatar, 0);
        panelCenter.add(panelInput, 1);

        // Construction tips
        System.out.println("LoginFrame.~: Input Panel construction complete.");

        // Constructing main login button
        JButton buttonLogin = new JButton("Login");
        buttonLogin.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                try {
                    // Preparing SQL statement
                    PreStatement preStatement = new PreStatement("user", "SELECT user_id, password FROM user_info WHERE user_id = ?");
                    PreparedStatement preparedStatement = preStatement.getPreStatement();
                    preparedStatement.setLong(1, Long.valueOf(textfieldPwd.getInputContext().toString()));
                    ResultSet resultset = preparedStatement.executeQuery();
                    boolean verifiedAccount = false, verifiedPassword = false;
                    do {
                        if (resultset.getLong("user_info") == Long.valueOf(textfieldPwd.getInputContext().toString()))
                        {
                            verifiedAccount = true;
                            if (resultset.getString("password") == textfieldPwd.getInputContext().toString())
                            {
                                verifiedPassword = true;
                                break;
                            }
                        }
                    } while (resultset.next());
                    
                    // Popup error messages
                    if (verifiedAccount && verifiedPassword)
                    {
                        MainFrame mainFrame = new MainFrame();
                        mainFrame.setVisible(true);
                    }
                    else if (!verifiedAccount)
                    {
                        MessagePopup accountNotExists =  new MessagePopup("Account");
                        accountNotExists.setVisible(true);
                    }
                    else if (verifiedAccount && !verifiedPassword)
                    {
                        MessagePopup pwdNotVerified = new MessagePopup("Password");
                        pwdNotVerified.setVisible(true);
                    }
                    
                } catch (SQLException sqle) {
                    sqle.printStackTrace();
                }
            }
        });
        panelCenter.add(buttonLogin, 2);
        System.out.println("LoginFrame.~: Input Panel construction complete.");
    }

    private void constructSouth()
    {
        // Components of south panel
        JLabel labelR3vPwd = new JLabel("retrieve password");
        labelR3vPwd.addMouseListener(r3vMouseAdapter);
        JLabel labelSignup = new JLabel("sign up");
        labelSignup.addMouseListener(signupMouseAdapter);
        LinkLabel labelService = new LinkLabel("service", "");
        labelService.addMouseListener(serviceMouseAdapter);

        panelSouth.add(labelR3vPwd, 0);
        panelSouth.add(labelService, 1);
    }

    private void debugButton(LoginFrame loginFrame)
    {
        // Debug button settings
        JButton resetAll = new JButton("regenerate");
        resetAll.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                loginFrame.dispose();
                new LoginFrame();
            }
        });

        panelWest.add(resetAll);
        topPane.add(panelWest, BorderLayout.WEST);
    }
}
