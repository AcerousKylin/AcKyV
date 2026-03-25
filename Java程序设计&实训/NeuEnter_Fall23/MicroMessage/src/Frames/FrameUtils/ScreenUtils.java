package Frames.FrameUtils;

import java.awt.Dimension;
import java.awt.Toolkit;

public class ScreenUtils {
    public static Dimension getScreenSize()
    {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        return toolkit.getScreenSize();
    }
}
