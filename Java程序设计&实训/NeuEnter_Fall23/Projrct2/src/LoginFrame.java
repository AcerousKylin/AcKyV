import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class LoginFrame extends JFrame{
    JLabel user;
    JTextField userInput;
    JLabel password;
    JPasswordField passwordInput;
    JButton button;
    JButton button1;

    AccountVerify verify = new AccountVerify();

    public LoginFrame()
    {
        initFrame();
        initInput();
    }

    private void initFrame()
    {
        ImageIcon  bg = new ImageIcon("imgs/BackPicture1.jpeg");

        JLabel backP = new JLabel(bg);
        backP.setSize(this.getWidth(), this.getHeight());
        
        JPanel pan =  (JPanel)getContentPane();
        pan.setOpaque(false);
        pan.setLayout(new FlowLayout());

        getLayeredPane().add(backP, Integer.MIN_VALUE);
        setSize(650, 500);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);//启动窗口关闭功能
        setResizable(false);//设置窗口是否开启放大功能
        setLocationRelativeTo(null);//设置窗口初始位置为屏幕中央
        setTitle("登陆界面");
    }

    public void initInput()
    {
        user = new JLabel("用户名：");
        user.setBounds(130, 70, 100, 50);
        user.setForeground(Color.red);
        user.setFont(new Font("楷体", Font.PLAIN, 25));
        this.add(user);

        userInput = new JTextField(20);
        userInput.setBounds(230, 80, 200, 30);
        userInput.setFont(new Font("楷体", Font.PLAIN, 15));
        this.add(userInput);

        password = new JLabel("密码：");
        password.setBounds(130, 170, 100, 50);
        password.setForeground(Color.red);
        password.setFont(new Font("楷体", Font.PLAIN, 25));
        this.add(password);

        passwordInput = new JPasswordField(20);
        passwordInput.setBounds(230, 180, 200, 30);
        this.add(passwordInput);

        button = new JButton("登录");
        button.setBounds(185, 275, 100, 50);
        button.setFont(new Font("楷体", Font.PLAIN, 20));
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                String username = userInput.getText().toString().trim();
                String password = passwordInput.getText().toString();
                JLabel jbin = new JLabel(username);

                verify = new AccountVerify();
                int flag = verify.loginCheck(username, password);
                
                switch (flag)
                {
                    case -1:
                        JOptionPane.showMessageDialog(null, "用户不存在", "提示", JOptionPane.INFORMATION_MESSAGE);
                        break;
                    case 0:
                        System.out.println("Password you entered is " + password + ".");
                        JOptionPane.showMessageDialog(null,"密码错误","提示",JOptionPane.INFORMATION_MESSAGE);
                        break;
                    case 1:
                        setVisible(false);
                        CharFrame mf1 = new CharFrame();
                        mf1.setVisible(true);
                        break;
                }
            }
        });
        this.add(button);

        button1 = new JButton("注册");
        button1.setBounds(345, 275, 100, 50);
        button1.setFont(new Font("楷体", Font.PLAIN, 20));
        button1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                SigninFrame signinFrame = new SigninFrame(verify);
                signinFrame.setVisible(true);
            }
        });
        this.add(button1);

        passwordInput.addKeyListener(new KeyAdapter()
        {
            @Override
            public void keyPressed(KeyEvent e)
            {
                if(e.getKeyCode() == KeyEvent.VK_ENTER)
                {
                    String username = userInput.getText().toString().trim();
                    String password = passwordInput.getText().toString();
                    JLabel jbin = new JLabel(username);

                    int flag = verify.loginCheck(username, password);
                    
                    switch (flag)
                    {
                        case -1:
                            JOptionPane.showMessageDialog(null, "用户不存在", "提示", JOptionPane.INFORMATION_MESSAGE);
                            break;
                        case 0:
                            System.out.println("Password you entered is " + password + ".");
                            JOptionPane.showMessageDialog(null,"密码错误","提示",JOptionPane.INFORMATION_MESSAGE);
                            break;
                        case 1:
                            setVisible(false);
                            CharFrame mf1 = new CharFrame();
                            mf1.setVisible(true);
                            break;
                    }
                }
            }
        });
    }
}
