package Frames.FrameUtils;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.Cursor;
import java.awt.Desktop;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.font.*;
import java.net.URI;

public class LinkLabel extends JLabel{
    private String text;
    private String url;

    HashMap<TextAttribute, Object> mapClickedUnderline = new HashMap<>();
    HashMap<TextAttribute, Object> mapSpareUnderline = new HashMap<>();
    {
        mapSpareUnderline.put(TextAttribute.FAMILY, "Default");
        mapSpareUnderline.put(TextAttribute.SIZE, 12.0);
        mapSpareUnderline.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
        mapSpareUnderline.put(TextAttribute.SWAP_COLORS, TextAttribute.SWAP_COLORS_ON);
        mapSpareUnderline.put(TextAttribute.FOREGROUND, new Color(0, 176, 255, 125));

        mapClickedUnderline.put(TextAttribute.FAMILY, "Default");
        mapClickedUnderline.put(TextAttribute.SIZE, 12.0);
        mapClickedUnderline.put(TextAttribute.UNDERLINE, TextAttribute.UNDERLINE_ON);
        mapClickedUnderline.put(TextAttribute.SWAP_COLORS, TextAttribute.SWAP_COLORS_ON);
        mapClickedUnderline.put(TextAttribute.FOREGROUND, new Color(0, 176, 255, 125));
    }
    private Font fontSpareUnderline = new Font(mapSpareUnderline);
    private Font fontClickedUnderline = new Font(mapClickedUnderline);
    private URI genURI;
    private boolean isSupported;
    private void LinkMouseAdapterApply(LinkLabel linkLabel)
    {
        MouseAdapter LinkMouseAdapter = new MouseAdapter()
        {
            public void mouseEntered(MouseEvent e)
            {
                if (isSupported)
                    setCursor(new Cursor(Cursor.HAND_CURSOR));
            }

            public void mouseClicked(MouseEvent e)
            {
                try {
                    genURI = new URI(LinkLabel.this.url);
                    Desktop.getDesktop().browse(genURI);
                } catch (Exception e2) {}
                linkLabel.setFont(fontClickedUnderline);
            }
        };
        linkLabel.addMouseListener(LinkMouseAdapter);
    }

    public LinkLabel(String text, String url)
    {
        this.text = text;
        this.url = url;
        try {
            this.isSupported = Desktop.isDesktopSupported()
                            && Desktop.getDesktop().isSupported(Desktop.Action.BROWSE);
        } catch (Exception e1) {
            this.isSupported = false;
        }
        super.setText(this.text);
        super.setFont(fontSpareUnderline);
        LinkMouseAdapterApply(this);
    }

}
