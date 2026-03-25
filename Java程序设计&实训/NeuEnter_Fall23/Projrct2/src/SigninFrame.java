import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SigninFrame extends JFrame{
        public JLabel jl1, jl2, jl3;
        public JTextField jtf1;
        public JPasswordField jpf1=new JPasswordField(), jpf2=new JPasswordField();
        public JButton button1;

        private SigninFrame sf = this;

        AccountVerify verify = new AccountVerify();

        public SigninFrame(AccountVerify a){
            verify = a;
            initFrame();
            initInput();
        }

        public void initFrame(){
            setSize(650, 500);
            getContentPane().setBackground(new Color(0xfabb66));
            setLocationRelativeTo(null);
            setResizable(false);
            setTitle("注册新用户");
            setLayout(null);
            setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        }

        public void initInput(){
            jl1 = new JLabel("用户名：");
            jl1.setBounds(130, 70, 100, 50);
            jl1.setForeground(Color.red);
            jl1.setFont(new Font("楷体", Font.PLAIN, 25));
            add(jl1);

            jtf1 = new JTextField(20);
            jtf1.setBounds(230, 80, 200, 30);
            jtf1.setFont(new Font("楷体", Font.PLAIN, 15));
            add(jtf1);

            jl2 = new JLabel("密码：");
            jl2.setBounds(130, 150, 100, 50);
            jl2.setForeground(Color.red);
            jl2.setFont(new Font("楷体", Font.PLAIN, 25));
            add(jl2);

            jpf1 = new JPasswordField(20);
            jpf1.setBounds(230, 160, 200, 30);
            add(jpf1);

            jl3 = new JLabel("确认密码：");
            jl3.setBounds(100, 230, 130, 50);
            jl3.setForeground(Color.red);
            jl3.setFont(new Font("楷体", Font.PLAIN, 25));
            add(jl3);

            jpf2 = new JPasswordField();
            jpf2.setBounds(230, 240, 200, 30);
            add(jpf2);

            button1 = new JButton("注册");
            button1.setBounds(270, 300, 100, 50);
            button1.setFont(new Font("楷体", Font.PLAIN, 20));
            add(button1);
            button1.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    String username = jtf1.getText().toString();
                    String psdInput1 = jpf1.getText().toString();
                    String psdInput2 = jpf2.getText().toString();

                    boolean exist = verify.signinCheck(username);

                    if (!exist)
                        JOptionPane.showMessageDialog(null,"用户名已存在","提示",JOptionPane.INFORMATION_MESSAGE);
                    else if (psdInput1.equals(null) || psdInput1.equals(""))
                    {
                        JOptionPane.showMessageDialog(null,"密码不能为空","提示",JOptionPane.INFORMATION_MESSAGE);
                    }
                    else if (psdInput1.equals(psdInput2))
                    {
                        verify.signin(username, psdInput1);
                        JOptionPane.showMessageDialog(null,"注册成功","提示",JOptionPane.INFORMATION_MESSAGE);
                        sf.dispose();
                    }
                    else
                        JOptionPane.showMessageDialog(null,"密码不一致","提示",JOptionPane.INFORMATION_MESSAGE);
                }
            });
        }
}
