package Frames.FrameUtils;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ComponentUtils {
    public final static JScrollBar V_JSCROLLBAR = new JScrollBar(JScrollBar.VERTICAL);
    public final static JScrollBar H_JSCROLLBAR = new JScrollBar(JScrollBar.HORIZONTAL);
    
    public static void preShownListenerApply(JTextField textfield, String textToShow)
    {
        FocusListener preShownListener = new FocusListener()
        {
            public void focusGained(FocusEvent e)
            {
                if (textfield.getText().equals(textToShow))
                {
                    textfield.setText("");
                    textfield.setForeground(Color.black);
                }
            }

            public void focusLost(FocusEvent e)
            {
                if (textfield.getText().equals(""))
                {
                    textfield.setForeground(Color.gray);
                    textfield.setText(textToShow);
                }
            }
        };
        textfield.addFocusListener(preShownListener);
    }

    public static void preShownListenerApply(JTextArea textArea, String textToShow)
    {
        FocusListener preShownListener = new FocusListener()
        {
            public void focusGained(FocusEvent e)
            {
                if (textArea.getText().equals(textToShow))
                {
                    textArea.setText("");
                    textArea.setForeground(Color.black);
                }
            }

            public void focusLost(FocusEvent e)
            {
                if (textArea.getText().equals(""))
                {
                    textArea.setForeground(Color.gray);
                    textArea.setText(textToShow);
                }
            }
        };
        textArea.addFocusListener(preShownListener);
    }
}
