import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.net.*;

//继承窗口类可以使用窗口的方法，实现点击监听器
public class CharFrame extends JFrame implements ActionListener, KeyListener {
    //    声明成员属性，这样所有函数中都能使用
    DatagramSocket ds;
    DatagramPacket dp;
    JLabel jl1;
    JLabel jl2;
    JLabel jl3;
    JTextField jtf1;
    JTextField jtf2;
    JTextField jtf3;
    JButton jb1;
    JPanel jp1;
    JTextArea jta;
    String hostIP;
    JScrollPane jsp;
    int hostPort;
    //    构造器初始化 ，利用模块化分别给界面的各个资源初始化
    public CharFrame()
    {
        initSocket();
        initFrame();
        initIpPort();
        initSendMsg();
        initTextArea();
    }

    public void initFrame()
    {
//        窗口初始化
        setSize(600,400);
//        位置居中
        setLocationRelativeTo(null);
        setResizable(false);
//        标题
        setTitle("聊天窗口" + "  " + hostIP + "  " + hostPort);
//        绝对定位
        setLayout(null);
//        关闭按钮
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
    
    public void initIpPort()
    {
//        文本
        jl1= new JLabel("IP：");
        jl1.setBounds(40,310,50,30);
        jl1.setForeground(Color.blue);
        jl1.setFont(new Font("楷体", Font.PLAIN, 20));
        add(jl1);
//        输入框
        jtf1 = new JTextField();
        jtf1.setBounds(80,310,120,30);
        add(jtf1);

        jl2= new JLabel("PORT：");
        jl2.setBounds(210,310,70,30);
        jl2.setForeground(Color.blue);
        jl2.setFont(new Font("楷体", Font.PLAIN, 20));
        add(jl2);

        jtf2 = new JTextField();
        jtf2.setBounds(270,310,120,30);
        add(jtf2);
    }
    public void initSendMsg()
    {
//        按钮
        jb1 = new JButton("发送");
        jb1.setBounds(430,310,100,30);
        jb1.setFont(new Font("楷体", Font.PLAIN, 20));
        add(jb1);
//        按钮绑定点击处理函数
        jb1.addActionListener(this);

        jl3= new JLabel("聊天输入：");
        jl3.setBounds(40,270,100,30);
        jl3.setForeground(Color.blue);
        jl3.setFont(new Font("楷体", Font.PLAIN, 20));
        add(jl3);

        jtf3 = new JTextField();
        jtf3.setBounds(140,270,390,30);
        add(jtf3);

        jtf3.addKeyListener(this);
    }
    
    void initTextArea(){
//        文本域
        jta = new JTextArea();
        jta.setBackground(Color.white);
        jta.setFont(new Font("楷体", Font.PLAIN, 25));
        jta.setEditable(false);
        jsp = new JScrollPane();
        jsp.setBounds(0, 0, 585, 260);
        jsp.setViewportView(jta);
        add(jsp);
    }

    public void initSocket()
    {
//        初始化网络，udp协议对象
        try {
            ds = new DatagramSocket();
//            获取本机ip和端口
            hostPort = ds.getLocalPort();
            hostIP = InetAddress.getLocalHost().getHostAddress();
        } catch (SocketException e) {
            throw new RuntimeException(e);
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }
//        联网之后就后台建立一个读取线程一直等待别人发消息
        new RecevierThread().start();
    }
    //        点击相应函数
    @Override
    public void actionPerformed(ActionEvent e) {
//        怕网络延迟，利用线程启动发送数据
        new Thread(()->{ sendMsg();}).start();
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if(e.getKeyCode() == KeyEvent.VK_ENTER) {
            new Thread(()->{ sendMsg();}).start();
        }
    }



    public void sendMsg()
    {
        //        获得输入框的内容
        String ip = jtf1.getText();
        int port = Integer.parseInt(jtf2.getText());
        String msg = jtf3.getText();
//        System.out.println(ip+"   "+port+"   "+msg);
//        把文本内容变成字节数组方便存入数据包
        byte brr[] = msg.getBytes();
        try {
//            把指定数据包向指定ip和端口号发送
            dp = new DatagramPacket(brr,brr.length,InetAddress.getByName(ip),port);
            ds.send(dp);
            magAddSend(msg);
            jtf3.setText("");
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    public void magAddSend(String msg)
    {
        String text = "我：" + msg;

        jta.append(text + System.lineSeparator());
        jta.setCaretPosition(jta.getDocument().getLength());
    }

    public void msgAddWindows(String msg)
    {
        int port = Integer.parseInt(jtf2.getText());
        String text = port + "：" + msg;
        jta.append(text + System.lineSeparator());
        jta.setCaretPosition(jta.getDocument().getLength());
    }


    //    创建一个后台读数据的线程类
    public class RecevierThread extends Thread
    {
        //        内部类可以直接访问外部类的socket属性
        @Override
        public void run() {
//            接受数据数据包数据导入字节数组，再转成字符串
            byte brr[] = new byte[1024];
            while(true){
                DatagramPacket dp = new DatagramPacket(brr,brr.length);
                try {
                    ds.receive(dp);
                    int length = dp.getLength();
                    String msg = new String(brr,0,length);
//                    System.out.println("接受的数据："+msg);
                    msgAddWindows(msg);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }


}
