import javax.swing.JFrame;

class GraphicsTest {
    public static void main(String[] args) {
        DemoGraphics dg = new DemoGraphics();

        dg.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        dg.setSize(300, 250);

        dg.init();

        dg.setVisible(true);
    }
}